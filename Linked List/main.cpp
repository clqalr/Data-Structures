#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    List<int> linkedList;
    linkedList.pushFront(1);
    linkedList.pushFront(2);
    linkedList.pushFront(3);
    // 3
    // 2
    // 1
    linkedList.display();

    List<int> linkedList2(linkedList); // testing copy constructor
    cout << endl;
    linkedList2.display();

    List<int> linkedList3;
    List<int> linkedList4;
    linkedList3.pushFront(4);
    linkedList3.pushFront(5);
    linkedList3.pushFront(6);
    linkedList4 = linkedList3; // testing assignment operator
    cout << endl;
    linkedList4.display();

    return 0;
}
