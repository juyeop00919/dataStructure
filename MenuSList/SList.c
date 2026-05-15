#include "SList.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList* createLinkedList() {
	LinkedList* r;
	r = (LinkedList*)malloc(sizeof(LinkedList));
	r->head = (PointType*)NULL;
	r->size = 0;
	return r;
}


LinkedList* insertFirstLinkedList(LinkedList* li, int item) {
	PointType* ptr = (PointType*)malloc(sizeof(PointType));
	ptr->x = item;
	ptr->next = li->head;
	li->head = ptr;
	li->size++;
	return li;
}

LinkedList* insertLastLinkedList(LinkedList* li, int item) {
	PointType* ptr = li->head;
	while (ptr->next != NULL) ptr = ptr->next;
	PointType* nPtr = (PointType*)malloc(sizeof(PointType));
	nPtr->x = item;
	nPtr->next = NULL;
	ptr->next = nPtr;
	li->size++;
	return li;
}


LinkedList* insertAtLinkedList(LinkedList* li, int item, int pos) {
	PointType* ptr = (PointType*)malloc(sizeof(PointType));
	ptr->x = item;

	PointType* pre = li->head;
	if (pos == 0) {
		ptr->next = li->head;
		li->head = ptr;
	}
	else {
		for (int i = 0; i < pos - 1; i++)
		{
			pre = pre->next;
		}
		ptr->next = pre->next;
		pre->next = ptr;
	}
	li->size++;
	return li;
}


LinkedList* deleteAtLinkedList(LinkedList* li, int pos) {
	if (pos > 0 && pos <= li->size) {
		PointType* pre = li->head;
		for (int i = 0; i < pos -1; i++)
		{
			pre = pre->next;
		}
		if (pos == 0) {
			PointType* temp = li->head;
			li->head = temp->next;
			free(temp);
		}
		else {
			PointType* temp = pre->next;
			pre->next = temp->next;
			free(temp);
		}
		li->size--;
	}
	printf("Delete %d Node -> ", pos);
	printLinkedList(li);
	return li;
}

int printLinkedList(LinkedList* li) {
	PointType* cur = li->head;
	printf("Linked List [%d] -> ", li->size);
	for (int i = 0; i < li->size; i++){
		printf("%d ", cur->x);
		cur = cur->next;
	}
	printf("\n");
}

int sizeLinkedList(LinkedList* li) {
	return li->size;
}

int destroyLinkedList(LinkedList* li) {
	PointType* nptr, * mptr;
	for (nptr = li->head; nptr != NULL; nptr=mptr) {
		mptr = nptr->next;
		free(nptr);
	}
	free(li);
	return 1;
}