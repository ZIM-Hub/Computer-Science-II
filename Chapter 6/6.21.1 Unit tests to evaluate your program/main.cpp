#include <iostream>
using namespace std;

double KiloToPounds(double kilos) {
   return (kilos * 2.204);
}

int main() {
   double kilos;
   double pounds;
   
   cin >> kilos;
   
   pounds = KiloToPounds(kilos);
   cout << pounds << " lbs" << endl;
   
   return 0;
}
