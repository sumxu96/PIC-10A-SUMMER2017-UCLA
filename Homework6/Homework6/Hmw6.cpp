/*
 
 Homework #6
 
 Author:  Sum Xu
 
 Email: sum.xu96@gmail.com
 
 Course: PIC 10A Summer 2017
 
 Honesty Pledge:
 
 I, Sum Xu, pledge that this is my independent work and abide by the guidelines of honesty outlined in the syllabus.
 
 List of known bugs: none
 
 Simplified battleship game; user inputs location and program determines whether that location has a ship there or not. Shows success rate and where the ships are at the end.
 
 */

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int main() {
    
    //set seed for random number generator
    srand (time (0));
    
    //vector for the location of ships; vector element values all 0 initially
    vector<int> location(10);
    for (int i = 0; i < 10; i++)
        location [i] = 0;
    
    //string array for the original board
    string board[10] = {"---", "---", "---", "---", "---", "---", "---", "---", "---", "---"};
    
    //storage array for random numbers
    int storageArray[3];
    
    //ensure that 3 unique random integers are generated
    for (int j = 0; j < 3; j++)
    {
        bool checkforRepeat;
        int random_ship;
        
        do
        {
            random_ship = rand()%10;
            checkforRepeat = true;
            
            for (int k = 0; k < j; k++)
                if (random_ship == storageArray[k])
                {
                    checkforRepeat = false;
                    break;
                }
            
        }
        while (!checkforRepeat);
        storageArray[j] = random_ship;
    }
    
    //make the elements of storage array into own integers
    int a = storageArray[0];
    int b = storageArray[1];
    int c = storageArray[2];
    
    //3 unique vector elements will have the value 1, which represents that the ship is there
    location[a] = 1;
    location[b] = 1;
    location[c] = 1;
    
    //define and initialize variables to be used
    int hitCounter = 0;
    double successRate = 0;
    const double numberofGuesses = 3.0;
    
    //clear screen
    system("cls");
    
    //display board with all "---"
    for (int d = 0; d < (sizeof(board)/sizeof(board[0])); d++)
        cout << board[d] << " ";
        cout << "Shot 1 Location: ";
    
    //first guess
    int guess1 = 0;
    cin >> guess1;
    
    //if guess is not valid, program stops
    if (guess1 < 1 || guess1 > 10 || cin.fail())
    {
        cout << "Please enter number between 1 and 10." << endl;
        return 1;
    }
    
    //clear screen
    system("cls");
    
    //if guess is valid...
    if (guess1 >= 1 && guess1 <= 10)
    {
        //use [guess1-1] because array index is user input - 1; if location equal to 0, display * at that spot
        if (location[guess1-1] == 0)
        {
            board[guess1-1] = " * ";
            
            for (int d = 0; d < (sizeof(board)/sizeof(board[0])); d++)
                cout << board[d] << " ";
                cout << "Shot 2 Location: ";
        }
        
        //if location equal to 1, display <*> at that spot
        else if (location [guess1-1] == 1)
        {
            board[guess1-1] = "<*>";
            hitCounter = hitCounter + 1;
            for (int d = 0; d < (sizeof(board)/sizeof(board[0])); d++)
                cout << board[d] << " ";
                cout << "Shot 2 Location: ";
        }
        
    }
    
    //second guess
    int guess2 = 0;
    cin >> guess2;
    
    //if second guess is not valid, program stops
    if (guess2 < 1 || guess2 > 10 || cin.fail())
    {
        cout << "Please enter number between 1 and 10." << endl;
        return 1;
    }
    
    //if second guess is same as first guess, program stops
    if (guess2 == guess1)
    {
        cout << "Please do not enter the same number." << endl;
        return 1;
    }
    
    //clear screen
    system("cls");
    
    
    if (guess2 >= 1 && guess2 <= 10)
    {
        //display * if guess 2 is incorrect
        if (location[guess2-1] == 0)
        {
            board[guess2-1] = " * ";
            
            for (int d = 0; d < (sizeof(board)/sizeof(board[0])); d++)
                cout << board[d] << " ";
            cout << "Shot 3 Location: ";
        }
        //display <*> if guess 2 is correct
        else if (location [guess2-1] == 1)
        {
            board[guess2-1] = "<*>";
            hitCounter = hitCounter + 1;
            for (int d = 0; d < (sizeof(board)/sizeof(board[0])); d++)
                cout << board[d] << " ";
            cout << "Shot 3 Location: ";
        }
        
    }
    
    //third guess
    int guess3 = 0;
    cin >> guess3;
    
    //need valid input
    if (guess3 < 1 || guess3 > 10 || cin.fail())
    {
        cout << "Please enter number between 1 and 10." << endl;
        return 1;
    }
    
    //cannot be same as past 2 guesses
    if (guess3 == guess1 || guess3 == guess2)
    {
        cout << "Please do not enter the same number.";
        return 1;
    }
    
    //clear screen
    system("cls");
    
    if (guess3 >= 1 && guess3 <= 10)
    {
        // * if guess 3 is incorrect
        if (location[guess3 - 1] == 0)
        {
            board[guess3 - 1] = " * ";
        }
        
        // <*> if guess 3 is correct
        else if (location [guess3 - 1] == 1)
        {
            board[guess3 - 1] = "<*>";
            hitCounter = hitCounter + 1;
        }
        
    }
    
    //if the spot with ship is not already guessed, display <>
    if (board[a] != "<*>")
        board[a] = "<> ";
    
    if (board[b] != "<*>")
        board[b] = "<> ";
    
    if (board[c] != "<*>")
        board[c] = "<> ";
    
    //display final board with all guesses and answers
    for (int d = 0; d < (sizeof(board)/sizeof(board[0])); d++)
        cout << board[d] << " ";
    
    //calculate and display success rate
    successRate = (hitCounter/numberofGuesses) * 100;
    cout << fixed << setprecision(0) << "Success = " << successRate << "%" << endl;
    
    return 0;
}
