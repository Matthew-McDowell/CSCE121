#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Student.h"

using namespace std;

Student::Student(std::string student_id, std::string name) {
    this->id = student_id;
    this->name = name;
}

string Student::get_id() {
    return this->id;
}

string Student::get_name() {
    return this->name;
}

void Student::addCourse(string course_id) {
  course_ids.push_back(course_id);
}

void Student::listCourses() {
    cout << "Courses for " << this->get_id() << endl;
    for (const auto & course_id : this->course_ids) {
        cout << course_id << endl;
    }
}
