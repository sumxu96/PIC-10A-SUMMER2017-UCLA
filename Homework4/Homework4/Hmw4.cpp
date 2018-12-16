/*
 
 Homework #4
 
 Author:  Sum Xu
 
 Email: sum.xu96@gmail.com
 
 Course: PIC 10A Summer 2017
 
 Honesty Pledge:
 
 I, Sum Xu, pledge that this is my independent work and abide by the guidelines of honesty outlined in the syllabus.
 
 List of known bugs: none
 
 User inputs homework, exam I, exam II, and final exam grades. Program outputs these grades in two decimal places and also calculates the overall grade, which is converted into a class grade.
 */

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    // defining and initializing variables
    double homework_grade = 0;
    double exam_1_grade = 0;
    double exam_2_grade = 0;
    double final_grade = 0;
    double overall_grade = 0;
    string class_grade;
    
    cout << "PIC 10A GRADE CALCULATOR" << endl;
    cout << endl;
    
    //user inputs homework grade
    cout << "Homework grade (%)  =  ";
    cin >> homework_grade;
        cout << endl;
    
    //program exits if homework grade is less than 0 or greater than 100
    if (homework_grade < 0 || homework_grade > 100)
    {
        cout << "The homework grade must not be negative nor greater than 100." << endl;
        return 1;
    }
    
    //user inputs exam I grade
    cout << "Exam I grade (%)  =  ";
    cin >> exam_1_grade;
    cout << endl;
    
    //program exits if exam I grade is less than 0 or greater than 100
    if (exam_1_grade < 0 || exam_1_grade > 100)
    {
        cout << "Exam I grade must not be negative nor greater than 100." << endl;
        return 1;
    }
    
    //user inputs exam II grade
    cout << "Exam II grade (%)  =  ";
    cin >> exam_2_grade;
    cout << endl;
    
    //program exits if exam II grade is less than 0 or greater than 100
    if (exam_2_grade < 0 || exam_2_grade > 100)
    {
        cout << "Exam II grade must not be negative nor greater than 100." << endl;
        return 1;
    }
    
    //user inputs final exam grade
    cout << "Final Exam grade (%)  =  ";
    cin >> final_grade;
    cout << endl;
    
    //program exits if final exam grade is less than 0 or greater than 100
    if (final_grade < 0 || final_grade > 100)
    {
        cout << "The final exam grade must not be negative nor greater than 100." << endl;
        return 1;
    }
    
    //replacing final exam grade with lower of two midterm exam grades
    
    if (exam_2_grade < exam_1_grade && final_grade > exam_2_grade)
    {
        exam_2_grade = final_grade;
    }
    
    else if (exam_1_grade < exam_2_grade && final_grade > exam_1_grade)
    {
        exam_1_grade = final_grade;
    }
    
    //overall grade calculation
    overall_grade = (0.2*homework_grade) + (0.25*exam_1_grade) + (0.25*exam_2_grade) + (0.3*final_grade);
    
    //overall grade to class grade
    if (overall_grade <= 100 && overall_grade >= 93)
        class_grade = "A";
    else if (overall_grade >= 90)
        class_grade = "A-";
    else if (overall_grade >= 87)
        class_grade = "B+";
    else if (overall_grade >= 83)
        class_grade = "B";
    else if (overall_grade >= 80)
        class_grade = "B-";
    else if (overall_grade >= 77)
        class_grade = "C+";
    else if (overall_grade >= 73)
        class_grade = "C";
    else if (overall_grade >= 70)
        class_grade = "C-";
    else if (overall_grade >= 67)
        class_grade = "D+";
    else if (overall_grade >= 63)
        class_grade = "D";
    else if (overall_grade >= 61)
        class_grade = "D-";
    else if (overall_grade >= 0)
        class_grade = "F";
    
    //grade outputs with 2 decimal places
    cout << "CATEGORY" << setw (15) << "GRADE" << endl;
    cout << fixed << setprecision (2);
    cout << endl;
    
    cout << "HOMEWORK" << setw (15) << homework_grade << endl;
    cout << "EXAM I" << setw (17) << exam_1_grade << endl;
    cout << "EXAM II" << setw (16) << exam_2_grade << endl;
    cout << "FINAL" << setw (18) << final_grade << endl;
    cout << "OVERALL GRADE" << setw (10) << overall_grade << endl;
    cout << "CLASS GRADE" << setw (9) << class_grade << endl;
    
    
    
    return 0;
}
