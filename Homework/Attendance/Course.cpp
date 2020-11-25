#include <iostream>
#include <fstream>
#include <string>
#include "Course.h"
#include "Date.h"
#include "AttendanceRecord.h"

using namespace std;

Course::Course(string id, string title, Date startTime, Date endTime) :
    id(id), title(title), startTime(startTime), endTime(endTime) {
    this->id = id;
    this->title = title;
    this->startTime = startTime;
    this->endTime = endTime;
}

string Course::getID() {
    return this->id;
}

string Course::getTitle() {
    return this->title;
}

Date Course::getStartTime() {
    return startTime;
}

Date Course::getEndTime() {
    return endTime;
}

void Course::addAttendanceRecord(AttendanceRecord ar) {
    attendanceRecords.push_back(ar);
}

void Course::outputAttendance() {
    bool foundRecord = false;
    for (auto & attendanceRecord : this->attendanceRecords) {
        foundRecord = true;
        cout << attendanceRecord.getDate().getDate() << ",";
        cout << attendanceRecord.getCourseID() << ",";
        cout << attendanceRecord.getStudentID() << endl;
    }
    if (!foundRecord) {
        cout << "No records" << endl;
    }
}

void Course::outputAttendance(string student_id) {
    bool foundRecord = false;
    for (auto & attendanceRecord : this->attendanceRecords) {
        if (attendanceRecord.getStudentID() == student_id) {
            foundRecord = true;
            cout << attendanceRecord.getDate().getDate() << ",";
            cout << attendanceRecord.getCourseID() << ",";
            cout << attendanceRecord.getStudentID() << endl;
        }
    }
    if (!foundRecord) {
        cout << "No records" << endl;
    }
}
