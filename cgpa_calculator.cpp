#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct Course {
    int number;
    double grade;
    double credits;
    double gradePoints;
};

int main() {
    cout << "==================================================" << endl;
    cout << "              CGPA CALCULATOR" << endl;
    cout << "==================================================" << endl;

    int numCourses;
    while (true) {
        cout << "\nEnter the number of courses: ";
        cin >> numCourses;
        if (cin.fail() || numCourses <= 0) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Please enter a valid positive number." << endl;
        } else {
            break;
        }
    }

    vector<Course> courses;
    double totalCredits = 0.0;
    double totalGradePoints = 0.0;

    cout << "\nEnter details for each course:" << endl;
    cout << "(Grade should be on a 10-point scale, e.g. 9.0, 8.5, 7.0 ...)\n" << endl;

    for (int i = 1; i <= numCourses; i++) {
        Course c;
        c.number = i;

        // Input Grade
        while (true) {
            cout << "--- Course " << i << " ---" << endl;
            cout << "Enter grade for Course " << i << ": ";
            cin >> c.grade;
            if (cin.fail() || c.grade < 0 || c.grade > 10) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Grade must be between 0 and 10. Try again." << endl;
            } else {
                break;
            }
        }

        // Input Credit Hours
        while (true) {
            cout << "Enter credit hours for Course " << i << ": ";
            cin >> c.credits;
            if (cin.fail() || c.credits <= 0) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Credit hours must be greater than 0. Try again." << endl;
            } else {
                break;
            }
        }

        c.gradePoints = c.grade * c.credits;
        totalCredits += c.credits;
        totalGradePoints += c.gradePoints;
        courses.push_back(c);
        cout << endl;
    }

    // Calculate CGPA
    double cgpa = (totalCredits > 0) ? (totalGradePoints / totalCredits) : 0.0;

    // Display Results
    cout << "==================================================" << endl;
    cout << "                   RESULTS" << endl;
    cout << "==================================================" << endl;
    cout << left << setw(10) << "Course" 
         << setw(12) << "Grade" 
         << setw(12) << "Credits" 
         << "Grade Points" << endl;
    cout << "--------------------------------------------------" << endl;

    cout << fixed << setprecision(2);
    for (const auto& c : courses) {
        cout << left << setw(10) << c.number
             << setw(12) << c.grade
             << setw(12) << setprecision(1) << c.credits
             << setprecision(2) << c.gradePoints << endl;
    }

    cout << "--------------------------------------------------" << endl;
    cout << left << setw(10) << "Total"
         << setw(12) << ""
         << setw(12) << setprecision(1) << totalCredits
         << setprecision(2) << totalGradePoints << endl;

    cout << "==================================================" << endl;
    cout << "\nSemester GPA / CGPA : " << fixed << setprecision(2) << cgpa << endl;
    cout << "==================================================" << endl;

    return 0;
}
