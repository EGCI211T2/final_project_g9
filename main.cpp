#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "ll.h"
#include "stack.h"
#include "sorting.h"

#include <iomanip>
using namespace std;



void displayMenu(const vector<string>& menuItems) {
    
    cout << "         -Menu-" << endl;
    for (size_t i = 0; i < menuItems.size(); ++i) {
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

void choices(int a, const vector<string>& menuItems,const vector<string>& calItems, Stack **food){
    if (a > 0 && a <= menuItems.size()) {
            (*food)->push(menuItems[a - 1], calItems[a-1]);
        } else {
            cout << "Invalid choice, skipping food selection." << endl;
        }
}

int main() {
    struct PersonBMR {
        string name;
        double bmr_difference;
    };

    int amount_user = 3; // amount of users
    string name;
    string name_one;
    string name_two;
    string name_three;

    char gender;
    int age;
    double subracted_bmr_1 = 0;
    double subracted_bmr_2 = 0;
    double subracted_bmr_3 = 0;
    double subtracted_bmr_temp = 0; // for display purposes
    double weight, height;
    
    string filename = "menu1.txt";
    string cal = "menu.txt";
    string menuonly = "food.txt";
    string calonly = "cal.txt";
    
    vector<string> menuItems = loadMenu(filename); // main menu
    vector<string> menuwithcal = loadMenu(cal); // menu with cal
    vector<string> menu = loadMenu(menuonly); // menu use for food choice
    vector<string> calmenu = loadMenu(calonly); // cal use for food choice

    if (menuItems.empty() && menuwithcal.empty() && menu.empty() && cal.empty()) {
        return 1; // Exit if menu loading failed
    }

    //displayMenu(menuItems);
    cout << endl;
    // displayMenu(menuwithcal);

    LL person;
    Stack *foodChoices = new Stack();

    for (int i = 0; i < amount_user; i++) {
        displayMenu(menuItems);
        cout<< endl;

        cout << "Name: (user " << i << ")" << endl;
        cin >> name;

        if (i == 0) {
            name_one = name;
        } else if (i == 1) {
            name_two = name;
        } else if (i == 2) {
            name_three = name;
        }
        do{
        fflush(stdin);
        cout << "Gender (M/F):" << endl;
        cin >> gender;
        if(gender=='m'||gender=='M'||gender=='f'||gender=='F') break;
        }while(gender!='m'||gender!='M'||gender!='f'||gender!='F');

      
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

        // int choice1, choice2, choice3;
        vector<int> vec(5);
        cout << "Choose 5 foods from the menu (enter the number):" << endl;
        for (int o = 0;o<5;o++) {
            cin >> vec[o];
        }
        
        //output to choice func
        for(int o : vec) {
            choices(o,menu,calmenu,&foodChoices);
        }
        cout <<endl;
        double subtracted_bmr = bmr - (foodChoices->get_total_calories());
        subtracted_bmr = subtracted_bmr *-1; // idk why subtracted_bmr is initially negative
        // cout << "Food calories - BMR = " << subtracted_bmr << endl;
         cout << "BMR  = " << bmr  << " - Food calories = " << foodChoices->get_total_calories() << endl;
         cout << "Calories left = " << bmr - foodChoices->get_total_calories() <<endl;
         
        
        cout << endl << "Food choices:" << endl;
        foodChoices->printStack();

        

        // Store the result in the appropriate variable
        if (i == 0) {
            subracted_bmr_1 = subtracted_bmr;
        } else if (i == 1) {
            subracted_bmr_2 = subtracted_bmr;
        } else if (i == 2) {
            subracted_bmr_3 = subtracted_bmr;
        }

        foodChoices->clearStack();
        // if (choice > 0 && choice <= menuwithcal.size()) {
        //     foodChoices.push(menuwithcal[choice - 0]);
        // } else {
        //     cout << "Invalid choice, skipping food selection." << endl;
        // }
    }
    person.print_list();
    
    PersonBMR bmr_array[3] = {
        {name_one, subracted_bmr_1},
        {name_two, subracted_bmr_2},
        {name_three, subracted_bmr_3}
    };

    // Extract BMR differences into a separate array
    double bmr_differences[3];

    for (int i = 0; i < 3; ++i) {
        bmr_differences[i] = bmr_array[i].bmr_difference;
    }
    
    bubbleSort(bmr_differences, amount_user);
    cout << "Sorted BMR: \n";

    for (int i = 0; i < 3; i++) {
        cout << fixed << setprecision(2);
        cout << bmr_differences[i] << endl;
    }

    delete foodChoices;
    // while (!foodChoices.isEmpty()) {
    //     cout << foodChoices.topElement() << endl;
    //     foodChoices.pop();
    // }

    return 0;
}