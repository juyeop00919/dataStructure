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
		nPtr->prev = nPtr;
		li->tail = nPtr;
	}
	else {
		nPtr->next = li->tail->next;
		nPtr->prev = li->tail;
		li->tail->next->prev = nPtr;
		li->tail->next = nPtr;
	}
	li->size++;
	return li;
}

CLinkedList* insertLastLinkedList(CLinkedList* li, int item) {
	insertFirstLinkedList(li, item);
	li->tail = li->tail->next;
	return li;
}

CLinkedList* insertAtLinkedList(CLinkedList* li, int item, int pos) {
	if (pos == 0) {
		return insertFirstLinkedList(li, item);
	}
	else if (pos == sizeLinkedList(li)) {
		return insertLastLinkedList(li, item);
	}
	else {
		PointType* ptr = (PointType*)malloc(sizeof(PointType));
		ptr->x = item;

		PointType* pre = li->tail;

		for (int i = 0; i < pos; i++) {
			pre = pre->next;
		}

		ptr->next = pre->next;
		ptr->prev = pre;
		pre->next->prev = ptr;
		pre->next = ptr;
		li->size++;

		return li;
	}
}

CLinkedList* deleteAtLinkedList(CLinkedList* li, int pos) {
	if (li->size == 0) return li;

	int x = -1; 
	if (pos >= 0 && pos < li->size) {
		if (li->size == 1) { 
			x = li->tail->x;
			free(li->tail);
			li->tail = NULL;
		}
		else if (pos == 0) {
			PointType* temp = li->tail->next;
			li->tail->next = temp->next;
			temp->next->prev = li->tail;
			x = temp->x;
			free(temp);
		}
		else {
			PointType* pre = li->tail;

			for (int i = 0; i < pos; i++) {
				pre = pre->next;
			}

			PointType* temp = pre->next;
			pre->next = temp->next;
			temp->next->prev = pre;
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