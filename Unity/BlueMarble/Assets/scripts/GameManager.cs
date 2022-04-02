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
    int laps = 0;

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
        Debug.Log("시작 위치 : " + next);
        if (next != now)
        {
            now = next;
            getBuilding();
        }

        // 게임 종료 시점 결정
        if (laps > 5)
            finishCanvas.SetActive(true);

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

    public void OnClickBuyBuildingButton()
    {
        canBuyBuilding();
    }

    public void getBuilding()
    {

        if (now == 0)
        {
            nowMoney += 200000;
        }

        if (now == 0 || now == 8 || now == 13 || now == 21)
        {
            btnBuyBuilding.SetActive(false);
            return;
        }


        // 구매가능한 경우
        if (starSet[now].activeSelf == false)
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
        nowMoney -= 20000;
        myMoneyNow.text = nowMoney.ToString();
        btnBuyBuilding.SetActive(false);
    }



}
