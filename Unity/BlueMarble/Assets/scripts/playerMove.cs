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
    int bringCnt;
    int compareCnt;

    int laps = 0;

    public int srcStart=0;
    
    // Start is called before the first frame update
    void Start()
    {
        transform.position = groundPos[start].transform.position;
        bringCnt = 0;
        compareCnt = 1;
        move = 0;
    }

    // Update is called once per frame
    void Update()
    {
        if (move == 0)
            move = GameObject.Find("btnDice").GetComponent<dice>().srcDice;
        
        if (move > 0)
            MovePath();
        
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

            while (true)
            {
                bringCnt = GameObject.Find("btnDice").GetComponent<dice>().cnt;
                
                if(bringCnt != compareCnt)
                {
                    compareCnt = bringCnt;
                    move=0;
                    break;
                }
            }
        }

        // 여기에 몇바퀴 돌았는지 체크 
        /*if (start + index == groundPos.Length)
            laps++;
        */

        return;
       

    }
    
}
