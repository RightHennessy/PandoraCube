using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class playerMove : MonoBehaviour
{
    [SerializeField] Transform[] groundPos;
    [SerializeField] float speed = 20f;
    int start = 7;
    int index = 0;
    int move = 6;
    int laps = 0;
    int cnt = 0;
    float n = (float)0.1;

    // Start is called before the first frame update
    void Start()
    {
        transform.position = groundPos[start].transform.position;
    }

    // Update is called once per frame
    void Update()
    {
        
        MovePath();
        Vector2 dir = groundPos[start + index].transform.position - transform.position; 
        transform.Translate(dir.normalized * speed * Time.deltaTime * n, Space.World);

    }

    public void MovePath()
    {

        transform.position = Vector2.MoveTowards
            (transform.position, groundPos[start + index].transform.position, speed * Time.deltaTime);

        if (index < move)
            index++;
        
        
        if (start + index == groundPos.Length)
            laps++;

    }
}
