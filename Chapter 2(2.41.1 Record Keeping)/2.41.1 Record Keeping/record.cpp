#include "Record.h"

using namespace std;

Record::Record(std::string first, std::string last, int years, int grade , int review) {
	firstName = first;
	lastName = last;
	yearsInService = years;
	incomeGrade = grade;
	reviewPerformance = min(3,review);

}
void Record::print() {
	cout<<"Name: "<<lastName<<", "<<firstName<<", years in service:"<<yearsInService
			<<", grade: "<<incomeGrade<<", last review: ";
	switch (reviewPerformance) {
	case 0: cout<<"Improvement Plan"<<endl; break;
	case 1: cout<<"Below Expectations"<<endl; break;
	case 2: cout<<"Meets Expectations"<<endl; break;
	case 3: cout<<"Outstanding"<<endl; break;
	}
}

int Record::compare(Record::fieldType field, Record* compareRecord) {
   
   int result = 0;
   
   switch(field)
   {
      case firstNameField:
      result = firstName.compare(compareRecord->firstName);
      break;
      case lastNameField:
      result = lastName.compare(compareRecord->lastName);
      break;
      case yearsInServiceField:
      result = yearsInService - compareRecord->yearsInService;
      break;
      case incomeGradeField:
      result = incomeGrade - compareRecord->incomeGrade;
      break;
      case reviewPerformanceField:
      result = reviewPerformance - compareRecord->reviewPerformance;
      break;
      default:
      std::cout << "Error: Invalid fieldType" << std::endl;
      break;
   }
	return result;
}
