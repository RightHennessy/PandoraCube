#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node* prev, * next;
	int data;
}Node;

Node* getNode();
Node *push(Node* t, int n);
Node *pop(Node* t);
void removeNode(Node* p);
void print(Node *t);
void clearNode(Node* t);

int main(void) {
	char ch;
	int n;
	Node* top;

	top = getNode();

	scanf("%c", &ch);

	while (ch != 'P') {
		if (ch == 'A') {
			scanf("%d", &n);
			top = push(top, n);
		}
		else if (ch == 'B')
			top = pop(top);

		getchar();
		scanf("%c", &ch);
	}

	print(top);

	clearNode(top);

	return 0;
}

Node* getNode() {
	Node* p;
	p = (Node*)malloc(sizeof(Node));

	p->next = NULL;
	p->prev = NULL;
	p->data = '\0';

	return p;
}

Node *push(Node* t, int n) {
	Node* p;

	if (t->data != '\0') {
		p = getNode();
		t->next = p;
		p->prev = t;
		t = p;
	}
	t->data = n;

	return t;
}


Node *pop(Node* t) {
	Node* p;
	
	if (t->data == '\0') {
		printf("스택이 비어 있습니다.\n");
		return t;
	}

	printf("pop : %d\n", t->data);
	
	if (t->prev != NULL) {
		p = t;
		t = t->prev;
		removeNode(p);
	}
	else 
		t->data = '\0';
	

	return t;
}

// 해당 노드를 삭제하고 메모리 해제
void removeNode(Node* p) {
	Node* q;

	q = p->prev;
	q->next = NULL;

	free(p);

	return;
}

void print(Node *t) {
	Node* p;

	p = t;
	if (p->data == '\0') {
		printf("스택이 비어 있습니다.\n");
		return;
	}

	while (p->prev != NULL) {
		printf(" %d", p->data);
		p = p->prev;		
	}
	printf(" %d", p->data);

	return;
}

// 동적할당 해제하는 함수
void clearNode(Node* t) {
	Node* p;

	if (t-> data == '\0') {
		free(t);
		return;
	}

	while (t->prev != NULL) {
		p = t;
		t = t->prev;
		t->next = NULL;

		free(p);
	}

	free(t);
	return;
}