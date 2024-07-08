#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include "ll.h"
#include "stack.h"
using namespace std;

void menu(const std::string& filename) {
    std::ifstream inputFile(filename); // Open the file

    // Check if the file was opened successfully
    if (!inputFile) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return; // Exit the function
    }

    std::string line;
    // Read the file line by line and print to the console
    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl;
    }

    inputFile.close(); // Close the file
}


int main ()
{
    string name;
    char gender;
    int weight, age, height;
    std::string filename = "menu1.txt";
    cout << "         -Menu-" << endl;
    
    menu(filename);
    cout << endl;

    LL person;
 
    for (int i = 0; i < 3;i++){
 
        cout << "Name:" << endl;
        cin >> name;
        cout << "Gender:" << endl;
        cin >> gender;
        cout << "Age:" << endl;
        cin >> age;
        cout << "Height:" << endl;
        cin >> height;
        cout << "weight:" << endl;
        cin >> weight;
        cout << endl;
        person.insert(name,gender,age,height,weight);
    }
    person.print_list();




    return 0;
}

