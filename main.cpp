#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 100;

struct Student {
    int studentID;
    string name;
    string course;
    int yearLevel;
};

class StudentList {
private:
    Student students[MAX_STUDENTS];
    int count;

public:
    StudentList() {
        count = 0;
    }

    void addStudent(int id, string name, string course, int year) {
        if (count >= MAX_STUDENTS) {
            cout << "Student list is full.\n";
            return;
        }

        students[count].studentID = id;
        students[count].name = name;
        students[count].course = course;
        students[count].yearLevel = year;

        count++;

        cout << "Student added successfully.\n";
    }

    void accessStudent(int id) {
        for (int i = 0; i < count; i++) {
            if (students[i].studentID == id) {
                cout << "\nStudent Information\n";
                cout << "Student ID: " << students[i].studentID << endl;
                cout << "Name: " << students[i].name << endl;
                cout << "Course: " << students[i].course << endl;
                cout << "Year Level: " << students[i].yearLevel << endl;
                return;
            }
        }

        cout << "Student not found.\n";
    }

    void updateStudent(int id, string newCourse, int newYear) {
        for (int i = 0; i < count; i++) {
            if (students[i].studentID == id) {
                students[i].course = newCourse;
                students[i].yearLevel = newYear;

                cout << "Student information updated successfully.\n";
                return;
            }
        }

        cout << "Student not found.\n";
    }

    void removeStudent(int id) {
        for (int i = 0; i < count; i++) {
            if (students[i].studentID == id) {


                for (int j = i; j < count - 1; j++) {
                    students[j] = students[j + 1];
                }

                count--;

                cout << "Student removed successfully.\n";
                return;
            }
        }

        cout << "Student not found.\n";
    }

    void orderStudents() {
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - i - 1; j++) {

                if (students[j].studentID > students[j + 1].studentID) {
                    Student temp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp;
                }
            }
        }

        cout << "Students ordered by Student ID.\n";
    }


    void displayStudents() {
        cout << "\n--- STUDENT INFORMATION SYSTEM ---\n";

        if (count == 0) {
            cout << "No students in the system.\n";
            return;
        }

        for (int i = 0; i < count; i++) {
            cout << "\nStudent ID: " << students[i].studentID << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Course: " << students[i].course << endl;
            cout << "Year Level: " << students[i].yearLevel << endl;
        }
    }
};

int main() {

    StudentList sis;


    sis.addStudent(1001, "Emmanuel Turingan", "BSIT", 2);
    sis.addStudent(1002, "John Lasac", "BSIT", 1);
    sis.addStudent(1003, "Jimuel Tolosa Navarette", "BSIT", 4);


    sis.accessStudent(1001);


    sis.updateStudent(1001, "BSIT", 2);


    sis.orderStudents();


    sis.displayStudents();


    sis.removeStudent(1002);


    sis.displayStudents();

    return 0;
}
