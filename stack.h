#ifndef stack_h
#define stack_h
#include "Node_stack.h"
#include <string>
#include <iostream>
using namespace std;

class Stack {
    private:
        NodePtr_stack top;
        int size;
        
    public:
        Stack() : top(nullptr), size(0) {}
        void push(const std::string &item, string cal);
        void print_list();
        void pop();
        string topElement();
        void printStack();
        void clearStack();
        int get_size();
        int get_total_calories();
        bool isEmpty(); 
        ~Stack();
        
};

// Stack::Stack() {
//     top = nullptr;
//     size = 0;
// }

void Stack::push(const std::string &item, string cal) {
    NodePtr_stack new_node = new NODE(item, stoi(cal));
    new_node->set_next(top);
    top = new_node;
    size++;  // Increment size
}

void Stack::print_list() {
    NodePtr_stack temp_ptr = top;
    for(int i = 0; i < size; i++) {
        temp_ptr->print();
        cout << " ";
        temp_ptr = temp_ptr->get_next();
    }
    cout << endl;
}

void Stack::pop() {
    if(top != nullptr) {
        NodePtr_stack temp = top;
        top = temp->get_next();
        delete temp;
        size--;
    } else {
        cout << "Unable to pop, stack empty" << endl;
    }
}

void Stack::printStack(){
    NodePtr_stack current = top;
    while(current != nullptr){
        current->print();
        current = current->get_next();
    }
    cout << endl;
}

void Stack::clearStack() {
    while (top != nullptr) {
        pop();
    }
    size = 0;
}

string Stack::topElement() {
    if(size > 0) {
        return top->get_data_string();
    } else {
        return "Stack is empty";
    }
}

int Stack::get_size() {
    return size;
}

int Stack::get_total_calories() {
    NodePtr_stack current = top;
    int total = 0;
    while (current != nullptr) {
        total += current->get_data_int();
        current = current->get_next();
    }
    return total;
}

bool Stack::isEmpty() {
    return size == 0;
}

Stack::~Stack() {
    cout << "Clearing the stack" << endl;
    while(top != nullptr) {
        pop();
    }
    cout << "done" << endl;
}

#endif