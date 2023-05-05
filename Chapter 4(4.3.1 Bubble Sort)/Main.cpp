#include <fstream>
#include <iostream>
#include <time.h>

#include "SortTester.h"

using namespace std;

bool singleBubblePass(SortTester &tester, unsigned int size, unsigned int passNum) {
	bool sorted = true;

    if (passNum % 2 == 1) { // odd pass, go from lowest to highest
        for (unsigned int i = 1; i < size; i++) {
            if (tester.compare(i, i - 1) < 0) {
                tester.swap(i, i - 1);
                sorted = false;
            }
        }
    } else { // even pass, go from highest to lowest
        for (unsigned int i = size - 1; i > 0; i--) {
            if (tester.compare(i, i - 1) < 0) {
                tester.swap(i, i - 1);
                sorted = false;
            }
        }
    }
    
	return sorted;
}

int main() {
	unsigned int size = 10;
	SortTester tester = SortTester(size);
	cout<<"Unsorted"<<endl;
	tester.print();
	bool sorted = false;
	unsigned int numPasses = 0;
	while (not sorted) {
		sorted = true;
		numPasses++;
		sorted = singleBubblePass(tester, size, numPasses);
   }
   tester.print();
}
