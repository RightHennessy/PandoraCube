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
        Debug.Log("���� ��ġ : " + next);
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
                Application.Quit(); // ���ø����̼� ����
        #endif
    }

    public void getBuilding()
    {
        /* �ѹ��� �� ��� 
        if (now == 0)
        {
            nowMoney += 200000;
        }
        */
        if (now == 0 || now == 8 || now == 13 || now == 21)
            return;

        Debug.Log("���� ��ġ : " + now);

        // ���Ű����� ���
        if(starSet[now].activeSelf == false)
        {
            starSet[now].SetActive(true);
            textSet[now].SetActive(false);
            nowMoney -= 20000;
         } 
        // �̹� ������ ���
        else
            return;
        
    }
}
