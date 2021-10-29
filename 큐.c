#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node* prev, * next;
	int data;
}Node;

Node* getNode();
Node *enqueue(Node* t, int n);
Node *dequeue(Node* h, Node *t);
void removeNode(Node* p);
void print(Node* h, Node* t);
void clearNode(Node* h, Node* t);

int main(void) {
	char ch;
	int n;
	Node *front, *rear;

	front = getNode();
	rear = front;

	scanf("%c", &ch);

	while (ch != 'P') {
		if (ch == 'E') {
			scanf("%d", &n);
			rear = enqueue(rear, n);
		}
		else if (ch == 'D')
			front = dequeue(front, rear);

		getchar();
		scanf("%c", &ch);
	}

	print(front, rear);

	clearNode(front, rear);

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

Node* enqueue( Node* t, int n) {
	Node* p;

	if (t->data != '\0') {
		p = getNode();
		p->prev = t;
		t->next = p;
		t = p;
	}
	t->data = n;

	return t;
}

Node* dequeue(Node* h, Node *t) {
	Node* p;
	int n;

	if (h->data == '\0') {
		printf("큐가 비어있습니다.\n");
		return h;
	}

	n = h->data;
	if (h == t)
		h->data = '\0';
	else {
		p = h;
		h = h->next;
		removeNode(p);
	}

	printf("dequeue : %d\n", n);
	return h;
}

// 해당 노드를 삭제하고 메모리 해제
void removeNode(Node* p) {
	Node* q;

	q = p->next;
	q->prev = NULL;
	
	free(p);

	return;
}

void print(Node* h, Node* t) {

	if (h ->data == '\0') {
		printf("큐가 비어있습니다.\n");
		return;
	}

	while (h->next != NULL) {
		printf(" %d", h->data);
		h = h->next;
	}
	printf(" %d", t->data);

	return;
}

// 동적할당 해제하는 함수
void clearNode(Node* h, Node* t) {
	Node* p;

	if (h == t) {
		free(h);
		return;
	}

	while (h->next != t) {
		p = h;
		h = h->next;

		free(p);
	}

	free(t);
	return;
}