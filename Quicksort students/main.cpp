#include <iostream>

using namespace std;

const int SIZE = 100;

struct Student {
    char name[SIZE];
    int facultyNumber;
    int age;
    double grade;

    void input(int i) {
        char debug[1];
        cin.getline(debug, 1);
        //cout << "Enter " << i << " student's name: ";
        cin.getline(name, SIZE);
        //cout << "Enter " << name << "'s faculty number: ";
        cin >> facultyNumber;
        //cout << "Enter " << name << "'s age: ";
        cin >> age;
        //cout << "Enter " << name << "'s grade: ";
        cin >> grade;
    }

    void output(int i) {
        cout << i << ":" << endl;
        cout << "   Name: " << name << endl;
        cout << "   Faculty number: " << facultyNumber << endl;
        cout << "   Age: " << age << endl;
        cout << "   Grade: " << grade << endl;
    }
};

void sortStudents(Student *students, int left, int right) {
    if (left < right) {
        Student pivot = students[right];

        int index = left;

        for (int i = left; i < right; i++) {
            //Sort by grade descending and then by facultyNumber ascending
            if ((students[i].grade > pivot.grade) ||
                (students[i].grade == pivot.grade && students[i].facultyNumber < pivot.facultyNumber)) {

                Student stud = students[i];
                students[i] = students[index];
                students[index] = stud;
                index++;
            }
        }

        students[right] = students[index];
        students[index] = pivot;

        sortStudents(students, left, index - 1);
        sortStudents(students, index + 1, right);
    }
}

int main() {
    int n;
    //cout << "Enter number of students: ";
    cin >> n;

    Student *students = new Student[n];

    for (int i = 0; i < n; i++) {
        Student stud;
        stud.input(i + 1);
        students[i] = stud;
    }

    sortStudents(students, 0, n - 1);

    for (int i = 0; i < n; i++) {
        students[i].output(i + 1);
    }

    delete[] students;

    return 0;
}