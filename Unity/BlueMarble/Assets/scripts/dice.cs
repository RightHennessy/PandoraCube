using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;


public class dice : MonoBehaviour
{
    public GameObject diceImg;
    public GameObject btnRoll;
    Sprite[] sprites;
    int isDice = 0;
    int index;
    public int srcDice;
    public int cnt;

    // Start is called before the first frame update
    void Start()
    {
        sprites = Resources.LoadAll<Sprite>("diceImage");
        cnt = 0;
    }

    // Update is called once per frame
    void Update()
    {
        if (isDice == 1)
        {
            StartCoroutine(Dice());
            isDice = 0;
        }
    }

    public void OnClickDiceButton()
    {
        isDice = 1;
        cnt++;
    }

    IEnumerator Dice()
    {
        int diceNum = Random.Range(0,6);
        btnRoll.GetComponent<Button>().interactable = false;


        for (double f = 2.5f; f>=0; f -= 0.1)
        {
            index = Random.Range(0,6);
            diceImg.GetComponent<Image>().sprite = sprites[index];

            yield return new WaitForSeconds(.1f);
        }

        diceImg.GetComponent<Image>().sprite = sprites[diceNum];
        btnRoll.GetComponent<Button>().interactable = true;

        srcDice = diceNum +1;
    }
    
}
