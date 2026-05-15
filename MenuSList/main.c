/* 
1) 연결리스트
- 깃허브에 등록된 연결 리스트 소스 코드와 공지사항의 ADT를 바탕으로, 사용자가 메뉴를 통해 정수 목록을 자유롭게 추가, 삭제, 검색할 수 있는 프로그램을 작성하시오.메뉴는 다음과 같다.
1. 맨 앞에 추가 : 정수를 입력받아 리스트의 가장 앞에 삽입
2. 맨 뒤에 추가 : 정수를 입력받아 리스트의 가장 뒤에 삽입
3. 특정 위치에 추가 : 위치(index)와 정수를 입력받아 해당 위치에 삽입
4. 특정 위치 삭제 : 위치(index)를 입력받아 해당 노드를 삭제하고 값 출력
5. 전체 목록 출력 : 현재 리스트에 저장된 모든 정수를 순서대로 출력
6. 리스트 크기 확인 : 현재 저장된 노드의 총 개수를 출력
0. 종료 : 모든 메모리를 해제(destroy)하고 프로그램을 종료
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "SList.h"

int main() {
	LinkedList* mylist;
	mylist = createLinkedList();
	int out = 1;

	while (out) {
		int N;
		int num;
		int pos;
		printf("1. Insert at First\n");
		printf("2. Insert at Last\n");
		printf("3. Insert at NUMS\n");
		printf("4. Delete at NUMS\n");
		printf("5. Print Linked List\n");
		printf("6. Check Size\n");
		printf("0. Destroy Memory and exit\n");
		printf("Enter Num : ");
		scanf("%d", &N);

		switch (N) {
		case 1:
			printf("1. Insert at First\n");
			printf("Enter Num : ");
			scanf("%d", & num);
			insertFirstLinkedList(mylist, num);
			break;

		case 2:
			printf("2. Insert at Last\n");
			printf("Enter Num : ");
			scanf("%d", & num);
			insertLastLinkedList(mylist, num);
			break;

		case 3:
			printf("3. Insert at NUMS\n");
			printf("Enter Num, Pos (ex:11 2): ");
			scanf("%d %d", &num, &pos);
			insertAtLinkedList(mylist, num, pos);
			break;

		case 4:
			printf("4. Delete at NUMS\n");
			printf("Enter Pos : ");
			scanf("%d", &pos);
			deleteAtLinkedList(mylist, pos);
			break;

		case 5:
			printf("5. Print Linked List\n");
			printLinkedList(mylist);
			break;

		case 6:
			printf("6. Check Size\n");
			printf("Linked List Size : %d \n", sizeLinkedList(mylist));
			break;

		case 0:
			destroyLinkedList(mylist);
			out = 0;
			break;
		}
		
	}
}
