#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "ll.h"
#include "stack.h"
#include "sorting.h"
#include <iomanip>
#include <stack>

using namespace std;



void displayMenu(const vector<string>& menuItems) {
    
    cout << "         -Menu-" << endl;
    for (size_t i = 0; i < menuItems.size(); ++i) {
        cout  << menuItems[i] << endl;
    }
}

void fat()
{
    cout<<"Result: Taooooooo aounnnnnnnn!!!";cout<<endl;
    cout<<"  @@ @#  # @ @@#@@@@@@@@@@@@@@@    @@ @@  @#  @  @ #@# @ @  @@@@@@@@@@@@@@@@  &@@";cout<<endl;
    cout<<"@@@@@@@@@@@@/@@@@@@@@@@@@@@@@@@     &@@@@@@@@@@@@@@@@@@@@#@@@@@@@@@@@@@@@@@@    ";cout<<endl;
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";cout<<endl;
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@&&,&&@@@@@@@@@@@@@@@@@@&%,,,%&@@@@@@@@@@@@@@@@@@@@@@@@@@@";cout<<endl;
    cout<<"@@@@@@@@@@@@@@@@@@@@@@&,,,%,,,&@&&&&&&&&&&&&*,,&*(,,&@@@@@@@@@@@@@@@@@@@@@@@@@@@";cout<<endl;
    cout<<"@@@@@@@@@@@@@@@@@@@@@@&,,,,,,,,,,,,,,,, ,,,,,,,,,,,,&&@@@@@@@@@@@@@@@@@@@@@@@@@@";cout<<endl;
    cout<<"@@@@@@@@@@@@@@@@@@@@@@&,(*,,,,,,,,,  ,,  ,,,,,,,,,,,,&&@@@@@@@@@@@@@@@@@@@@@@@@@";cout<<endl;
    cout<<"@@@@@@@@@   @  @@@@/@&(,,,,,,,,*,,         &.%&,,,,,*,,,&  @@ @ @@@@@ @@@@@@@@@@";cout<<endl;
    cout<<"@@@@@@@@  , @  @@, @%*,,*,,,,&/%%&         &&&/,,,,,*,,,,,%@@@ @  @     /@   ,/ ";cout<<endl;
    cout<<"@@@@@@@@@@@ /@@@@@&&*,,,,,,,,                    *,,,/*,,* &@@@@@@@@@@@@@@@@@@@@";cout<<endl;
    cout<<"@@@@@@@@@@@@@@@@@@&,,,**,,,      %.  .*,&,,*%(    ,,,,,,,,  &@@@@@@@@@@@@@@@@@@@";cout<<endl;
    cout<<"@@@@@@@@@@@@@@@@@&&. ,,,,            .,,,             *     &&&@@@@@@@@@@@@@@@@@";cout<<endl;
    cout<<"@@@@@@@@@@@@@@@&//*,                                      ,,,,,&&@@@@@@@@@@@@@@@";cout<<endl;
    cout<<"@@@@@@@@@@@@@&&/*****      ,,                  ,,       .,,,,,,,#&@@@@@@@@@@@@@@";cout<<endl;
    cout<<"@@@@@@@@@@@@&//*********      .,,,,,,,,,,,,,,.        ,,,,  ,,,,,*&@@@@@@@@@@   ";cout<<endl;
    cout<<"  / @  @ & %%//*******,                 ..    .       ****,*,,,,,,&&@@@@@@@  ,@@";cout<<endl;
    cout<<"@@@@@@@@@@@&//**********&,,       .               .,/,***,*,,,,,,,,&@@@@@@@  @@"; cout<<endl;
    cout<<"@@@@@@@@@@&////************&,                   ,&,,,,,,,,,,,*,,,,,,&@@@@@@@@@@@";cout<<endl;
    cout<<"@@@@@@@@@&//////(/************,                 ,&,,,,,,,,/(/,,,,,,,&&@@@@@@@@@@";cout<<endl;
    cout<<"@@@@@@@@&&////////%//******/*&,                 ,/&/&//&&//,,,,,,  ,*&@@@@@@@@@@";cout<<endl;
    cout<<"@@@@@@@@&***,,,/////,*&(//(&&,,                   ,,,,,.           //&@@@@@@@@@@";cout<<endl;
    cout<<"@@@@@@@@&&(/,,,,,,,,,,,,,,,,,.......       ..      ......     *****/&&@@@@@@@@@@";cout<<endl;
    cout<<"@@@@@@@@&&////*,,,,,,,................................     ********/&@@@@@@@@@@@";cout<<endl;
    cout<<"@@@@@@@@ &**,*,*,,,,,,... . .........................  . . ..... .,,& @  @  @ @ ";cout<<endl;
    cout<<"@@@@@@@@@&***,,,,,,,,,,,..............................    ........,&/*&&@@@@@@@@";cout<<endl;
    cout<<"@@@@@@@@@@&(((,,,,,,,,,,,,....................................***/&&**,*&@@@@@@@";cout<<endl;
    cout<<"@@@@@@@@@@@&(((////,,,,,,,,,,,..................,,,,,,,,,,,,///((&((,**,&@@@@@@@";cout<<endl;
    cout<<"@@@@@@@@@@@@&&***,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,**&&*((/**&@@@@@@@@";cout<<endl;
    cout<<"@@@@@@@@@@@@@@&&****,,#&&&,,,,,,,,,,,,,,,,,,,,,,,,**&&&&/****&&#*/#(&&@@@@@@@@@@";cout<<endl;
    cout<<"@@@@@@@@@@@@@@@@@@&&((((####&****/*,,,,,,,,,*****%####&#&#&&&&&&&&@@@@@@@@@@@@@@";cout<<endl;
    cout<<"@@@ @@@@@@@@@@@@@@@@@@@&&&&@@@@ %    @@ @,@@@@@ @@@@@@@@@@@@@@@@@@@@@@@@@@@ & @@";cout<<endl;
    cout<<"* @    @ (  @ @@@@@@@@@@@@@@@@%   &  @@@ @  @ /. . @    @ @@@@@@@@@@@@@@@@@  @  ";cout<<endl;
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

void choices(int a, const vector<string>& menuItems, const vector<string>& calItems, Stack* food) {
    if (a > 0 && a <= menuItems.size()) {
        food->push(menuItems[a - 1], calItems[a - 1]);
    } else {
        cout << "Invalid choice, skipping food selection." << endl;
    }
}

int main() {
    struct PersonBMR {
        string name;
        double bmr_differences;
    };

    int amount_user;
    do{
    cout << "amount user : ";
    cin >> amount_user;
    cout << endl;
    }while(amount_user<0);

    string name[amount_user];
    char gender;
    int age;
    double bmr[amount_user];
    int eaten_cal[amount_user]; // array to track how much calories have been eaten by each user DONT DELETE PLS
    double subtracted_bmr[amount_user];
    double bmr_differences[amount_user];
    double weight, height;

    string filename = "menu1.txt";
    string menuonly = "food.txt";
    string calonly = "cal.txt";

    vector<string> menuItems = loadMenu(filename);
    vector<string> menu = loadMenu(menuonly);
    vector<string> calmenu = loadMenu(calonly);

    if (menuItems.empty() && menu.empty() && calmenu.empty()) {
        return 1; // Exit if menu loading failed
    }

    LL person;
    Stack* foodChoices = new Stack();

    for (int i = 0; i < amount_user; i++) {
        displayMenu(menuItems);
        cout << endl;

        cout << "Name: (user " << i + 1 << name[i] << ")" << endl;
        for (int j = i; j < i + 1; j++) {
            cout << "Name " << i + 1 << " :" << " ";
            cin >> name[i];
        }

        do {
            fflush(stdin);
            cout << "Gender (M/F):" ;
            cin >> gender;
            if (gender == 'm' || gender == 'M' || gender == 'f' || gender == 'F') break;
        } while (gender != 'm' || gender != 'M' || gender != 'f' || gender != 'F');

        cout << "Age:" ;
        cin >> age;
        cout << "Height (cm):" ;
        cin >> height;
        cout << "Weight (kg):" ;
        cin >> weight;
        cout << endl;

        person.insert(name[i], gender, age, height, weight);

        bmr[i] = calculateBMR(gender, weight, height, age);
        if(bmr[i]== -1) continue;
        cout << "BMR: " << fixed << setprecision(2) << bmr[i] << " calories/day" << endl;

        vector<int> vec(5);
        cout << "Choose 5 foods from the menu (enter the number):" << endl;
        for (int o = 0; o < 5; o++) {
            cin >> vec[o];
        }

        for (int o : vec) {
            choices(o, menu, calmenu, foodChoices);
        }

        cout << endl;
        subtracted_bmr[i] = bmr[i] - (foodChoices->get_total_calories());
        //subtracted_bmr[i] = subtracted_bmr[i] * -1;

        eaten_cal[i] = foodChoices->get_total_calories(); // store total calories for each user, printed after sorting
        cout << "BMR  = " << bmr[i] << " - Food calories = " << foodChoices->get_total_calories() << endl;
        cout << "Calories left = " << bmr[i] - foodChoices->get_total_calories() << endl;
       
        if(bmr[i] - foodChoices->get_total_calories()<0)
        {
            fat();
        }
        else if(bmr[i] - foodChoices->get_total_calories()>0&&bmr[i] - foodChoices->get_total_calories()<300) cout<<" Balance ";
        else cout<< "Result : lack of nutrition";
        cout << endl << "Food choices:" << endl;
        foodChoices->printStack();
        foodChoices->clearStack();

        // for (int k = 0; k < amount_user; k++) {
        //     cout << subtracted_bmr[k];
            
        // }

        bmr_differences[amount_user];

        for (int j = 0; j < amount_user; ++j) {
            bmr_differences[j] = subtracted_bmr[j];
            // bmr_differences[j] = subtracted_bmr[j]*-1;
            // if (bmr_differences[j] < 0) ; 
            //else  cout<< "You did not eat excessively";break;

        }
        bmr_differences[i] = subtracted_bmr[i];
    }
    cout<<endl;
    person.print_list();

     
     /*for(int i=0;i<amount_user;i++)
    {
        //PersonBMR bmr_array[i]={name[i+1], subtracted_bmr[i+1]};
        //bmr_differences[i] = bmr_array[i].bmr_differences;
          bmr_differences[i] = subtracted_bmr[i];
    };*/


    bubbleSort(bmr_differences, amount_user);
    /*
    cout << "Sorted BMR: "<<endl;

    for (int i = 0; i < amount_user; i++) {
        cout << "User " << i+1 << ", " << name[i] << ": " << "BMR (" << bmr[i] << ") - Eaten Calories (" << eaten_cal[i] << ") = ";
        
        cout << fixed << setprecision(2) << bmr_differences[i] << endl;
    }
    */
    cout << "Sorted Subtracted BMRs: "<<endl;

    for (int i = 0; i < amount_user; i++) {
        cout << i+1 << ". " << name[i] << ": " << "BMR (" << bmr[i] << ") - Eaten Calories (" << eaten_cal[i] << ") = ";
        
        cout << fixed << setprecision(2) << bmr_differences[i] << endl;
    }


    delete foodChoices;

    return 0;
}