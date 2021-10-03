#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node *prev, *next;
	int data;
}Node;

Node *getNode();
void initialize(Node* p, Node* q);
void add(Node *t, int n);
void removenode(Node* h, Node* t, int n);
void removeNode(Node* p);
void print(Node* h, Node *t);
void clearNode(Node* h, Node* t);

int main(void) {
	char ch;
	int n;
	Node *H, *T;

	H = getNode();
	T = getNode();
	initialize(H, T);

	scanf("%c", &ch);

	while (ch != 'p') {
		scanf("%d", &n);
		if (ch == 'a')
			add(T, n);
		else if (ch == 'r')
			removenode(H,T,n);
			
		getchar();
		scanf("%c", &ch);
	}

	print(H, T);
	
	clearNode(H, T);
	 
	return 0;
}

Node *getNode() {
	Node *p;
	p = (Node *)malloc(sizeof(Node));

	p->next = NULL;
	p->prev = NULL;
	p->data = '\0';

	return p;
}

void initialize(Node* p, Node* q) {
	p->next = q;
	q->prev = p;

	return;
}

void add(Node *t, int n) {
	Node* p, * q;

	p = t->prev;
	q = getNode();
	
	initialize(p, q);
	initialize(q, t);
	
	q->data = n;

	return;
}

//  remove �� ���Ұ� �ִ��� Ȯ��
void removenode(Node* h, Node* t, int n) {
	Node* p;
	int flag=0;

	p = h;
	if (h->next == t) {
		printf("���Ḯ��Ʈ�� ����ֽ��ϴ�.\n");
		return;
	}

	while (p->next != t) {
		p = p->next;
		if (p->data == n) {
			flag = 1;
			removeNode(p);
			break;
		}
	}

	if (flag == 0) {
		printf("%d��� ���� �������� �ʾ� ������ �� �����ϴ�.\n", n);
	}

	return;
}

// �ش� ��带 �����ϰ� �޸� ����
void removeNode(Node* p) {
	Node *q;

	q = p->prev;
	q->next = p->next;
	(p->next)->prev = q;

	free(p);

	return;
}

void print(Node* h, Node *t) {
	Node* p;

	p = h;
	if (h->next == t)
		printf("���Ḯ��Ʈ�� ����ֽ��ϴ�.\n");

	while (p->next != t) {
		p = p->next;
		printf(" %d", p->data);
	}

	return;
}

// �����Ҵ� �����ϴ� �Լ�
void clearNode(Node* h, Node* t) {
	Node* p, *q;

	p = h;

	if (h->next == t) {
		free(h);
		free(t);
		return;
	}

	while (p->next != t) {
		q = p;
		p = p->next;
		
		free(q);
	}

	free(t);
	return;
}


