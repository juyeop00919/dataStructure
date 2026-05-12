#pragma once

#include <stdio.h>
#include <stdlib.h>


typedef struct pointType {
	int x;
	int y;
	struct pointType* next;
} PointType;



typedef struct linkedList {
	struct pointType* head;
	int size;
} LinkedList;
// typedef 가 없으면 struct linkedList 이런식으로 써야하지만 typedef가 있어서 바로 사용가능

LinkedList* createLinkedList();
int destroyLinkedList(LinkedList* li);