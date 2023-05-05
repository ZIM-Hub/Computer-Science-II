#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Add all occurences of goal value
int CheckSingles(vector<int>& diceValues, int goal) {
   int score = 0;
   for(int i = 0; i < diceValues.size(); ++i){
      if(diceValues.at(i) == goal){
         score += goal;
      }
   }
   return score;
}

// Check for three of a kind (score = 30)
int CheckThreeOfKind(vector<int>& diceValues) {
   int score = 0;
   for (int i = 0; i < 3; ++i){
      if(diceValues.at(i) == diceValues.at(i + 1) && diceValues.at(i) == diceValues.at(i + 2)){
         score = 30;
         break;
      }
   }
   return score;
}


// Check for four of a kind (score = 40)
int CheckFourOfKind(vector<int>& diceValues) {
   int score = 0;
    for (int i = 0; i < 2; ++i) {
        if (diceValues.at(i) == diceValues.at(i + 1) && diceValues.at(i) == diceValues.at(i + 2) && diceValues.at(i) == diceValues.at(i + 3)) {
            score = 40;
            break;
        }
    }
    return score;
}

// Check for five of a kind (score = 50)
int CheckFiveOfKind(vector<int>& diceValues) {
   int score = 0;
   if(diceValues.at(0) == diceValues.at(4)){
      score = 50;
   }
   return score;
}

// Check for full house (score = 35)
int CheckFullHouse(vector<int>& diceValues) {
   int score = 0;
    if ((diceValues.at(0) == diceValues.at(1) && diceValues.at(2) == diceValues.at(4))
            || (diceValues.at(0) == diceValues.at(2) && diceValues.at(3) == diceValues.at(4))) {
        score = 35;
    }
    return score;
}

// Check for straight (score = 45)
int CheckStraight(vector<int>& diceValues) {
   int score = 0;
    if ((diceValues.at(0) == 1 && diceValues.at(1) == 2 && diceValues.at(2) == 3 && diceValues.at(3) == 4 && diceValues.at(4) == 5)
            || (diceValues.at(0) == 2 && diceValues.at(1) == 3 && diceValues.at(2) == 4 && diceValues.at(3) == 5 && diceValues.at(4) == 6)) {
        score = 45;
    }
    return score;
}

// Find high score
int FindHighScore(vector<int>& diceValues) {
   int highScore = 0;
   int score;
   
   for(int i = 1; i <= 6; ++i){
      score = CheckSingles(diceValues, i);
      if(score > highScore){
         highScore = score;
      }
   }
   
   score = CheckThreeOfKind(diceValues);
   if(score > highScore){
      highScore = score;
   }
   
   score = CheckFourOfKind(diceValues);
   if(score > highScore){
      highScore = score;
   }
   
   score = CheckFiveOfKind(diceValues);
   if(score > highScore){
      highScore = score;
   }
   
   score = CheckFullHouse(diceValues);
   if(score > highScore){
      highScore = score;
   }
   
   score = CheckStraight(diceValues);
   if(score > highScore){
      highScore = score;
   }
   
   return highScore;
}

int main() {
   vector<int> diceValues(5);
   int highScore = 0;

   // Fill array with five values from input
   for(int i = 0; i < 5; ++i) {
      cin >> diceValues.at(i);
   }

   // Place values in ascending order
   sort(diceValues.begin(), diceValues.end());

   // Find high score and output
   highScore = FindHighScore(diceValues);
   cout << "High score: " << highScore << endl;

   return 0;
}
