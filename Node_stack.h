#include <string>
#ifndef node_h
#define node_h

class NODE{
    private:
        string data_string; // food name
        int data_int; // calories
        NODE *nextPtr;
        
    public:
        NODE(string, int);
        ~NODE();
        void set_next(NODE*);
        void print();
        NODE* get_next();
        int get_data_int();
        string get_data_string();
        
};

typedef NODE* NodePtr_stack;

NODE::NODE(string a, int b){
    data_string = a;
    data_int = b;
    nextPtr = NULL;
}
NODE* NODE::get_next(){
    return nextPtr;
}


int NODE::get_data_int(){
    return data_int;
}

string NODE::get_data_string(){
    return data_string;
}

void NODE::set_next(NODE *t){
    nextPtr = t;
}
void NODE::print(){
    cout << data_string << ", " << data_int << " kcal" << endl;
}

NODE::~NODE(){
    cout<< data_string <<" have been eaten "<< endl;
}


#endif