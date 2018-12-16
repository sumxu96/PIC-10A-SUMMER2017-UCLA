/*
 
 Homework # 1
 
 Author:  Sum Xu
 
 Email: sum.xu96@gmail.com
 
 Course: PIC 10A Summer 2017
 
 
 Honesty Pledge:
 
 I, Sum Xu, pledge that this is my independent work and abide by the guidelines of honesty outlined in the syllabus.
 
 
 User inputs: state postal code
 
 Output: message saying I <3 (input state)  -\_(- __-)_/-
 
 List of known bugs: none
 */


#include <iostream>
#include <string>

using namespace std;

int main ()

{
    //user inputs state code
    cout << "STATE CODE = ";
    string state;
    cin >> state;
    
    //output message with face
    cout << endl;
    cout << "***************" << endl;
    cout << "**I LOVE \"" << state << "\"" << "**   -\\_(- __-)_/-" << endl;
    cout << "***************" << endl;
    
    return (0);
}







