#ifndef FACULTY_CPP
#define FACULTY_CPP

#include "Faculty.h"
#include <string>

Faculty::Faculty() {
  fID = rand() % 999 + 100;
  adviseeList = new DoublyLinkedList<Student>();
}
Faculty::Faculty(int id, string n, string l, string d) {
  fID = id;
  name = n;
  level = l;
  department = d;
  adviseeList = new DoublyLinkedList<Student>();
}

Faculty::~Faculty() {
  delete adviseeList;
}

string Faculty::getFacultyInfo() {
  string info = "";
  info += "Faculty ID: " + to_string(fID);
  info += "\nName: " + name;
  info += "\nLevel: " + level;
  info += "\nDepartment: " + department;
}

int Faculty::getID() {
  return fID;
}
string Faculty::getName() {
  return name;
}
string Faculty::getLevel() {
  return level;
}
string Faculty::getDepartment() {
  return department;
}

void Faculty::setID(int id) {
  fID = id;
}
void Faculty::setName(string n) {
  name = n;
}
void Faculty::setLevel(string l) {
  level = l;
}
void Faculty::setDepartment(string d) {
  department = d;
}

void Faculty::addStudent(Student s) {
  adviseeList->insertBack(s);
}
void Faculty::removeStudent(Student s) {
  adviseeList->removeNode(s);
}
void Faculty::removeStudent(int id) {
  for(int x = 0; x < adviseeList->getSize(); ++x) {
    if(adviseeList->returnAtPos(x)->getID() == id) {
      adviseeList->deletePos(x);
    }
  }
}

bool Faculty::operator<(Faculty f2) {
  return lessThan(f2);
}
bool Faculty::operator>(Faculty f2){
  return greaterThan(f2);
}
bool Faculty::operator==(Faculty f2) {
  return equalTo(f2);
}
bool Faculty::operator!=(Faculty f2) {
  return notEqual(f2);
}
ostream& operator<<(ostream& os, Faculty *f) {
  os << f->getFacultyInfo();
  return os;
}

bool Faculty::equalTo(Faculty f2) {
  if(fID == f2.getID()) {
    return true;
  } else {
    return false;
  }
}
bool Faculty::notEqual(Faculty f2) {
  if(fID != f2.getID()) {
    return true;
  } else {
    return false;
  }
}
bool Faculty::lessThan(Faculty f2) {
  if (fID < f2.getID()) {
    return true;
  } else {
    return false;
  }
}
bool Faculty::greaterThan(Faculty f2) {
  if(fID > f2.getID()) {
    return true;
  } else {
    return false;
  }
}

void Faculty::printAdvisees() {
  for(int x = 0; x < adviseeList->getSize(); ++x) {
    Student* s = adviseeList->returnAtPos(x);
    cout << s;
  }
}

#endif
