#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int month;
    int day;
    int year;

public:
    // Default + parameterized constructor
    Date(int m = 1, int d = 1, int y = 2001) {

        bool valid = true;

        // Validate month
        if (m < 1 || m > 12)
            valid = false;

        // Validate day based on month
        if (valid) {
            if (m == 2) {
                if (d < 1 || d > 28)
                    valid = false;
            }
            else if (m == 4 || m == 6 || m == 9 || m == 11) {
                if (d < 1 || d > 30)
                    valid = false;
            }
            else {
                if (d < 1 || d > 31)
                    valid = false;
            }
        }

        if (valid) {
            month = m;
            day = d;
            year = y;
        } else {
            month = 1;
            day = 1;
            year = 2001;
        }
    }

    void printNumeric() const {
        cout << month << "/" << day << "/" << year << endl;
    }

    void printMonthFirst() const {
        string monthNames[] = {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
        };
        cout << monthNames[month - 1] << " " << day << ", " << year << endl;
    }

    void printDayFirst() const {
        string monthNames[] = {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
        };
        cout << day << " " << monthNames[month - 1] << " " << year << endl;
    }
};

int main() {
    int m, d, y;

    cout << "Enter month: ";
    cin >> m;
    cout << "Enter day: ";
    cin >> d;
    cout << "Enter year: ";
    cin >> y;

    Date userDate(m, d, y);

    cout << "\nYour date in different formats:\n";
    userDate.printNumeric();
    userDate.printMonthFirst();
    userDate.printDayFirst();

    return 0;
}