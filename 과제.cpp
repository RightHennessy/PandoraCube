#include <iostream>
#include <string>
using namespace std;

class GameObject {
private:
	string job, name;
	int level, hp_now, hp_max, power;

public:
	void setJob(string J) {
		job = J;
	}
	string getJob() {
		return job;
	}

	void setName(string N) {
		name = N;
	}
	string getName() {
		return name;
	}

	void setLevel(int L) {
		level = L;
	}
	int getLevel() {
		return level;
	}

	void setHpNow(int H) {
		hp_now = H;
	}
	int getHpNow() {
		return hp_now;
	}

	void setHpMax(int H) {
		hp_max = H;
	}
	int getHpMax() {
		return hp_max;
	}

	void setPower(int P) {
		power = P;
	}
	int getPower() {
		return power;
	}

};

class Player : public GameObject {
public:
	

	void playerSetting(string pJob, string pName, int pLevel, int pHpnow, int pHpmax, int pPower) {
		this->setJob(pJob);
		this->setName(pName);
		this->setLevel(pLevel);
		this->setHpNow(pHpnow);
		this->setHpMax(pHpmax);
		this->setPower(pPower);
	}

	void playerInfo() {
		cout << "닉네임 : " << this->getName() << "\n";
		cout << "직업 : " << this->getJob() << "\n";
		cout << "레벨 : " << this->getLevel() << "\n";
		cout << "체력 : " << this->getHpNow() << " / " << this->getHpMax() << "\n";
		cout << "파워 : " << this->getPower() << "\n";
	}
	
	void levelup() {
		int n, lev, pow, ph;

		cout << "레벨을 얼마나 올릴까요? : ";
		cin >> n;
		lev = this->getLevel();
		pow = this->getPower();
		ph = this->getHpMax();
		this->setLevel(lev + n);
		this->setHpMax(ph + (n * 100));
		this->setPower(pow + (n * 10));
		cout << n << "만큼 레벨업 했습니다.\n";
		cout << "현재 레벨은 " << this->getLevel() << "입니다.\n";
	}

	void hp_plus() {
		int hp;

		hp = this->getHpNow();
		setHpNow(hp + 20);
		cout << "20만큼 회복하여 현재 HP는 " << this->getHpNow() << " 입니다.\n";
	}

	void changeJob() {
		int n;

		cout << "주의)해당 직업의 초기 스택으로 적용됩니다.\n";
		cout << "1 - 전사\n2 - 마법사\n3 - 궁수\n4 - 취소\n";
		cout << "원하시는 직원을 입력해 주세요 : ";
		cin >> n;

		if (n == 1) {
			playerSetting("전사", this->getName(), 1, 50, 50, 10);
			cout << "전사로 전직했습니다\n";
		}
		else if (n == 2) {
			playerSetting("마법사", this->getName(), 1, 100, 100, 20);
			cout << "마법사로 전직했습니다.\n";
		}
		else if (n == 3) {
			playerSetting("궁수", this->getName(), 1, 100, 100, 20);
			cout << "궁수로 전직했습니다.\n";
		}
		else {
			cout << "전직을 취소했습니다.\n";
		}
	}

	void showNowHp() {
		cout << "보스에게 공격받아 체력이 10만큼 감소했습니다.\n";
		cout << "현재 체력 : "  << this->getHpNow() << " / " << this->getHpMax() << "\n";
	}
};

class Monster : public GameObject {
public:

	void monsterSetting(string pJob, string pName, int pLevel, int pHpnow, int pHpmax, int pPower) {
		this->setJob(pJob);
		this->setName(pName);
		this->setLevel(pLevel);
		this->setHpNow(pHpnow);
		this->setHpMax(pHpmax);
		this->setPower(pPower);
	}

	int monsterAttack() {
		int hp;
		hp = this->getHpNow();
		this->setHpNow(hp - 10);
		cout << "보스에게 10만큼의 데미지를 주었습니다.\n";
		cout << "보스의 남은 체력 : " << this->getHpNow() << " / " << this->getHpMax() << "\n";

		return this->getHpNow();
	}
};

int main(void) {

	Player player;
	Monster monster;
	string in;
	int n = 0, hp;

	monster.monsterSetting("보스", "보스", 1, 500, 500, 10);
	cout << "==============================\n";
	cout << "[보스잡자]\n";
	cout << "접속을 환영합니다. 기본 정보를 입력해주세요 :)\n";
	cout << "닉네임을 입력해주세요 (띄어쓰기 금지) : ";
	cin >> in;
	player.playerSetting("초보자", in, 1, 50, 50, 10);
	cout << "플레이어가 생성되었습니다. 정보는 다음과 같습니다. \n";
	player.playerInfo();
	cout << "==============================\n";
	cout << "보스가 죽을 때까지 다음의 작업을 수행할 수 있습니다.\n";
	cout << "1 - 공격\n2 - 체력 20 회복\n3 - 직업설정\n4 - 레벌 업\n5 - 현재 플레이어 정보 출력\n6- 종료\n";
	cout << "==============================\n";

	while (1) {
		cout << "수행하실 작업을 입력해주세요 : ";
		cin >> n;
		if (n == 1)
			hp = monster.monsterAttack();
		else if (n == 2)
			player.hp_plus();
		else if (n == 3)
			player.changeJob();
		else if (n == 4)
			player.levelup();
		else if (n == 5)
			player.playerInfo();
		else
			break;
		
		//보스의 체력이 0이 되는 경우 
		if (hp == 0)
			break;

		player.showNowHp();
		cout << "\n";
	}
	cout << "이용해주셔서 감사합니다.\n";

	return 0;
}