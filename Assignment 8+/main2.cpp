#include <iostream>
#include <string>
#include <fstream>
#include "pride.hpp"

using namespace std;

int main()
{
    DoublyLinkedList<string> DLL;
    DLL.insert("ge");
    DLL.insert("ge");
    DLL.insert("gg");
    DLL.print();
    DLL.searchDelete("ge");
    DLL.print();
    DLL.searchDelete("gg");
    DLL.print();

    std::cout << "Done" << std::endl;
    DLL.backwardsPrint();
    readData(DLL);

    std::cout << "FORWARD" << std::endl;
    DLL.print();

    cout << "\n\n";
    
    std::cout << "BACKWARD" << std::endl;
    DLL.backwardsPrint();
    
    
    cout << "\nPride is for everyone." << endl;
    return 0;
}
