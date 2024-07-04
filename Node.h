#include <iostream>
#include <string>

using namespace std;

class Node{
    private:
        string name;
        char gender;
        int age;
        int weight;

        Node* nextPtr;

    public:
        Node(string name_input, char gender_input, int age_input, int weight_input); // Correct 'string' to lowercase
        
        Node* get_next();
        void set_next(Node* t);

        void set_age(int age_input);
        void set_weight(int weight_input);
        void set_gender(char gender_input);
        
        string get_name();
        int get_age();
        int get_weight();
        char get_gender();

        ~Node();
};

typedef Node* NodePtr; // synonym for Node*

Node::Node(string name_input, char gender_input, int age_input, int weight_input) {
    nextPtr = NULL;

    name = name_input;
    gender = gender_input;
    age = age_input;
    weight = weight_input;
}

Node* Node::get_next() {
    return nextPtr;
}

void Node::set_next(Node* t) {
    nextPtr = t;
}

void Node::set_age(int age_input) {
    age = age_input;
}

void Node::set_weight(int weight_input) {
    weight = weight_input;
}

void Node::set_gender(char gender_input) {
    gender = gender_input;
}

string Node::get_name() {
    return name;
}

int Node::get_age() {
    return age;
}

int Node::get_weight() {
    return weight;
}

char Node::get_gender() {
    return gender;
}

Node::~Node() {
    // Destructor
}