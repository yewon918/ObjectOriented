/*
 * lab3-linkedlist.c
 *
 *  Created on: Apr 9, 2019
 *      Author: rsyoung
 *  Lab 3: Singly Linked List
 *  Department of Computer Science at Chungbuk National University
 */


#include<stdio.h>
#include<stdlib.h>

 /* �꾩슂�� �ㅻ뜑�뚯씪 異붽� */

typedef struct Node {
	int key;
	struct Node* link;
} listNode;

typedef struct Head {
	struct Node* head;
}headNode;


/* �⑥닔 由ъ뒪�� */
headNode* initialize(headNode* h);
int freeList(headNode* h);

int insertMiddle(headNode* h, int key);
int insertLast(headNode* h, int key);
int insertFirst(headNode* h, int key);
int deleteMiddle(headNode* h, int key);
int deleteLast(headNode* h);
int deleteFirst(headNode* h);
int invertList(headNode* h);
void printList(headNode* h);

int main()
{
	char command;
	int key;
	headNode* headnode = NULL;

	do {
		printf("----------------------------------------------------------------\n");
		printf("                    Lab 2: Singly Linked List                  \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Middle = i           Delete Middle = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch (command) {
		case 'z': case 'Z':
			headnode = initialize(headnode);
			break;
		case 'p': case 'P':
			printList(headnode);
			break;
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);
			insertMiddle(headnode, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteMiddle(headnode, key);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insertLast(headnode, key);
			break;
		case 'e': case 'E':
			deleteLast(headnode);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			insertFirst(headnode, key);
			break;
		case 't': case 'T':
			deleteFirst(headnode);
			break;
		case 'r': case 'R':
			invertList(headnode);
			break;
		case 'q': case 'Q':
			freeList(headnode);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	} while (command != 'q' && command != 'Q');

	return 1;
}
//뭔 소린지 잘 모르겠다
headNode* initialize(headNode* h) {	

	/*headNode가 NULL이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제*/
	if (h != NULL)
		freeList(h);

	/*headNode에 대한 메모리를 할당하여 리턴*/
	headNode* temp = (headNode*)malloc(sizeof(headNode));
	temp->head = NULL;
	return temp;
}

int freeList(headNode* h) {
	/* h와 연결된 listNode 메모리 해제
	 * headNode도 해제되어야 함
	 */
	listNode* p = h->head;

	listNode* prev = NULL;
	while (p != NULL) {
		prev = p;
		p = p->link;
		free(prev);
	}
	free(h);
	return 0;
}


/*리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertMiddle(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key;
	node->link = NULL;

	if (h->head == NULL)
	{
		h->head = node;
		return 0;
	}

	listNode* n = h->head;
	listNode* trail = h->head;

	/*key를 기준으로 삽입할 위치를 찾는다.*/
	while (n != NULL) {
		if (n->key >= key) {
			/*첫 노드 앞쪽에 삽입해야할 경우 인지 검사*/
			if (n == h->head) {
				h->head = node;
				node->link = n;
			}
			else { 
				/*중간이거나 마지막인 경우*/
				node->link = n;
				trail->link = node;
			}
			return 0;
		}

		trail = n;
		n = n->link;
	}

	/*마지막 노드까지 찾지 못한 경우, 마지막에 삽입*/
	trail->link = node;
	return 0;
}

/**
 * list�� key�� ���� �몃뱶�섎굹瑜� 異붽� list에 key에 대한 노드 추가
 */
int insertLast(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key;
	node->link = NULL;

	if (h->head == NULL)
	{
		h->head = node;
		return 0;
	}

	listNode* n = h->head;
	while (n->link != NULL) {
		n = n->link;
	}
	n->link = node;
	return 0;
}

/**
 * list 처음에 key에 대한 노드 하나를 추가
 */
int insertFirst(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key;

	node->link = h->head;
	h->head = node;

	return 0;
}

/**
 * list�먯꽌 key�� ���� �몃뱶 ��젣 list에서 key에 대한 노드 삭제
 */
int deleteMiddle(headNode* h, int key) {

	if (h->head == NULL)
	{
		printf("nothing to delete.\n");
		return 0;
	}

	listNode* n = h->head;
	listNode* trail = NULL;

	/*key를 기준으로 삽입할 위치를 찾는다*/
	while (n != NULL) {
		if (n->key == key) {
			/* 泥� �몃뱶 �욎そ�� �쎌엯�댁빞�� 寃쎌슦 �몄� 寃��� */
			
			if (n == h->head) {
				h->head = n->link;
			}
			else { /*중간이거나 마지막인 경우*/
				trail->link = n->link;
			}
			free(n);
			return 0;
		}

		trail = n;
		n = n->link;
	}

	/*찾을 수 없을 경우*/
	printf("cannot find the node for key = %d\n", key);
	return 0;



	return 0;
}

/**
 * list�� 留덉�留� �몃뱶 ��젣
 */
int deleteLast(headNode* h) {

	if (h->head == NULL)
	{
		printf("nothing to delete.\n");
		return 0;
	}

	listNode* n = h->head;
	listNode* trail = NULL;

	/* �몃뱶媛� �섎굹留� �덈뒗 寃쎌슦, 利� first node == last node��  寃쎌슦 泥섎━ */
	if (n->link == NULL) {
		h->head = NULL;
		free(n);
		return 0;
	}

	/* 留덉�留� �몃뱶源뚯� �대룞 */
	while (n->link != NULL) {
		trail = n;
		n = n->link;
	}

	/* n�� ��젣�섎�濡�, �댁쟾 �몃뱶�� 留곹겕 NULL 泥섎━ */
	trail->link = NULL;
	free(n);

	return 0;
}
/**
 * list�� 泥ル쾲吏� �몃뱶 ��젣
 */
int deleteFirst(headNode* h) {

	if (h->head == NULL)
	{
		printf("nothing to delete.\n");
		return 0;
	}
	listNode* n = h->head;

	h->head = n->link;
	free(n);

	return 0;
}


/**
 * 리스트 링크를 역순으로 배치		//책 182
 */
int invertList(headNode* h) {


	if (h->head == NULL) {
		printf("nothing to invert...\n");
		return 0;
	}
	listNode *n = h->head;
	listNode *trail = NULL;
	listNode *middle = NULL;

	while (n != NULL) {
		trail = middle;
		middle = n;
		n = n->link;
		middle->link = trail;
	}

	h->head = middle;

	return 0;
}


void printList(headNode* h) {
	int i = 0;
	listNode* p;

	printf("\n---PRINT\n");

	if (h == NULL) {
		printf("Nothing to print....\n");
		return;
	}

	p = h->head;

	while (p != NULL) {
		printf("[ [%d]=%d ] ", i, p->key);
		p = p->link;
		i++;
	}

	printf("  items = %d\n", i);
}
