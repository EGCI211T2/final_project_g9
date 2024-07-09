#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "ll.h"
#include "stack.h"
#include <iomanip>
using namespace std;



void displayMenu(const vector<string>& menuItems) {
    cout << "         -Menu-" << endl;
    for (size_t i = 1; i < menuItems.size(); ++i) {
        cout  << menuItems[i] << endl;
    }
}

vector<string> loadMenu(const string& filename) {
    ifstream inputFile(filename); // Open the file

    // Check if the file was opened successfully
    if (!inputFile) {
        cerr << "Unable to open file " << filename << endl;
        return {}; // Return empty vector
    }

    vector<string> menuItems;
    string line;
    // Read the file line by line and add to the menuItems vector
    while (getline(inputFile, line)) {
        menuItems.push_back(line);
    }

    inputFile.close(); // Close the file
    return menuItems;
}

double calculateBMR(char gender, double weight, double height, int age) {
    double bmr;
    if (gender == 'M'|| gender == 'm') {
        bmr = 88.362 + (13.397 * weight) + (4.799 * height) - (5.677 * age);
    } else if (gender == 'F'|| gender == 'f') {
        bmr = 447.593 + (9.247 * weight) + (3.098 * height) - (4.330 * age);
    } else {
        //cout << "Invalid gender input." << endl;
        //return -1;
    }
     return bmr;
} 

int main() {
    string name;
    char gender;
    int age;
    double weight, height;
    
    string filename = "menu1.txt";
    string cal = "menu.txt";
    
    vector<string> menuItems = loadMenu(filename);
    vector<string> menuwithcal = loadMenu(cal);

    if (menuItems.empty() && menuwithcal.empty()) {
        return 1; // Exit if menu loading failed
    }

    displayMenu(menuItems);
    cout << endl;
    // displayMenu(menuwithcal);

    LL person;
    Stack foodChoices;

    for (int i = 0; i < 2; i++) {
        cout << "Name:" << endl;
        cin >> name;
        cout << "Gender (M/F):" << endl;
        cin >> gender;
        cout << "Age:" << endl;
        cin >> age;
        cout << "Height (cm):" << endl;
        cin >> height;
        cout << "Weight (kg):" << endl;
        cin >> weight;
        cout << endl;
        person.insert(name, gender, age, height, weight);

        double bmr = calculateBMR(gender, weight, height, age);
        cout << "BMR: " << fixed << setprecision(2)<< bmr << " calories/day" << endl;

        int choice;
        cout << "Choose a food item from the menu (enter the number):" << endl;
        cin >> choice;

        if (choice > 0 && choice <= menuwithcal.size()) {
            foodChoices.push(menuwithcal[choice - 0]);
        } else {
            cout << "Invalid choice, skipping food selection." << endl;
        }
    }
    person.print_list();
    
    cout << "Food choices:" << endl;
    while (!foodChoices.isEmpty()) {
        cout << foodChoices.topElement() << endl;
        foodChoices.pop();
    }

    return 0;
}