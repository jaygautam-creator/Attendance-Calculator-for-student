# Attendance Calculator in C++

## Overview
This C++ program helps students calculate their current and projected attendance percentages, plan absences, and determine how many more classes they can miss while meeting the required attendance threshold. It provides user-friendly prompts and robust input validation.

## Features
- Calculates current attendance percentage.
- Projects attendance percentage with planned absences.
- Determines how many more classes can be missed to meet the required attendance percentage.
- Includes enhanced input validation to ensure correct user input.

## How to Use
1. Compile the program:
   ```bash
   g++ attendance_report_calc.cpp -o attendance_calc
Run the program: 
./attendance_calc
Follow the prompts to enter:
Total classes conducted
Total classes attended
Remaining classes
Required attendance percentage
Number of classes you plan to miss
Example

Input:
Enter total classes conducted so far: 90
Enter total classes attended so far: 83
Enter total remaining classes: 38
Enter the required attendance percentage (e.g., 76 for 76%): 76
Enter the number of classes you plan to miss: 19
Output:
Current Attendance Percentage: 92.22%
Projected Attendance (Attend All): 94.53%
Projected Attendance (After Absences): 79.69%

License

This project is licensed under the MIT License. Feel free to use, modify, or contribute to it!
