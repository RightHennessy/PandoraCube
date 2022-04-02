using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{
    [SerializeField] GameObject[] starSet;
    [SerializeField] GameObject[] textSet;
    public GameObject btnBuyBuilding;
    public GameObject finishCanvas;

    int i;
    int now;
    int next;
    int nowMoney;
    public Text myMoneyNow;
    int bringLaps = 0;
    int checkLaps = 0;

    // Start is called before the first frame update
    void Start()
    {
        now = 0;
        next = 0;
        nowMoney = 500000;
        myMoneyNow.text = "500000";
    }

    // Update is called once per frame
    void Update()
    {
        next = GameObject.Find("player").GetComponent<playerMove>().srcStart;
        if (next != now)
        {
            now = next;
            getBuilding();
        }


        // 게임 종료 시점 결정
        bringLaps = GameObject.Find("player").GetComponent<playerMove>().srcLaps;
        if (bringLaps > 5)
            finishCanvas.SetActive(true);

        if (checkLaps < bringLaps && bringLaps <= 5)
        {
            nowMoney += 200000;
            myMoneyNow.text = nowMoney.ToString();
            checkLaps++;
        }

    }


    public void OnClickBuyBuildingButton()
    {
        canBuyBuilding();
    }

    public void getBuilding()
    {

        

        if (now == 0 || now == 8 || now == 13 || now == 21)
        {
            btnBuyBuilding.SetActive(false);
            return;
        }


        // 구매가능한 경우
        if (starSet[now].activeSelf == false && nowMoney >= 50000)
        {
            btnBuyBuilding.SetActive(true);
            
        }
        // 이미 구매한 경우
        else
        {
            btnBuyBuilding.SetActive(false);
            return;
        }

    }

    public void canBuyBuilding()
    {
        starSet[now].SetActive(true);
        textSet[now].SetActive(false);
        nowMoney -= 50000;
        myMoneyNow.text = nowMoney.ToString();
        btnBuyBuilding.SetActive(false);
    }



}
