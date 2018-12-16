/*
 
 Homework #5
 
 Author:  Sum Xu
 
 Email: sum.xu96@gmail.com
 
 Course: PIC 10A Summer 2017
 
 Honesty Pledge:
 
 I, Sum Xu, pledge that this is my independent work and abide by the guidelines of honesty outlined in the syllabus.
 
 List of known bugs: none
 
 User inputs initial population, birth rate, death rate, and the years he/she wants to look at. Program uses these and calculates the population after the years inputted in deterministic and environmental models. Extinction possibility and probability are also outputted.
 */

//header files
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

//defining functions used in program; parameters determined by variables needed in function
double growth_rate (double birth_rate, double death_rate);
int population (int initial_population, int years, double birth_rate, double death_rate, double random);
bool extinction (double birth_rate, double death_rate);
double extinction_probability (int initial_population, int years, double birth_rate, double death_rate);
                
int main() {
    
    //setting seed for random number generator
    srand(time(0));
    
    //defining and initializing input variables
    int initial_population = 0;
    double birth_rate = 0;
    double death_rate = 0;
    int years = 0;
    
    //defining/initializing variables that will be outputted
    string possibility;
    double extinct_probability = 0;
    
    //user inputs initial population
    cout << "Initial Population = ";
    cin >> initial_population;
    cout << endl;
    
    //if population inputted is less than 2 or not integer, program stops
    if (initial_population < 2 || cin.fail())
    {
        cout << "Please enter proper initial population." << endl;
        return 1;
    }
    
    //user inputs birth rate
    cout << "Birth Rate = ";
    cin >> birth_rate;
    cout << endl;
    
    //if birth rate is not between 0 and 1, program stops
    if (birth_rate < 0 || birth_rate > 1)
    {
        cout << "Birth rate must be between 0 and 1." << endl;
        return 1;
    }
    
    //user inputs death rate
    cout << "Death Rate = ";
    cin >> death_rate;
    cout << endl;
    
    //if death rate is not between 0 and 1, program stops
    if (death_rate < 0 || death_rate > 1)
    {
        cout << "Death rate must be between 0 and 1." << endl;
        return 1;
    }
    
    //user inputs years
    cout << "Years = ";
    cin >> years;
    cout << endl;
    
    //if years is negative, program stops
    if (years < 0)
    {
        cout << "Years must not be less than 0." << endl;
        return 1;
    }
    
    //calling population function
    int population_deterministic = population (initial_population, years, birth_rate, death_rate, 0);
    int population_environmental = population (initial_population, years, birth_rate, death_rate, 1);
    
    //calling extinction function; if extinction function returns true, string possibility is "POSSIBLE"
    if (extinction(birth_rate, death_rate))
    {
        possibility = "POSSIBLE";
    }
    
    //calling extinction function; if extinction function returns false, string possibility is "NOT POSSIBLE"
    if (!extinction(birth_rate, death_rate))
    {
        possibility = "NOT POSSIBLE";
    }
    
    //calling extinction_probability function
    extinct_probability = extinction_probability (initial_population, years, birth_rate, death_rate);
    
    //outputs deterministic and environmental populations, and also outputs possibility and probability of extinction
    cout << "MODEL" << setw (23) << "POPULATION" << setw (22) << "EXTINCTION" << endl;
    cout << "DETERMINISTIC" << setw (15) << population_deterministic << setw (22) << possibility << endl;
    cout << "ENVIRONMENTAL" << setw (15) << population_environmental << setw (19) << "PROB = " << extinct_probability << endl;
    return 0;
    
}

//growth rate function to calculate constant r
double growth_rate (double birth_rate, double death_rate) {
    double r = 0;
    r = birth_rate - death_rate;
    return r;
}

//population function to determine deterministic and environmental populations; parameter "random" used to return proper population
int population (int initial_population, int years, double birth_rate, double death_rate, double random) {

    //defining and initializing variables used in future calculations
    int P_year_before = initial_population;
    int t = 0;
    double P_deterministic = 0;
    double P_environmental = 0;
    
    //calling growth_rate function for constant r
    double r = growth_rate (birth_rate, death_rate);
    
    //deterministic population calculation; if deterministic population negative, it is 0 instead
    P_deterministic = initial_population * pow(1+r,years);
    if (P_deterministic < 0)
        P_deterministic = 0;
    
    //calculating environmental population
    while (t <= years)
    {
        //random number generator for variable E between -1 and 1
        double E = ((2.0)*rand()*1.0/RAND_MAX) - 1.0;
        
        //environmental population calculation
        P_environmental = (1 + r - E) * P_year_before;
        P_year_before = P_environmental;
        t++;
    }
    
    //if environmental population negative, it is 0 instead
    if (P_environmental < 0)
        P_environmental = 0;
    
    //if "random" is 0, return deterministic population; if not 0, return environmental population.
    if (random == 0){
        return P_deterministic;
    }
    else return P_environmental;
    
}

//extinction function
bool extinction (double birth_rate, double death_rate) {
    
    //call growth rate function for r; in deterministic model, if r is negative, extinction possible; if r is positive, extinction is not possible
    double r = growth_rate (birth_rate, death_rate);
    
    if (r < 0)
       return true;
    
    else return false;
}

//extinction_probability function
double extinction_probability (int initial_population, int years, double birth_rate, double death_rate){
    
    //use of same variables and calling same function as in population function
    int P_year_before = initial_population;
    int t = 0;
    double P_environmental = 0;
    double r = growth_rate (birth_rate, death_rate);
    
    //used to calculate probability of extinction
    double probability = 0;
    double number_of_extinctions = 0;
    
    //calculate the environmental population 100 times in order to find probability
    for (int i = 0; i < 100; i++)
    {
        //same calculation as in population function for environmental population
        for (t = 0; t <= years; t++)
        {
            double E = ((2.0)*rand()*1.0/RAND_MAX) - 1.0;
            P_environmental = (1 + r - E) * P_year_before;
            P_year_before = P_environmental;
        }
        
        //extinction counter
        if (P_environmental == 0)
            number_of_extinctions = number_of_extinctions + 1;
        
        //reset population of year before
        P_year_before = initial_population;
    }
   
    //extinction probability calculation
    probability = number_of_extinctions/100.0;
    
    return probability;
}


