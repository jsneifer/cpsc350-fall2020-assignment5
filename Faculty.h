#include <iostream>
using namespace std;

#include "DoublyLinkedList.cpp"
#include "Student.cpp"
using namespace std;

class Faculty {
  public:
    Faculty();
    Faculty(int id, string n, string l, string d);
    ~Faculty();

    string getFacultyInfo();
    int getID();
    string getName();
    string getLevel();
    string getDepartment();

    void setID(int id);
    void setName(string n);
    void setLevel(string l);
    void setDepartment(string d);

    void addStudent(Student s);
    void removeStudent(Student s);
    void removeStudent(int id); //Remove student based on id
    void printAdvisees(); //Loops through the whole list and prints each student's info out

    //Overloaded equality operators
    bool operator<(Faculty f2);
    bool operator>(Faculty f2);
    bool operator==(Faculty f2);
    bool operator!=(Faculty f2);
    friend ostream& operator<<(ostream& os, Faculty f);
    bool equalTo(Faculty f2); //checks if students are equal
    bool lessThan(Faculty f2); //Checks if student is less than student 2
    bool greaterThan(Faculty f2); // Checks if student is greater than
    bool notEqual(Faculty f2);

  private:
    unsigned int fID;
    string name;
    string level;
    string department;

    DoublyLinkedList<Student> *adviseeList;
};
