#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int x;
char character[16];

void addCharacter();
void removeCharacter();
void changeCharacter();
void printCharacter();

void main() {

	char in;
	x = 0;
	
	scanf("%c", &in);
	while (in != 'P') {
		if (in == 'A')
			addCharacter();
		else if (in == 'R')
			removeCharacter();
		else if (in == 'C')
			changeCharacter();

		scanf("%c", &in);
	}
	printCharacter();

	return;
}

void addCharacter() {
	char name;
	int i, flag = 0;

	getchar();
	scanf("%c", &name);

	if (x == 16) {
		printf("캐릭터 슬롯 없음\n");
		return;
	}
		
	for (i = 0; i < x; i++) {
		if (character[i] == name) {
			printf("캐릭터 이미 존재\n");
			flag = -1;
			break;
		}
	}

	if (flag != -1)
		character[x++] = name;

	return;
}

void removeCharacter() {
	char name;
	int i, flag = -1;

	getchar();
	scanf("%c", &name);

	for (i = 0; i < x; i++) {
		if (character[i] == name) {
			flag = i;
			break;
		}
	}

	if (flag == -1) {
		printf("캐릭터 정보 없음\n");
		return;
	}

	if (x - 1 != i) {
		for (i = flag; i < x-1; i++)
			character[i] = character[i + 1];
	}
	character[i] = NULL;

	return;
}

void changeCharacter() {
	char name, command;
	int i, flag = -1;

	getchar();
	scanf("%c %c", &name, &command);

	for (i = 0; i < x; i++) {
		if (character[i] == name) {
			flag = i;
			break;
		}
	}

	// 1. 캐릭터 없음 2. 첫자리 왼쪽 변경 3. 마지막자리 오른쪽 변경 4. 오른캐릭 없는 오른쪽 변경 
	if (flag == -1 || (flag == 0 && command == 'L') || (flag == 15 && command == 'R') || (x-1 == flag)) {
		printf("위치 변경 불가능\n");
		return;
	}

	if (command == 'L') {
		character[flag] = character[flag - 1];
		character[flag - 1] = name;
	}
	else {
		character[flag] = character[flag + 1];
		character[flag + 1] = name;
	}
	
	return;
}
void printCharacter() {
	int i;

	printf("1\n");
	for (i = 0; i < x && i < 4; i++)
		printf("%c ", character[i]);
	printf("\n");
	for (i = 4; i < x && i < 8; i++)
		printf("%c ", character[i]);
	printf("\n2\n");
	for (i = 8; i < x && i < 12; i++)
		printf("%c ", character[i]);
	printf("\n");
	for (i = 12; i < x && i < 16; i++)
		printf("%c ", character[i]);
	printf("\n");

	return;
}