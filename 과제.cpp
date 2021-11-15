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
		cout << "�г��� : " << this->getName() << "\n";
		cout << "���� : " << this->getJob() << "\n";
		cout << "���� : " << this->getLevel() << "\n";
		cout << "ü�� : " << this->getHpNow() << " / " << this->getHpMax() << "\n";
		cout << "�Ŀ� : " << this->getPower() << "\n";
	}
	
	void levelup() {
		int n, lev, pow, ph;

		cout << "������ �󸶳� �ø����? : ";
		cin >> n;
		lev = this->getLevel();
		pow = this->getPower();
		ph = this->getHpMax();
		this->setLevel(lev + n);
		this->setHpMax(ph + (n * 100));
		this->setPower(pow + (n * 10));
		cout << n << "��ŭ ������ �߽��ϴ�.\n";
		cout << "���� ������ " << this->getLevel() << "�Դϴ�.\n";
	}

	void hp_plus() {
		int hp;

		hp = this->getHpNow();
		setHpNow(hp + 20);
		cout << "20��ŭ ȸ���Ͽ� ���� HP�� " << this->getHpNow() << " �Դϴ�.\n";
	}

	void changeJob() {
		int n;

		cout << "����)�ش� ������ �ʱ� �������� ����˴ϴ�.\n";
		cout << "1 - ����\n2 - ������\n3 - �ü�\n4 - ���\n";
		cout << "���Ͻô� ������ �Է��� �ּ��� : ";
		cin >> n;

		if (n == 1) {
			playerSetting("����", this->getName(), 1, 50, 50, 10);
			cout << "����� �����߽��ϴ�\n";
		}
		else if (n == 2) {
			playerSetting("������", this->getName(), 1, 100, 100, 20);
			cout << "������� �����߽��ϴ�.\n";
		}
		else if (n == 3) {
			playerSetting("�ü�", this->getName(), 1, 100, 100, 20);
			cout << "�ü��� �����߽��ϴ�.\n";
		}
		else {
			cout << "������ ����߽��ϴ�.\n";
		}
	}

	void showNowHp() {
		cout << "�������� ���ݹ޾� ü���� 10��ŭ �����߽��ϴ�.\n";
		cout << "���� ü�� : "  << this->getHpNow() << " / " << this->getHpMax() << "\n";
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
		cout << "�������� 10��ŭ�� �������� �־����ϴ�.\n";
		cout << "������ ���� ü�� : " << this->getHpNow() << " / " << this->getHpMax() << "\n";

		return this->getHpNow();
	}
};

int main(void) {

	Player player;
	Monster monster;
	string in;
	int n = 0, hp;

	monster.monsterSetting("����", "����", 1, 500, 500, 10);
	cout << "==============================\n";
	cout << "[��������]\n";
	cout << "������ ȯ���մϴ�. �⺻ ������ �Է����ּ��� :)\n";
	cout << "�г����� �Է����ּ��� (���� ����) : ";
	cin >> in;
	player.playerSetting("�ʺ���", in, 1, 50, 50, 10);
	cout << "�÷��̾ �����Ǿ����ϴ�. ������ ������ �����ϴ�. \n";
	player.playerInfo();
	cout << "==============================\n";
	cout << "������ ���� ������ ������ �۾��� ������ �� �ֽ��ϴ�.\n";
	cout << "1 - ����\n2 - ü�� 20 ȸ��\n3 - ��������\n4 - ���� ��\n5 - ���� �÷��̾� ���� ���\n6- ����\n";
	cout << "==============================\n";

	while (1) {
		cout << "�����Ͻ� �۾��� �Է����ּ��� : ";
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
		
		//������ ü���� 0�� �Ǵ� ��� 
		if (hp == 0)
			break;

		player.showNowHp();
		cout << "\n";
	}
	cout << "�̿����ּż� �����մϴ�.\n";

	return 0;
}