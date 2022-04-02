using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{
    [SerializeField] GameObject[] starSet;
    [SerializeField] GameObject[] textSet;
    int now;
    int next;
    int nowMoney;

    // Start is called before the first frame update
    void Start()
    {
        now = 0;
        next = 0;
        nowMoney = 500000;
    }

    // Update is called once per frame
    void Update()
    {
        next = GameObject.Find("player").GetComponent<playerMove>().srcStart;
        Debug.Log("시작 위치 : " + next);
        if (next != now)
        {
            now = next;
            getBuilding();
        }
    }

    public void OnClickStartButton()
    {
        SceneManager.LoadScene("GameScene");
    }

    public void OnClickExitButton()
    {
        #if UNITY_EDITOR
                UnityEditor.EditorApplication.isPlaying = false;
        #else
                Application.Quit(); // 어플리케이션 종료
        #endif
    }

    public void getBuilding()
    {
        /* 한바퀴 돈 경우 
        if (now == 0)
        {
            nowMoney += 200000;
        }
        */
        if (now == 0 || now == 8 || now == 13 || now == 21)
            return;

        Debug.Log("현재 위치 : " + now);

        // 구매가능한 경우
        if(starSet[now].activeSelf == false)
        {
            starSet[now].SetActive(true);
            textSet[now].SetActive(false);
            nowMoney -= 20000;
         } 
        // 이미 구매한 경우
        else
            return;
        
    }
}
