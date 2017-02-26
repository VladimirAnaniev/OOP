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
        cin>>facultyNumber;
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
        int middle = left + right / 2;
        Student pivot = students[middle];

        students[middle] = students[right];
        students[right] = pivot;

        int index = left;

        for (int i = left; i < right; i++) {
            if (students[i].grade > pivot.grade) {
                Student stud = students[i];
                students[i] = students[index];
                students[index] = stud;
                index++;
            }
            else if(students[i].grade == pivot.grade) {
                if(students[i].grade == pivot.grade)
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

    sortStudents(students, 0, n-1);

    for (int i = 0; i < n; i++) {
        students[i].output(i+1);
    }

    delete[] students;

    return 0;
}