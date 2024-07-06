#include <iostream>
#include <string>
#include <iostream>
#include "ll.h"
#include "stack.h"
using namespace std;

int main ()
{
    LL list;
    list.insert("Alice", 'F', 30, 65);
    list.insert("Bob", 'M', 25, 80);
    list.insert("Charlie", 'M', 35, 70);

    list.print_list();


    return 0;
}