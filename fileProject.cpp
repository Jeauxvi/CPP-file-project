#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream cTempFS("CelsiusTemperature.text"); // creates and opens new file
    ifstream tempFS("FahrenheitTemperature.txt"); //openes exsisting file
    string countries;
    int fahrenheit;
    double celsius;

    cout << "Opening FahrenheitTemperature.txt\n";
    cout << "*********************************\n";
    //check if file is open
    if (!tempFS.is_open()) {
      cout << "Could not open file FahrenheitTemperature.txt." << endl;
      return 1; // sends error if file fails to open
   }
    tempFS >> countries; //saves strings from file to country variable
    tempFS >> fahrenheit; // saves int values from file to fahrenheit variable


    while (!tempFS.fail()){ //loops through file to completion
        cout << "Fahrenheit: " << countries << " " << fahrenheit << endl; //output from orgional file
        celsius = (fahrenheit - 32.0) * (5.0/9.0); // convert fahrenheit to celsius
        cout << "Celsius: " << countries << " " << fixed << setprecision(2) << celsius << endl; //output countries with new values
        cout << "************************\n"; //organize output

        cTempFS << countries << " " << fixed << setprecision(2) << celsius << endl; //saves to new file and formatting floting points to 2 decimals

        tempFS >> countries;  //iterates to next string
        tempFS >> fahrenheit; //iterates to next int
    }


    // close files
    tempFS.close(); 
    cTempFS.close();


    return 0;
}