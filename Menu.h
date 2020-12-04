#include <iostream>
#include "BST.cpp"
#include "Student.cpp"
#include "Faculty.cpp"
using namespace std;

class Menu {
  public:

    Menu();
    ~Menu();

    void runOptions();

    void option3();
    void option4();
    void option5();
    void option6();
    void option7();
    void option9();
    void option11();


  private:
    BST<Student>* masterStudent;
    BST<Faculty>* masterFaculty;

}
