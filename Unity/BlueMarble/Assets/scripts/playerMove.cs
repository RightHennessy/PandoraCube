using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class playerMove : MonoBehaviour
{
    [SerializeField] Transform[] groundPos;
    [SerializeField] float speed = 5f;
    int now = 0;
    int target = 0;
    int move =0;
    int bringCnt;
    int compareCnt;
    int laps = 0;
    

    public int srcStart;
    public int srcLaps;
    
    // Start is called before the first frame update
    void Start()
    {
        transform.position = groundPos[now].transform.position;
        bringCnt = 0;
        compareCnt = 1;
    }

    // Update is called once per frame
    void Update()   
    {

        if (move == 0)
        {
            move = GameObject.Find("btnDice").GetComponent<dice>().srcDice;
            target = now + move;
        }
        else if (move > 0)
            MovePath();
        else
        {
            Debug.Log("실행중지");
            bringCnt = GameObject.Find("btnDice").GetComponent<dice>().srcCnt;
            if(bringCnt != compareCnt)
            {
                compareCnt=bringCnt;
                move = 0;
            }
        }
        
        Vector2 dir = groundPos[(now)%26].transform.position - transform.position; 
        transform.Translate(dir.normalized * speed * Time.deltaTime, Space.World);
        
    }

    public void MovePath()
    {

        transform.position = Vector2.MoveTowards
            (transform.position, groundPos[(now)%26].transform.position, speed * Time.deltaTime);

        if (now < target)
            now++;
        else if (now == target)
        {
            srcStart = now%26;
            move = -1;

        }

        if (now % 26 == 0)
        {
            laps++;
            srcLaps = laps;
        }

        return;
       

    }
    
}
