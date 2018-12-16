/*
 
 Homework #2
 
 Author:  Sum Xu
 
 Email: sum.xu96@gmail.com
 
 Course: PIC 10A Summer 2017
 
 Honesty Pledge:
 
 I, Sum Xu, pledge that this is my independent work and abide by the guidelines of honesty outlined in the syllabus.
 
 List of known bugs: none
 
 User inputs various personal information such as name, birthday, telephone number etc.
 Two email outputs to current employees and new employee using information from user inputs
 
 */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    //various user inputs following this output
    cout << "===== PLEASE COMPLETE THE FOLLOWING FORM =====" << endl;
    cout << endl;
    
    //user inputs First and Last name
    cout << "What is your full name (First Last)? ";
    string FirstName;
    string LastName;
    cin >> FirstName >> LastName;
    string FullName = FirstName + " " + LastName;
    
    //Set up Initials
    string Initials = FirstName.substr(0,1) + "." + LastName.substr(0,1) + ".";
    
    //Initials for ID # later
    string InitialsNoDots = FirstName.substr(0,1) + LastName.substr(0,1);
    
    //user inputs birth year
    cout << endl;
    cout << "What year were you born? ";
    int (YearBorn) = 0;
    cin >> YearBorn;
    
    //user inputs birth month
    cout << endl;
    cout << "What is your birth month? ";
    string (BirthMonth);
    cin >> BirthMonth;
    
    //user inputs day of month of birth
    cout << endl;
    cout << "What day of the month were you born in? ";
    string (DayOfMonthBorn);
    cin >> DayOfMonthBorn;
    
    //user inputs telephone number
    cout << endl;
    cout << "What is your telephone number? ";
    string (TelephoneNumber);
    cin >> TelephoneNumber;
    
    //user inputs email address
    cout << endl;
    cout << "What is your email? ";
    string (Email);
    cin >> Email;
    
    //user inputs desired hourly wage
    cout << endl;
    cout << "Write your desired hourly wage = $ ";
    double (HourlyWage) = 0;
    cin >> HourlyWage;
    
    //salary calculation
    const int WorkHoursWeek = 40;
    const int WeeksInYear = 52;
    long Salary = HourlyWage * WorkHoursWeek * WeeksInYear;
    if (Salary > 62500) Salary = 62500;
    if (Salary < 17000) Salary = 17000;
    
    //adding comma to salary number
    string SalaryWithComma = to_string(Salary);
    int CommaPosition = SalaryWithComma.length() - 3.0;
    while (CommaPosition > 0)
    {
        SalaryWithComma.insert(CommaPosition, ",");
        CommaPosition-=3;
    }
    
    //next year age calculation
    const int NextYear = 2018;
    int NextYearAge = NextYear - YearBorn;
    
    //output message to current employees
    cout << endl;
    cout << "* * * * * * * * * * * * * * * * * * * *" << endl;
    cout << "TO: ALL CURRENT EMPLOYEES" << endl;
    cout << endl;
    cout << endl;
    
    cout << "Please join me in welcoming " << FullName << " to our company!" << endl;
    cout << endl;
    cout << setw(15) << "Name: " << FullName << endl;
    cout << setw(15) << "Initials: " << Initials << endl;
    cout << setw(15) <<"Email: " << Email << endl;
    cout << endl;
    
    cout << "Because " << Initials << " will be " << NextYearAge << " years young, we will celebrate by going" << endl;
    cout << "out to lunch next year during " << Initials << "'s birthday on " << BirthMonth << " " << DayOfMonthBorn << "." << endl;
    cout << endl;
    cout << endl;
    cout << "* * * * * * * * * * * * * * * * * * * *" << endl;

    //output message to new employee
    cout << "TO: " << Email << endl;
    cout << endl;
    cout << endl;
    
    cout << "Dear " << FirstName << "," << endl;
    cout << endl;
    cout << "Please review your new employee information:" << endl;
    cout << endl;
    
    cout << setw (15) << "Name: " << FullName << endl;
    cout << setw (15) << "ID #: " << InitialsNoDots << TelephoneNumber.substr(TelephoneNumber.length() - 4) << endl;
    cout << setw (15) << "DOB: " << BirthMonth << " " << DayOfMonthBorn << " " << YearBorn << endl;
    cout << setw (15) << "Salary: $ " << SalaryWithComma << endl;
    cout << endl;
    cout << "Welcome to our company!" << endl;
    cout << endl;

    return 0;
   
}
