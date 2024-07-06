#ifndef stack_h
#define stack_h
#include "Node_stack.h"
#include <cstring>
using namespace std;

class Stack{
    private:
        NodePtr top;
        int size;
    public:
        Stack();
        void push(int);
        void print_list();
        int pop();
        int get_size();
        ~Stack();
};

Stack::Stack(){
    top = NULL;
    size = 0;
}

void Stack::push(int x){    
    // cout << "pushing " << x << endl;
    NodePtr new_node = new NODE(x);

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
    NodePtr temp_ptr = top;
    for(int i=0; i<size; i++){
        temp_ptr -> print();
        cout << " ";
        temp_ptr = temp_ptr -> get_next(); // This line seems to be source of the error
    }
    cout << endl;
}

void Stack::print_size(){
    cout << size;
}

int Stack::pop(){
    // cout << "pop: ";
    int value = 0;
    if(size > 0){
        NodePtr temp = top;
        value = temp -> get_value();
        top = temp -> get_next();
        delete temp;

        size--;
        // print_list();
    }
    else{
        cout << "Unable to pop, stack empty\n";
    }
    return value;
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