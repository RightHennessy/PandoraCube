#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<int, int> world;
unordered_map<int, int> forum;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

void insertList(int n, int m);

int main(void) {
	int N, i, j, in, flag, find;
	

	cin >> N;

	forum.insert(pair<int, int>(1, 1));
	insertList(1,2);

	for (i = 0; i < N; i++) {

		flag = 0;
		cin >> in;
		find = in;

		for (j = 0; j < 3 && flag >= 0 && find < 100000000; j++) {
			// �������� X
			if (world.find(find) == world.end()) {
				if (flag == 1)
					cout << "��� " << find << "�� �ҷ���." << endl;
				forum.insert(pair<int, int>(find, find));
				insertList(find, find);
				flag = -1;
			}
			// �������� O ȸ�� X
			else if (forum.find(find) == forum.end()) {
				if(flag == 0)
					cout << "�̹� �����ϰ� �ִ� ����." << endl;
				flag = 1;
				find = (world.find(find)->first + world.find(find)->second);
			}
			// �������� O ȸ�� O
			else {
				if (flag == 0)
					cout << "�̹� �����ϰ� �ִ� ����." << endl;
				flag = 1;
				find *= 2;
			}

		}

		if (flag != -1) {
			cout << "��� ������ ���� ��ã�Ҿ�" << endl;
			forum.insert(pair<int, int>(in, in));
		}

		
	}

	vector<pair<int, int>> v(forum.begin(), forum.end());
	sort(v.begin(), v.end(),compare);
	for (int k = 0; k<N; k++)
		cout << v[k].first <<" ";
	cout << endl;

	return 0;
}

void insertList(int n, int m) {
	int tmp, pin=n;

	world.insert(pair<int, int>(n, pin));
	while (m < 100000000) {
		world.insert(pair<int, int>(m, pin));
		tmp = m;
		m += n;
		n = tmp;
	}

	return;
}
