#include <iostream>
using namespace std;

class Student {
  public:
    Student();
    Student(int id, string n, string l, string m, double g, int ad);
    Student(string n, string l, string m, double g, int ad);
    ~Student();

    //functions to get all variables
    int getID();
    string getName();
    string getLevel();
    string getMajor();
    double getGPA();
    int getAdvisor();
    string getStudentInfo();

    //functions to set all the variables
    void setID(int id);
    void setName(string n);
    void setLevel(string l);
    void setMajor(string m);
    void setGPA(double g);
    void setAdvisor(int ad);


    //Overloaded equality operators
    bool operator<(Student s2);
    bool operator>(Student s2);
    bool operator==(Student s2);
    bool operator!=(Student s2);
    friend ostream& operator<<(ostream& os, Student *s);
    bool equalTo(Student s2); //checks if students are equal
    bool lessThan(Student s2); //Checks if student is less than student 2
    bool greaterThan(Student s2); // Checks if student is greater than
    bool notEqual(Student s2); //Returns true if not equal to eachother

  private:
    unsigned int sID;
    string name;
    string level;
    string major;
    double gpa;
    unsigned int advisor;

};
