#include "Node_ll.h"
#include <string>
using namespace std;

class LL{
    private:
        NodePtr_ll hol; // head of linked list
        int size;

    public:
        LL();
        void insert(string name_input, char gender_input, int age_input, int weight_input);
        void remove();
        void print_list();
        ~LL();
};

LL::LL(){
    this -> hol = NULL;
    size = 0;
}

void LL::insert(string name_input, char gender_input, int age_input, int weight_input) {
    NodePtr_ll newPtr = new Node(name_input, gender_input, age_input, weight_input); // create node & put value in

    if (newPtr != nullptr) { // is space available
        NodePtr_ll currentPtr = hol;  // pointer to current node in list
        NodePtr_ll previousPtr = nullptr; // pointer to previous node in list

        // loop to find the correct location in the list
        while (currentPtr != nullptr && age_input > currentPtr->get_age()) {
            previousPtr = currentPtr;            // walk to ...
            currentPtr = currentPtr->get_next(); // ... next node        
        }

        // insert new node at beginning of list
        if (previousPtr == nullptr) {
            newPtr->set_next(hol);
            hol = newPtr;
        } else {
            previousPtr->set_next(newPtr);
            newPtr->set_next(currentPtr);
        }
        ++size;
    } else {
        cout << "Node not inserted. No memory available." << endl;
    }
}

void LL::remove() {
    // remove one node from linked list here
    if (hol != nullptr) {
        NodePtr_ll tempPtr = hol;
        hol = hol->get_next();
        delete tempPtr;
        --size;
    }
}

void LL::print_list() {
    NodePtr_ll tempPtr = hol; // Start at the head of the list

    for (int i = 0; tempPtr != nullptr; i++) {
        cout << "Person " << i + 1 << endl;
        cout << "Name: " << tempPtr->get_name() << endl;
        cout << "Gender: " << tempPtr->get_gender() << endl;
        cout << "Age: " << tempPtr->get_age() << endl;
        cout << "Weight: " << tempPtr->get_weight() << endl;

        tempPtr = tempPtr->get_next(); // Move to the next node
        cout << endl;
    }
}

LL::~LL() {
    while (hol != nullptr) {
        NodePtr_ll tempPtr = hol;
        hol = hol->get_next();
        delete tempPtr;
    }
}
