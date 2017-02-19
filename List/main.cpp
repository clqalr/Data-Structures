#include <iostream>
#include "list.h"
using namespace std;

int main()
{
    List<int> list;
    List<int> list2;
    list.insert(0, 3);
    list.insert(0, 4);
    list.insert(1, 9);
    list2 = list; // testing assignment operator
    list.display();
    list2.display();
    List<int> list3(list2); // copy constructor
    list3.display();
    return 0;
}
