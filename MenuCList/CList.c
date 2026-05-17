#include "CList.h"

CLinkedList* createLinkedList() {
	CLinkedList* temp;
	temp = (CLinkedList*)malloc(sizeof(CLinkedList));
	temp->tail = NULL;
	temp->size = 0;
	return temp;
}

CLinkedList* insertFirstLinkedList(CLinkedList* li, int item) {
	PointType* nPtr;
	nPtr = (PointType*)malloc(sizeof(PointType));
	nPtr->x = item;
	if (li->size == 0) {
		nPtr->next = nPtr;
		li->tail = nPtr;
	}
	else {
		nPtr->next = li->tail->next;
		li->tail->next = nPtr;
	}
	li->size++;
}

CLinkedList* insertLastLinkedList(CLinkedList* li, int item) {
	insertFirstLinkedList(li, item);
	li->tail = li->tail->next;
}

CLinkedList* insertAtLinkedList(CLinkedList* li, int item, int pos) {
	PointType* ptr = (PointType*)malloc(sizeof(PointType));
	ptr->x = item;

	PointType* pre = li->tail;
	if (pos == 0) {
		insertFirstLinkedList(li, item);
	}
	else if (pos == sizeLinkedList(li)) {
		insertLastLinkedList(li, item);
	}
	else {
		for (int i = 0; i < pos; i++) {
			pre = pre->next;
		}
		ptr->next = pre->next;
		pre->next = ptr;
		li->size++;
	}
}

CLinkedList* deleteAtLinkedList(CLinkedList* li, int pos) {
	int x;
	if (pos >= 0 && pos <= li->size) {
		if (pos == 0) {
			PointType* temp = li->tail->next;
			if (li->tail == temp) li->tail = NULL;
			else li->tail->next = temp->next;
			x = temp->x;
			free(temp);
		}
		else {
			PointType* pre = li->tail;
			for (int i = 0; i < pos;i++) {
				pre = pre->next;
			}
			PointType* temp = pre->next;
			pre->next = temp->next;
			if (temp == li->tail) li->tail = pre;
			x = temp->x;
			free(temp);
		}
		li->size--;
	}
	printf("Delete %d[%d] Node -> ",x, pos);
	printLinkedList(li);
	return li;
}

void printLinkedList(CLinkedList* li) {
	printf("Print CLinkedList :\n");

	if (li->size == 0) return;

	PointType* start = li->tail->next;
	for (int i = 0; i < li->size; i++)
	{
		printf("%d ", start->x);
		start = start->next;
	}
	printf("\n");
}
int sizeLinkedList(CLinkedList* li) {
	return li->size;
}

int destroyLinkedList(CLinkedList* li) {
	PointType* temp;
	temp = li->tail;
	while (li->size != 0) {
		PointType* nPtr = temp->next;
		free(temp);
		temp = nPtr;
		li->size--;
	}
	free(li);
	return 1;
}