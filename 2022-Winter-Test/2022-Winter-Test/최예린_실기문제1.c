#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printStringNumber(char str[]);
void printNumber(char str[]);

void main() {

	int n, i;
	char str[30];

	scanf("%d", &n);
	getchar();

	for (i = 0; i < n; i++) {
		gets(str);
		if (str[0] >= 'a' && str[0] <= 'z') {
			printNumber(str);
		}
		else {
			printStringNumber(str);
		}
	}

	return;
}

void printNumber(char str[]) {
	int i;

	for (i = 0; i < strlen(str); i++) {
		if (str[i] == 'z') {
			printf("0");
			i += 3;
		}
		else if (str[i] == 'o') {
			printf("1");
			i += 3;
		}
		else if (str[i] == 't') {
			if (str[i+1] == 'w') {
				printf("2");
				i += 3;
			}
			else {
				printf("3");
				i += 5;
			}
		}
		else if (str[i] == 'f') {
			if (str[i+1] == 'o') {
				printf("4");
				i += 4;
			}
			else {
				printf("5");
				i += 4;
			}
		}
		else if (str[i] == 's') {
			if (str[i+1] == 'i') {
				printf("6");
				i += 3;
			}
			else {
				printf("7");
				i += 5;
			}
		}
		else if (str[i] == 'e') {
			printf("8");
			i += 5;
		}
		else if (str[i] == 'n') {
			printf("9");
			i += 4;
		}
	}
	printf("\n");

	return;
}

void printStringNumber(char str[]) {
	int i ;

	for (i = 0; i < strlen(str); i++) {
		if (str[i] == '0')
			printf("zero ");
		else if (str[i] == '1')
			printf("one ");
		else if (str[i] == '2')
			printf("two ");
		else if (str[i] == '3')
			printf("three ");
		else if (str[i] == '4')
			printf("four ");
		else if (str[i] == '5')
			printf("five ");
		else if (str[i] == '6')
			printf("six ");
		else if (str[i] == '7')
			printf("seven ");
		else if (str[i] == '8')
			printf("eight ");
		else if (str[i] == '9')
			printf("nine ");
	}
	printf("\n");

	return;
}