#include <fstream>
#include <iostream>
#include <time.h>

using namespace std;

typedef unsigned int uint;

uint updatePopulation(uint currentPopulation) {
	uint numBirths = .0185*(currentPopulation);
	uint numDeaths = .0008*(currentPopulation);
	return currentPopulation + numBirths - numDeaths;
}

uint howManyGenerations(uint startAmount, uint finalAmount) {
///
   if(startAmount >= finalAmount){
      return 0;
   }
   else{
 return 1 + howManyGenerations(updatePopulation(startAmount), finalAmount);
 }
}

int main() {

	uint finalAmount = 1000000;
	uint startAmount = 100;
	if (howManyGenerations(startAmount, finalAmount) == 537) {
		cout<<"PASSED start=100, final=1000000"<<endl;
	}
	return 0;
}
