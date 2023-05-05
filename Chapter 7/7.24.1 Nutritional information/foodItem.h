#ifndef FOODITEMH
#define FOODITEMH

#include <string>

using namespace std;

class FoodItem {
   public:
      FoodItem() {name = "Water";
      fat = 0.0;
      carbs = 0.0;
      protein = 0.0;
      }
   
   FoodItem(string n, double f, double c, double p) {
      name = n;
      fat = f;
      carbs = c;
      protein = p;
   }

      string GetName();

      double GetFat();

      double GetCarbs();

      double GetProtein();

      double GetCalories(double numServings);

      void PrintInfo();

   private:
      string name;
      double fat;
      double carbs;
      double protein;
};

#endif
