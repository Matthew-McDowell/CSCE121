#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include "School.h"
#include "AttendanceRecord.h"

using namespace std;

void School::addCourses(string filename) {
    ifstream ifs (filename);
    if (!ifs.is_open()) {
        cout << "Unable to open file: " << filename << endl;
        return;
    }
    while (!ifs.eof()) {
        // DECLARATIONS
        string line;

        string id;
        string title;
        string start;
        string end;

        string startDateHour;
        string startDateMinute;
        string endDateHour;
        string endDateMinute;

        int startDateHourInt;
        int startDateMinuteInt;
        int endDateHourInt;
        int endDateMinuteInt;

        // Parse data
        getline(ifs, line);
        istringstream ss(line);
        // Check for EOF
        if (line.empty()) { break; }

        getline(ss, id, ',');
        getline(ss, start, ',');
        getline(ss, end, ',');
        getline(ss, title);

        // Convert startTime & endTime strings into Date() format
        istringstream startStream(start);
        istringstream endStream(end);
        getline(startStream, startDateHour, ':');
        getline(startStream, startDateMinute);
        getline(endStream, endDateHour, ':');
        getline(endStream, endDateMinute);

        startDateHourInt = stoi(startDateHour);
        startDateMinuteInt = stoi(startDateMinute);
        endDateHourInt = stoi(endDateHour);
        endDateMinuteInt = stoi(endDateMinute);

        Date startTime = Date(startDateHourInt, startDateMinuteInt);
        Date endTime = Date(endDateHourInt, endDateMinuteInt);

        if (!ss.fail()) {
            courses.push_back(Course(id, title, startTime, endTime));
        }
    }
}

void School::addStudents(string filename) {
    ifstream ifs (filename);
    if (!ifs.is_open()) {
        cout << "Unable to open file: " << filename << endl;
        return;
    }
    while (!ifs.eof()) {
        string line;
        getline(ifs, line);

        // Check for EOF
        if (line.empty()) { break; }

        istringstream ss(line);
        string uin;
        getline(ss, uin, ',');
        string name;
        getline(ss, name);
        name.erase(name.find_last_not_of(" \r")+1);
        if (!ss.fail()) {
            students.emplace_back(uin, name);
        }
    }
}

void School::addAttendanceData(string filename) {
    ifstream ifs(filename);
    if (!ifs.is_open()) {
        cout << "Unable to open file: " << filename << endl;
        return;
    }
    while (!ifs.eof()) {
        string line;
        getline(ifs, line);
        istringstream ss(line);

        // Check for EOF
        if (line.empty()) { break; }

        string year;
        string month;
        string day;
        string hour;
        string minute;
        string second;
        string course_id;
        string student_id;

        getline(ss, year, '-');
        getline(ss, month, '-');
        getline(ss, day, ' ');
        getline(ss, hour, ':');
        getline(ss, minute, ':');
        getline(ss, second, ',');
        getline(ss, course_id, ',');
        getline(ss, student_id);

        Date time = Date(stoi(year), stoi(month), stoi(day), stoi(hour), stoi(minute), stoi(second));
        AttendanceRecord ar = AttendanceRecord(course_id, student_id, time);

        if (!ss.fail()) {
            // Add to attendance record (if time is greater than or equal to the
            // start time and less than or equal to the end time.
            for (auto & course : courses) {
                if (course.getID() == course_id) {
                    if (course.getStartTime() <= time && time <= course.getEndTime()) {
                        course.addAttendanceRecord(ar);
                    }
                }
            }
        }
    }
}

void School::listCourses() {
    if (!courses.empty()) {
        for (auto & course : courses) {
            cout << course.getID() << "," << course.getStartTime().getTime() << ",";
            cout << course.getEndTime().getTime() << "," << course.getTitle() << endl;
        }
    }
    else {
        cout << "No courses" << endl;
    }
}

void School::listStudents() {
    if (!students.empty()) {
        for (auto & student : students) {
            cout << student.get_id() << "," << student.get_name() << endl;
        }
    }
    else {
        cout << "No students" << endl;
    }
}

void School::outputCourseAttendance(string course_id) {
    if (!courses.empty()) {
        for (auto & course : courses) {
            if (course.getID() == course_id) {
                course.outputAttendance();
            }
        }
    }
    else {
        cout << "No records" << endl;
    }
}

void School::outputStudentAttendance(string student_id, string course_id) {
    if (!courses.empty()) {
        for (auto & course : courses) {
            if (course.getID() == course_id) {
                course.outputAttendance(student_id);
            }
        }
    }
    else {
        cout << "No records" << endl;
    }
}
