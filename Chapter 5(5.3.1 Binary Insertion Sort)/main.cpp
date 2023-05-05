#include <fstream>
#include <iostream>
#include <time.h>

#include "SortTester.h"

using namespace std;

typedef unsigned int uint;

uint findInsertionLocation(SortTester &tester, uint start, uint end, uint index) {
  if (end <= start)
        return start;
    uint mid = (end + start) / 2;

    if (tester.compare(mid, index) == 0) {
        return mid + 1;
    }

    if (tester.compare(mid, index) > 0) {
        return findInsertionLocation(tester, start, mid, index);
    }

    if (tester.compare(mid, index) < 0) {
        return findInsertionLocation(tester, mid + 1, end, index);
    }

    return end;
}

void insertionSort(SortTester &tester, uint size) {
   uint temp;
    for (uint index = 1; index < size; index++) {
        uint start = 0;
        uint end = index;

        uint insertionLoc = findInsertionLocation(tester, start, end, index);

        temp = index;
        while (temp > insertionLoc) {
            tester.swap(temp - 1, temp);
            temp--;
        }
    }
}

int main() {
	uint size = 10;
	SortTester tester = SortTester(size);
	cout<<"Unsorted"<<endl;
	tester.print();
	insertionSort(tester, size);
	if (tester.isSorted()) {
		cout<<"PASSED List Sorted (10 pts)"<<endl;
	}
	else {
		tester.print();
		cout<<"FAILED List not Sorted"<<endl;
	}

	if (tester.areComparesBinary()) {
	   cout<<"PASSED Binary Insertion Sort (15 pts)"<<endl;
	}
	else {
	   cout<<"FAILED Binary Insertion Sort"<<endl;
	}

	if (tester.isSortStable()) {
	   cout<<"PASSED Extra Credit - sort is stable (5pts)"<<endl;
	}
	else {
	   cout<<"Sort is not stable - swap occured among entries with same value"<<endl;
	}
}
