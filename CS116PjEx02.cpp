//CS116PjEx02
//20230517
//Shun Hoi Yeung
//900494756
//Section17097Spring
//Section17098Spring

// Submit the following items:
// 1. source code text file (CPP file) and Submit to Canvas
// 2. Compile, Run, and capture print screen of Visual Studio then Submit to Canvas.

// Write a program that asks the user for the speed of a vehicle (in miles per hour) 
// and how many hours it has traveled. The program should then use a loop to display the distance the vehicle 
// has traveled for each hour of that time period. Here is an example of the output:

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int distance(int speedInMile, int timeInHr);
bool positiveRecivier(int& poistiveNumber);
void displaydistanceTable(int timeInHr, int distance);

void main() {
    int mph = 0, hr = 0;

    do {
        try {
            printf("What is the speed of the vehicle in mph? ");
            positiveRecivier(mph);
        }
        catch (std::invalid_argument& e) {
            cerr << e.what() << endl;
        }
    } while (mph <= 0);
    do {
        try {
            printf("How many hours has it traveled? ");
            positiveRecivier(hr);
        }
        catch (std::invalid_argument& e) {
            cerr << e.what() << endl;
        }
    } while (hr <= 0);

    displaydistanceTable(hr, mph);

    return;
}

void displaydistanceTable(int timeInHr, int mph) {
    printf("Hour\tDistance Traveled In Miles\n");
    printf("---------------------------------------\n");

    for (int i = (timeInHr < 1) ? 0 : 1; i <= timeInHr; i++) {
        printf("%d\t%d\n", i, distance(mph, i));
    }
    printf("\n");
}

int distance(int speedInMile, int timeInHr) {
    return speedInMile * timeInHr;
}

bool positiveRecivier(int& poistiveNumber) {
    // try{
    // bool temp = (cin >> poistiveNumber);
    while ( cin >> poistiveNumber && poistiveNumber > 0) {
       return true;
    }
    // Input Validation: Do not accept a negative number for speed and do not accept any value less than I for time traveled.
    throw std::invalid_argument("input must be positive");
    //    }catch (std::invalid_argument& e){
    //            cerr << e.what() << endl;
}

