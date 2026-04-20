#include <stdio.h>
#include <stdlib.h>

#include "sparseMatrix.h"

int main() {
	//arrayList* al = createArrayList(10);
	//insertArrayList(al, 0, (elementArrayList) { 1, 2, 3 });
	//printArrayList(al);
	//printf("\n");

	sparseMatrix* sm1 = createSparseMatrix(10, 10);
	//addElementSparseMatrix(sm1, 2, 1, 10);
	//addElementSparseMatrix(sm1, 3, 3, 15);
	//addElementSparseMatrix(sm1, 4, 1, 3);
	//printf("sm1 : \n");
	//printSparseMatrix(sm1);
	//printf("\n");

	sparseMatrix* sm2 = createSparseMatrix(10, 10);
	//addElementSparseMatrix(sm2, 2, 1, 10);
	//addElementSparseMatrix(sm2, 3, 4, 15);
	//addElementSparseMatrix(sm2, 4, 1, 3);
	//printf("sm2 : \n");
	//printSparseMatrix(sm2);
	//printf("\n");

	//sparseMatrix* sm3 = addSparseMatrix(sm1, sm2);
	//printf("sm3 : \n");
	//printSparseMatrix(sm3);

	for (int i = 0; i < 20; i++) {
		elementArrayList item = { rand() % 10, rand() % 10, rand() % 100 };
		insertArrayList(sm1, sm1->size, item); 
	}

	printf("sm1 :\n");
	printSparseMatrix(sm1);
	printf("\n");
	int move = 0;
	sparseMatrix* smT = transposeArray(sm1, &move);
	printf("smT :\n");
	printSparseMatrix(smT);
}