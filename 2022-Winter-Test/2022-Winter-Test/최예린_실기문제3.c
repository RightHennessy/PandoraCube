#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;

typedef struct station {
	char name;
	char presence;
	int platform, toilet;
}station;

void getResult(station st[]);

void main() {
	int i;
	station st[10];	

	scanf("%d", &n);
	
	
	for (i = 0; i < n; i++) {
		getchar();
		scanf("%c %c", &st[i].name, &st[i].presence);
		if (st[i].presence == 'o')
			scanf("%d %d", &st[i].platform, &st[i].toilet);
	}

	getResult(st);
	
	return;
}	

void getResult(station st[]) {
	int i, pin, flag = -1, dif;
	char now, direc[5];

	getchar();
	scanf("%c %s", &now, &direc);

	if (strcmp(direc, "up") == 0) {
		for (i = n - 1; i >= 0; i--) {
			if (st[i].name == now) {
				pin = i;
				break;
			}
		}
		for (i = pin; i >= 0; i--) {
			if (st[i].presence == 'o') {
				flag = i;
				break;
			}
		}
	}
	else {
		for (i = 0; i < n; i++) {
			if (st[i].name == now) {
				pin = i;
				break;
			}
		}

		for (i = pin; i < n; i++) {
			if (st[i].presence == 'o') {
				flag = i;
				break;
			}
		}
	}

	if (flag == -1) {
		printf("근처에 화장실이 없습니다.\n");
		return;
	}

	if (st[flag].platform * st[flag].toilet < 0) {
		if(st[flag].platform < st[flag].toilet)
			dif = st[flag].toilet - st[flag].platform - 1;
		else
			dif = st[flag].toilet - st[flag].platform + 1;
	}
	else
		dif = st[flag].toilet - st[flag].platform;

	if (dif < 0)
		printf("%c역에서 내려서 %d층 내려가십시오", st[flag].name, -1*dif);
	else
		printf("%c역에서 내려서 %d층 올라가십시오", st[flag].name, dif);

	return;
}
