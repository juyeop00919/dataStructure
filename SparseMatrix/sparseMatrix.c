#include <stdio.h>
#include <stdlib.h>

#include "sparseMatrix.h"

int compareElements(const void* a, const void* b) {
	elementArrayList* elemA = (elementArrayList*)a;
	elementArrayList* elemB = (elementArrayList*)b;

	if (elemA->row != elemB->row) {
		return elemA->row - elemB->row;
	}
	return elemA->col - elemB->col;
}

void sortSparseMatrix(sparseMatrix* sm) {
	qsort(sm->data, sm->size, sizeof(elementArrayList), compareElements);
}

sparseMatrix* createSparseMatrix(int row, int col) {
	return createArrayList(row * col);
}

int addElementSparseMatrix(sparseMatrix* sm, int row, int col, int value) {
	int size;
	size = sizeArrayList(sm);

	insertArrayList(sm, size,
		(elementArrayList) {
		row, col, value
	});
}

int printSparseMatrix(sparseMatrix* sm) {
	printf("Matrix OUT : \n");

	printArrayList(sm);
}

sparseMatrix* addSparseMatrix(sparseMatrix* sm1, sparseMatrix* sm2) {

	sortSparseMatrix(sm1);
	sortSparseMatrix(sm2);
	sparseMatrix* smResult = createArrayList(100);

	int i = 0, j = 0;

	while (i < sizeArrayList(sm1) && j < sizeArrayList(sm2)) {
		elementArrayList nonZeroOfSM1
			= getItemArrayList(sm1, i);
		elementArrayList nonZeroOfSM2
			= getItemArrayList(sm2, j);
		if (nonZeroOfSM1.row == nonZeroOfSM2.row &&
			nonZeroOfSM1.col == nonZeroOfSM2.col) {
			insertArrayList(smResult, sizeArrayList(smResult), (elementArrayList) {
				nonZeroOfSM1.row,
					nonZeroOfSM1.col,
					nonZeroOfSM1.value + nonZeroOfSM2.value
			});
			i++;
			j++;
		}
		else if (nonZeroOfSM1.row < nonZeroOfSM2.row ||
				 (nonZeroOfSM1.row == nonZeroOfSM2.row &&
				  nonZeroOfSM1.col < nonZeroOfSM2.col)) {
			insertArrayList(smResult, sizeArrayList(smResult),
				nonZeroOfSM1);
			i++;
		}
		else {
			insertArrayList(smResult, sizeArrayList(smResult),
				nonZeroOfSM2);
			j++;
		}
	}
	while (i < sizeArrayList(sm1)) {
		insertArrayList(smResult, sizeArrayList(smResult), getItemArrayList(sm1, i++));
	}


	while (j < sizeArrayList(sm2)) {
		insertArrayList(smResult, sizeArrayList(smResult), getItemArrayList(sm2, j++));
	}
	return smResult;
}

arrayList* transposeArray(arrayList* sm, int* moveCount) {
	int tSize = sm->size;
	int numCols = 10;
	*moveCount = 0;

	elementArrayList** tArray = (elementArrayList**)malloc(sizeof(elementArrayList*) * tSize);

	for (int i = 0; i < tSize; i++) {
		tArray[i] = (elementArrayList*)malloc(sizeof(elementArrayList));
		*(tArray[i]) = sm->data[i];
	}


	int rowTerms[10] = { 0 }, startingPos[10] = { 0 };
	for (int i = 0; i < tSize; i++) rowTerms[tArray[i]->col]++;
	startingPos[0] = 0;
	for (int i = 1; i < 10; i++) {
		startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
	}

	arrayList* result = createArrayList(sm->capacity);

	for (int k = 0; k < tSize; k++) {
		elementArrayList v = { 0, 0, 0 };
		result->data[k] = v;
	}

	for (int i = 0; i < tSize; i++) {
		int col = tArray[i]->col;
		int targetIdx = startingPos[col]++; 

		result->data[targetIdx].row = tArray[i]->col;
		result->data[targetIdx].col = tArray[i]->row;
		result->data[targetIdx].value = tArray[i]->value;

		(*moveCount)++;
	}
	result->size = tSize;

	for (int i = 0; i < tSize; i++) free(tArray[i]);
	free(tArray);

	return result;
}