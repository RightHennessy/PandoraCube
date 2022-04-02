using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class playerMove : MonoBehaviour
{
    [SerializeField] Transform[] groundPos;
    [SerializeField] float speed = 20f;
    int start = 0;
    int index = 0;
    int move;
    int laps = 0;
    public int srcStart=0;
    
    // Start is called before the first frame update
    void Start()
    {
        transform.position = groundPos[start].transform.position;
    }

    // Update is called once per frame
    void Update()
    {
        if (move == 0)
            move = GameObject.Find("btnDice").GetComponent<dice>().srcDice;
        else if (move > 0)
            MovePath();
        else if (move < 0)
            move--;
        
        Vector2 dir = groundPos[(start + index)%26].transform.position - transform.position; 
        transform.Translate(dir.normalized * speed * Time.deltaTime, Space.World);
        
    }

    public void MovePath()
    {
        int check = move;

        transform.position = Vector2.MoveTowards
            (transform.position, groundPos[(start + index)%26].transform.position, speed * Time.deltaTime);

        if (index < move)
            index++;
        else if (index == move)
        {
            start += move;
            start %= 26;
            srcStart = start;
            move = -1;
            index = 0;

            while (check == move)
            {
                move = GameObject.Find("btnDice").GetComponent<dice>().srcDice;
                StartCoroutine(Stop());
            }

        }


        if (start + index == groundPos.Length)
            laps++;

    }
    
    IEnumerator Stop()
    {
         yield return null;
    }
    
}
