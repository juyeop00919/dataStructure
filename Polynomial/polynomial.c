#include "arraylist.h"
#include "polynomial.h"

polynomial* createPolynomial(int capacity) {
	polynomial* po = (polynomial*)createArrayList(capacity);
	return po;
}

polynomial* addItemPolynomial(polynomial* po, elementType item) {
	int i;
	for (i = 0; i < sizeArrayList(po); i++) {
		if (po->data[i].expo > item.expo) {
			break;
		}
	}

	if (i == sizeArrayList(po)) {
		insertArrayList(po, i, item);
	}
	else if (po->data[i].expo == item.expo) {
		po->data[i].coef += item.coef;
	}
	else {
		insertArrayList(po, i, item);
	}
}

polynomial* addPolynomial(polynomial* p1, polynomial* p2) {
    polynomial* r = createPolynomial(100);
    int i = 0, j = 0;

    while (i < sizeArrayList(p1) && j < sizeArrayList(p2)) {
        if (p1->data[i].expo < p2->data[j].expo) {
            insertArrayList(r, sizeArrayList(r), p1->data[i]);
            i++;
        }
        else if (p1->data[i].expo > p2->data[j].expo) {
            insertArrayList(r, sizeArrayList(r), p2->data[j]);
            j++;
        }
        else {
            elementArrayList sumItem;
            sumItem.coef = p1->data[i].coef + p2->data[j].coef;
            sumItem.expo = p1->data[i].expo;

            if (sumItem.coef != 0) { 
                insertArrayList(r, sizeArrayList(r), sumItem);
            }
            i++;
            j++;
        }
    }

    while (i < sizeArrayList(p1)) {
        insertArrayList(r, sizeArrayList(r), p1->data[i]);
        i++;
    }

    while (j < sizeArrayList(p2)) {
        insertArrayList(r, sizeArrayList(r), p2->data[j]);
        j++;
    }

    return r;
}

polynomial* multiplyPolynomial(polynomial* p1, polynomial* p2) {
	int capacity = sizeArrayList(p1) * sizeArrayList(p2);
	if (capacity < 100) capacity = 100; 

	polynomial* r = createPolynomial(capacity);

	for (int i = 0; i < sizeArrayList(p1); i++) {
		for (int j = 0; j < sizeArrayList(p2); j++) {
			elementArrayList item;
			item.coef = p1->data[i].coef * p2->data[j].coef;
			item.expo = p1->data[i].expo + p2->data[j].expo;
			if (item.coef != 0) {
				addItemPolynomial(r, item);
			}
		}
	}
	return r;
}

void printPolynomial(polynomial* po) {
	printf("Polynomial : \n");

	printArrayList(po);
}