#include <iostream>
#include "BST.cpp"
#include "Student.cpp"

using namespace std;

int main() {

  BST<Student> *masterStudent = new BST<Student>();
  Student* s = new Student("Tommy", "Freshman", "Comp Sci", 3.5, 235);
  cout << s;
  Student* s2 = new Student("Robert", "Senior", "Art History", 4.0, 111);
  //Student* s3 = new Student("Betsy", "Junior", "Business", 3.1, 205);
  masterStudent->insert(*s);
  masterStudent->insert(*s2);
  //masterStudent->insert(*s3);
  //masterStudent->printAscending();

  return 0;
}
