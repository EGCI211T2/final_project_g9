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
    int weight, age;
    std::string filename = "menu1.txt";
    cout << "Menu" << endl;
    menu(filename);
    cout << endl;

    LL person;
    // Stack food_stack;
    // food_stack.push("Pad Thai", 800);
    for (int i = 0; i < 3;i++){
 
        cout << "name" << endl;
        cin >> name;
        cout << "gender" << endl;
        cin >> gender;
        cout << "weight" << endl;
        cin >> weight;
        cout << "age" << endl;
        cin >> age;
        cout << endl;
        person.insert(name,gender,age,weight);
    }
    person.print_list();




    return 0;
}

