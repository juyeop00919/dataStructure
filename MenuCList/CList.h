#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct pointType {
	int x;
	struct pointType* prev;
	struct pointType* next;
}PointType;

typedef struct cLinkedList {
	PointType* tail;
	int size;
}CLinkedList;

extern CLinkedList* createLinkedList();

//1. 맨 앞에 추가 : 정수를 입력받아 리스트의 가장 앞에 삽입
extern CLinkedList* insertFirstLinkedList(CLinkedList* li, int item);

//2. 맨 뒤에 추가 : 정수를 입력받아 리스트의 가장 뒤에 삽입
extern CLinkedList* insertLastLinkedList(CLinkedList* li, int item);

//3. 특정 위치에 추가 : 위치(index)와 정수를 입력받아 해당 위치에 삽입
extern CLinkedList* insertAtLinkedList(CLinkedList* li, int item, int pos);

//4. 특정 위치 삭제 : 위치(index)를 입력받아 해당 노드를 삭제하고 값 출력
extern CLinkedList* deleteAtLinkedList(CLinkedList* li, int pos);

//5. 전체 목록 출력 : 현재 리스트에 저장된 모든 정수를 순서대로 출력
extern void printLinkedList(CLinkedList* li);

//6. 리스트 크기 확인 : 현재 저장된 노드의 총 개수를 출력
extern int sizeLinkedList(CLinkedList* li);

//0. 종료 : 모든 메모리를 해제(destroy)하고 프로그램을 종료
extern int destroyLinkedList(CLinkedList* li);