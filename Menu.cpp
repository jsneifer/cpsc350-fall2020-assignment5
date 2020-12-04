#include "Menu.h"
#include <string>
#include <stdlib.h>

Menu::Menu() {
  masterStudent = new BST<Student>();
  masterFaculty = new BST<Faculty>();
}

Menu::~Menu() {
  delete masterStudent;
  delete masterFaculty;
}

void Menu::runOptions() {
  while(true) {
    cout << "\n\nSelect and  option: \n";
    //cout << "1. Print all student info\n";
    //cout << "2. Print all faculty info\n";
    cout << "3. Display a student's information\n";
    cout << "4. Display a faculty's information\n";
    cout << "5. Print a student's advisor\n";
    cout << "6. Print advisee's of a faculty member\n";
    cout << "7. Add a new student\n";
    //cout << "8. Remove a student from the database\n";
    cout << "9. Add a new faculty member\n";
    //cout << "10. Remove a faculty member from the datbase\n";
    cout << "11. Change an advisor of a student\n";
  }
}

void Menu::option3() {
  cout << "\nEnter Student ID number: ";
  int id;
  getline(cin, id);
  if(masterStudent->checkNode(id)){
    cout << masterStudent->Find();
  } else {
    cout << "\nStudent does not exist";
  }
}

void Menu::option4() {
  cout << "\nEnter Faculty ID number: ";
  int id;
  getline(cin, id);
  if(masterFaculty->checkNode(id)){
    cout << masterFaculty->Find();
  } else {
    cout << "\nFaculty does not exist";
  }
}

void Menu::option5() {
  cout << "\nEnter Student ID number: ";
  int id;
  getline(cin, id);
  if(masterStudent->checkNode(id)){
    Student *s = masterStudent->Find(id);
    cout << s->getAdvisor();
  } else {
    cout << "Student does not exist";
  }
}

void Menu::option6() {
  cout << "\nEnter Faculty ID number: ";
  int id;
  getline(cin, id);
  if(masterStudent->checkNode(id)){
    Faculty f = masterStudent->Find();
    f->printAdvisees();
  } else {
    cout << "\nFaculty does not exist";
  }
}

void Menu::option7() {
  int id;
  string n;
  stirng l;
  string m;
  double g;
  int ad;
  cout << "\nEnter student ID: ";
  getInt(cin, id);
  cout << "\nEnter student name: ";
  getline(cin, n);
  cout << "\nEnter student level: ";
  getline(cin, l);
  cout << "\nEnter student major: ";
  getline(cin, m);
  cout << "\nEnter student gpa";
  getDouble(cin, g);
  cout << "\nEnter student advisor";
  getInt(cin, ad);

  Student s = new Student(id, n, l, m, g, ad);
  masterStudent->insert(s);
}

void Menu::option9() {
  int id;
  string n;
  stirng l;
  string d;
  cout << "\nEnter faculty ID: ";
  getInt(cin, id);
  cout << "\nEnter faculty name: ";
  getline(cin, n);
  cout << "\nEnter faculty level: ";
  getline(cin, l);
  cout << "\nEnter faculty department: ";
  getline(cin, d);

  Faculty f = new Faculty(id, n, l, d);
  masterFaculty->insert(f);
}

void Menu::option11() {
  int sid;
  int fid;
  cout << "\nEnter student ID: ";
  getline(cin, sid);
  cout < "\nEnter faculty ID: ";
  getline(cin, fid);

  if(masterStudent->checkNode(sid) && masterFaculty->checkNode(fid)) {
    masterStudent->Find(sid)->setAdvisor(fid);
  } else {
    cout << "\nOne or more IDs are not in the directory";
  }

}
