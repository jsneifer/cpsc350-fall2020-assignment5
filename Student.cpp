#ifndef STUDENT_CPP
#define STUDENT_CPP


#include "Student.h"
#include <string>

Student::Student() {
  sID = rand() % 9999 + 1000;

}

Student::Student(int id, string n, string l, string m, double g, int ad) {
  sID = id;
  name = n;
  level = l;
  major = m;
  gpa = g;
  advisor = ad;
}
Student::Student(string n, string l, string m, double g, int ad) {
  sID = rand() % 9999 + 1000;
  name = n;
  level = l;
  major = m;
  gpa = g;
  advisor = ad;
}

Student::~Student() {}

//"Gets"
int Student::getID() {
  return sID;
}
string Student::getName() {
  return name;
}
string Student::getLevel() {
  return level;
}
string Student::getMajor() {
  return major;
}
double Student::getGPA() {
  return gpa;
}
int Student::getAdvisor() {
  return advisor;
}

//"Sets"
void Student::setID(int id) {
  sID = id;
}
void Student::setName(string n) {
  name = n;
}
void Student::setLevel(string l) {
  level = l;
}
void Student::setMajor(string m) {
  major = m;
}
void Student::setGPA(double g) {
  gpa = g;
}
void Student::setAdvisor(int ad) {
  advisor = ad;
}

bool Student::operator<(Student s2) {
  return lessThan(s2);
}
bool Student::operator>(Student s2){
  return greaterThan(s2);
}
bool Student::operator==(Student s2) {
  return equalTo(s2);
}
bool Student::operator!=(Student s2) {
  return notEqual(s2);
}
ostream& operator<<(ostream& os, Student *s) {
  os << s->getStudentInfo();
  return os;
}
bool Student::notEqual(Student s2) {
  if(sID != s2.getID()) {
    return true;
  } else {
    return false;
  }
}
bool Student::equalTo(Student s2) {
  if(sID == s2.getID()) {
    return true;
  } else {
    return false;
  }
}
bool Student::lessThan(Student s2) {
  if (sID < s2.getID()) {
    return true;
  } else {
    return false;
  }
}
bool Student::greaterThan(Student s2) {
  if(sID > s2.getID()) {
    return true;
  } else {
    return false;
  }
}

string Student::getStudentInfo() {
  string info = "";
  info += "Student ID: " + to_string(sID);
  info += "\nName: " + name;
  info += "\nLevel: " + level;
  info += "\nMajor: " + major;
  info += "\nGPA: " + to_string(gpa);
  info += "\nAdvisor ID: " + to_string(advisor) + "\n\n";
  return info;
}

#endif
