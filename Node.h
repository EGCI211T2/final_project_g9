#include <iomanip>
#include <string>

class Node{
  private:
    string name;
    char gender;
    int age;
    int weight;

    Node *nextPtr;

  public:
    Node(String name_input, char gender_input, int age_input, int weight_input);
    
    Node* get_next();
    void set_next(Node* t);

    void set_age();
    void set_weight();
    void set_gender();
    
    string get_name();
    int get_age();
    int get_weight();
    char get_gender();

    ~Node();
};

typedef Node *NodePtr; // synonym for Node*

Node::Node(String name_input, char gender_input, int age_input, int weight_input){
    nextPtr = NULL;

    name = given_name;
    gender = gender_input;
    age = age_input;
    weight = weight_input;
}