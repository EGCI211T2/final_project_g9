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
        Stack();
        void push(string a);
        void print_list();
        void pop();
        string topElement();
        int get_size();
        bool isEmpty(); 
        ~Stack();
        
};

Stack::Stack() {
    top = nullptr;
    size = 0;
}

void Stack::push(string a, string b) {
    NodePtr_stack new_node = new NODE(a, stoi(b));
    if(new_node) {
        new_node->set_next(top); // First in, last out
        top = new_node;
        size++;
    } else {
        cout << "Out of memory, unable to push." << endl;
    }
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
    if(size > 0) {
        NodePtr_stack temp = top;
        top = temp->get_next();
        delete temp;
        size--;
    } else {
        cout << "Unable to pop, stack empty" << endl;
    }
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