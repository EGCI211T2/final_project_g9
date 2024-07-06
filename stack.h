#ifndef stack_h
#define stack_h
#include "Node_stack.h"
#include <string>
#include <iostream>
using namespace std;

class Stack{
    private:
        NodePtr_stack top;
        int size;
    public:
        Stack();
        void push(string, int);
        void print_list();
        void pop();
        int get_size();
        ~Stack();
};

Stack::Stack(){
    top = NULL;
    size = 0;
}

void Stack::push(string a, int b){
    // cout << "pushing " << x << endl;
    NodePtr_stack new_node = new NODE(a, b);

    if(new_node){
        new_node -> set_next(top); // First in, last out
        top = new_node;
        size++;

        // cout << "new node with value ";
        // new_node->print();
        // cout << "\n";
    }
    else{cout << "Out of memory, unable to push.";}
}

void Stack::print_list(){
    NodePtr_stack temp_ptr = top;
    for(int i=0; i<size; i++){
        temp_ptr -> print();
        cout << " ";
        temp_ptr = temp_ptr -> get_next(); // This line seems to be source of the error
    }
    cout << endl;
}

void Stack::pop(){ // since one node in the stack holds two values, this pop func will need to return both int and string,
                  // but we can't do that for now, so just don't return anything here
    // cout << "pop: ";
    if(size > 0){
        NodePtr_stack temp = top;
        top = temp -> get_next();
        delete temp;

        size--;
        // print_list();
    }
    else{
        cout << "Unable to pop, stack empty\n";
    }
}

int Stack::get_size(){
    return size;
}

Stack::~Stack(){
    cout << "Clearing the stack\n";
    int iterator = 0;
    
    while(top != nullptr){
        pop();
        iterator++;
    }
    // cout << "done\n";
}


#endif