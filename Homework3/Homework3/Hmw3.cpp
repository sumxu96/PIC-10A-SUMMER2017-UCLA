/*
 
 Homework #3
 
 Author:  Sum Xu
 
 Email: sum.xu96@gmail.com
 
 Course: PIC 10A Summer 2017
 
 Honesty Pledge:
 
 I, Sum Xu, pledge that this is my independent work and abide by the guidelines of honesty outlined in the syllabus.
 
 List of known bugs: none
 
 User inputs a budget, living room length in feet, and living room width in feet. This will determine cost of flooring in living room. Dimensions are then also used to determine size of backyard for fencing, which is 3 times the area of living room. Program then determines whether cost of fencing and flooring is within budget or not.

 */

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    
    cout << "* Home Remodeling *" << endl;
    cout << endl;
    cout << endl;
    
    //defining and initializing many variables
    const double Flooring_Price = 3.79;
    const double Fence_Price = 18.00;
    
    double Budget = 0;
    double Living_Room_Width = 0;
    double Living_Room_Length = 0;
    

    double Area_Living_Room = 0;
    double Area_Backyard = 0;
    
    double Backyard_Length = 0;
    double Total_Backyard_Length = 0;
    
    double Cost_Flooring = 0;
    double Cost_Fencing = 0;
    double Total_Cost = 0;

    //user inputs budget
    cout << " Budget = ";
    cin >> Budget;
    cout << endl;
    cout << endl;
    
    //user inputs living room width in feet
    cout << " Living Room Width (feet) = ";
    cin >> Living_Room_Width;
    cout << endl;
    cout << endl;
    
    //user inputs living room length in feet
    cout << " Living Room Length (feet) = ";
    cin >> Living_Room_Length;
    cout << endl;
    cout << endl;
    
    //Calculations of areas, fence lengths, and costs based on the user inputs
    Area_Living_Room = Living_Room_Width * Living_Room_Length;
    Area_Backyard = 3 * Area_Living_Room;
    
    Backyard_Length = sqrt (Area_Backyard);
    Total_Backyard_Length = 3 * Backyard_Length;
    
    Cost_Flooring = Flooring_Price * Area_Living_Room;
    Cost_Fencing = std::ceil (Total_Backyard_Length) * Fence_Price;
    Total_Cost = Cost_Flooring + Cost_Fencing;
    
    //output when budget is greater than or equal to the total cost of flooring and fencing
    if (Budget >= Total_Cost)
    {
        cout << "* * * * * * * * * * * * * * * * * * *" << endl;
        cout << "* REMODELING PROJECT SPECIFICATIONS *" << endl;
        cout << "* * * * * * * * * * * * * * * * * * *" << endl;
        cout << endl;
        cout << endl;
        
        cout << "LIVING ROOM = " << Area_Living_Room << " square feet of flooring needed." << endl;
        cout << "BACK YARD = " << std::ceil (Total_Backyard_Length) << " feet of fence needed." << endl;
        cout << fixed << setprecision(2);
        cout << "TOTAL COST = $" << Total_Cost << endl;
    }
    
    //output when budget is less than the total cost of flooring and fencing, but also greater than or equal to cost of flooring
    else if (Budget < Total_Cost && Budget >= Cost_Flooring)
    {
        
        cout << "* * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
        cout << "* NOT ENOUGH BUDGET ... ADJUSTING BACK YARD SIZE. *" << endl;
        cout << "* * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
        cout << endl;
        cout << endl;
        
        cout << "LIVING ROOM = " << Area_Living_Room << " square feet of flooring is needed." << endl;
        cout << endl;
        cout << endl;
        
        cout << "      TOTAL COST    FENCE AMOUNT   BACK YARD SIZE" << endl;
        cout << endl;
        cout << endl;
        
        //defining and initializing for the "while" loop
        double Backyard_Size = 0;
        double Fence_Amount = 0;
        double Fence_Cost = 0;
        Fence_Amount = 3 * Backyard_Size;
        Fence_Cost = Fence_Amount * Fence_Price;
        Total_Cost = Cost_Flooring + Fence_Cost;
        
        //shows which backyard sizes in increments of 5' can fencing be applied within budget
        while (Total_Cost <= Budget)
        {
             cout << setw (7) << "$ " << fixed << setprecision(2) << Total_Cost << setprecision(0) << setw(12) << std::ceil (Fence_Amount) << "'" << setw (13) << std::ceil (Backyard_Size) << "' X " << std::ceil (Backyard_Size) << "'" << endl;
            Backyard_Size = Backyard_Size + 5;
            Fence_Amount = 3 * Backyard_Size;
            Fence_Cost = Fence_Amount * Fence_Price;
            Total_Cost = Cost_Flooring + Fence_Cost;
            
        }
        
    }
    
    //output when budget is less than total cost and less than cost of flooring
    else
    {
        cout << "* * * * * * * * * * * * * * * * * * *" << endl;
        cout << "* SORRY, YOUR BUDGET IS NOT ENOUGH. *" << endl;
        cout << "* * * * * * * * * * * * * * * * * * *" << endl;
    }
    
    
    return 0;
}

