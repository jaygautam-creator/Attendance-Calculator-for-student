#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

// Function to validate user input
int getValidatedInput(const string &prompt, int min, int max = numeric_limits<int>::max()) {
    int value;
    cout << prompt;
    while (!(cin >> value) || value < min || value > max) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a value between " << min << " and " << max << ": ";
    }
    return value;
}

// Function to calculate percentage
double calculatePercentage(int attended, int conducted) {
    if (conducted == 0) {
        return 0.0;
    }
    return static_cast<double>(attended) / conducted * 100;
}

// Function to print the attendance report
void printAttendanceReport(int totalConducted, int totalAttended, int remainingClasses, double requiredPercentage, int plannedAbsences) {
    double totalFutureClasses = totalConducted + remainingClasses;
    double minAttendedRequired = ceil((requiredPercentage / 100) * totalFutureClasses);

    // Projected attendance after planned absences
    int totalProjectedClasses = remainingClasses - plannedAbsences;
    double newAttended = totalAttended + totalProjectedClasses;
    double newTotalClasses = totalConducted + remainingClasses;
    double newPercentage = calculatePercentage(newAttended, newTotalClasses);

    int classesYouCanMiss = totalAttended + totalProjectedClasses - static_cast<int>(minAttendedRequired);

    cout << "\n--- Attendance Report ---\n";
    if (classesYouCanMiss < 0) {
        cout << "You cannot afford to miss any more classes. You need to attend all remaining classes to meet the required percentage." << endl;

        // Calculate additional classes needed
        int additionalClassesNeeded = static_cast<int>(minAttendedRequired) - (totalAttended + totalProjectedClasses);
        cout << "Additionally, you need to attend " << additionalClassesNeeded << " more classes than currently planned to meet the target.\n";
    } else {
        cout << "After your planned absences, you can afford to miss up to " << classesYouCanMiss << " more classes and still meet the required attendance percentage of " 
             << fixed << setprecision(2) << requiredPercentage << "%.\n";
    }

    // Display current and projected percentages
    double currentPercentage = calculatePercentage(totalAttended, totalConducted);
    double projectedPercentage = calculatePercentage(totalAttended + remainingClasses, totalFutureClasses);

    cout << left << setw(30) << "Current Attendance Percentage:" << fixed << setprecision(2) << currentPercentage << "%" << endl;
    cout << left << setw(30) << "Projected Attendance (Attend All):" << fixed << setprecision(2) << projectedPercentage << "%" << endl;
    cout << left << setw(30) << "Projected Attendance (After Absences):" << fixed << setprecision(2) << newPercentage << "%" << endl;
    cout << "-------------------------\n";
}

int main() {
    cout << "Welcome to the Attendance Calculator!\n";

    // Get inputs
    int totalConducted = getValidatedInput("Enter total classes conducted so far: ", 0);
    int totalAttended = getValidatedInput("Enter total classes attended so far: ", 0, totalConducted);
    int remainingClasses = getValidatedInput("Enter total remaining classes: ", 0);
    double requiredPercentage = getValidatedInput("Enter the required attendance percentage (e.g., 76 for 76%): ", 0, 100);

    // Get planned absences
    int plannedAbsences = getValidatedInput("Enter the number of classes you plan to miss: ", 0, remainingClasses);

    // Print attendance report
    printAttendanceReport(totalConducted, totalAttended, remainingClasses, requiredPercentage, plannedAbsences);

    // Allow rerun
    char choice;
    cout << "Do you want to calculate for another scenario? (y/n): ";
    cin >> choice;
    if (tolower(choice) == 'y') {
        main(); // Rerun the program
    } else {
        cout << "Thank you for using the Attendance Calculator. Goodbye!" << endl;
    }

    return 0;
}
