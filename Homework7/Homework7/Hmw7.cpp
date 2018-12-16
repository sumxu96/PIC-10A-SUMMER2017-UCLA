/*
 
 Homework #7
 
 Author:  Sum Xu
 
 Email: sum.xu96@gmail.com
 
 Course: PIC 10A Summer 2017
 
 Honesty Pledge:
 
 I, Sum Xu, pledge that this is my independent work and abide by the guidelines of honesty outlined in the syllabus.
 
 List of known bugs: none
 
 Using classes, with credit limit of 1500, user inputs purchases and program calculates whether these purchases can be done with the credit limit. 
 
 */

#include <iostream>
#include <string>
using namespace std;

class Customer
{

public:
    
    //constructor
    Customer (string name, const double& creditLimit, double totalBalance, int numberOfPurchases);
    
    //accessors
    string get_name() const;
    double get_credit_limit() const;
    bool add_purchase(double val);
    double get_total_balance() const;
    int get_num_purchases() const;
    
    //mutators
    void set_total_balance(double totalBalance);
    void set_num_purchases(int numberOfPurchases);

private:
    
    int mPurchases;
    double mCreditLimit;
    double mTotalBalance;
    string mName;
    
};

// Definition of constructor and member functions


//constructor; setting credit limit to 1500
Customer::Customer (string name, const double& creditLimit, double totalBalance, int numberOfPurchases)
{
    mName = name;
    mCreditLimit = 1500;
    mTotalBalance = totalBalance;
    mPurchases = numberOfPurchases;
}

//define mutators
void Customer::set_total_balance (double totalBalance)
{
    mTotalBalance = totalBalance;
}
//
void Customer::set_num_purchases (int numberOfPurchases)
{
    mPurchases = numberOfPurchases;
}

//define accessors
string Customer::get_name() const
{
    return mName;
}

double Customer::get_credit_limit() const
{
    return mCreditLimit;
}

double Customer::get_total_balance() const
{
    return mTotalBalance;
}

int Customer::get_num_purchases() const
{
    return mPurchases;
}

bool Customer::add_purchase (double val)
{
    
    if (val > mCreditLimit)
    {
        return false;
    }
    
    return true;
}


int main ()
{
    //create object

    Customer c ("Sum Xu", 5000, 0, 0);
    
    //output customer name and credit limit
    cout<< "Customer: " << c.get_name() << endl;
    cout << "Credit Limit: " << c.get_credit_limit() <<endl;
    
    
    //define and initialize variables needed in while loop
   
    double val = 0;
    double totalBalance = 0;
    int numberOfPurchases = 0;
    string y_or_n;
    
    //while loop
    while (totalBalance <= c.get_credit_limit())
    {
        //user inputs purchase value of item
        cout << "Purchase value (in $): ";
        cin >> val;
        
        //user must input a correct value
        if (val < 0 || cin.fail())
        {
            cout << "Please enter a valid value." << endl;
            return 1;
        }

        //if input is larger than 1500, purchase cannot be completed
        if (!c.add_purchase(val))
            cout << "Not enough credit limit. Purchase cannot be completed." << endl;
        
        //if input is valid and total balance is less than credit limit...
        if (c.add_purchase(val) && totalBalance <= c.get_credit_limit())
        {
            //add up the purchase values
            totalBalance += val;
            
            //add to number of purchases counter
            numberOfPurchases = numberOfPurchases + 1;
            
            //if total balance becomes greater than the credit limit...
            if (totalBalance > c.get_credit_limit())
            {
                //output this message and subtract the purchase values and counter to "reset"
                cout << "Not enough credit limit. Purchase cannot be completed." << endl;
                totalBalance -= val;
                numberOfPurchases = --numberOfPurchases;
            }
            
            else cout << "Purchase successful." << endl;
        }
        
        //set balance and number of purchases with this member function
        c.set_total_balance(totalBalance);
        c.set_num_purchases(numberOfPurchases);
        
        //input y or n for another item
        cout << "Do you want to purchase another item (y/n)? ";
        cin >> y_or_n;
        
        //input must be correct
        if (y_or_n != "y" && y_or_n != "n")
        {
            cout << "Please enter either 'y' or 'n'." << endl;
            return 1;
        }
        
        //if "n", break out of loop
        if (y_or_n == "n")
            break;
    }
    
    //final output message, with get member functions
    cout << "The total of " << c.get_num_purchases() << " purchase(s) is $" << c.get_total_balance() << endl;
    return 0;
    }
