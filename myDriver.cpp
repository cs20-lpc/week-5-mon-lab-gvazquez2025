#include "DoublyList.hpp"
#include <string>
#include <iostream>
using namespace std;

int main() {
    // Test with integers
    DoublyList<int> intList;
    intList.append(10);
    intList.append(20);
    intList.append(30);
    cout << "Initial int list: " << intList;

    intList.insert(1, 15);
    cout << "After insert at position 1: " << intList;

    intList.remove(2);
    cout << "After removing position 2: " << intList;

    intList.replace(1, 99);
    cout << "After replacing position 1 with 99: " << intList;

    cout << "Search for 99: " << (intList.search(99) ? "found" : "not found") << endl;
    cout << "Length of intList: " << intList.getLength() << endl;

    // Test with strings
    DoublyList<string> strList;
    strList.append("Alpha");
    strList.append("Beta");
    strList.append("Gamma");
    cout << "\nInitial string list: " << strList;

    strList.insert(0, "Start");
    strList.insert(4, "End");
    cout << "After inserting at beginning and end: " << strList;

    strList.remove(2);
    cout << "After removing position 2: " << strList;

    strList.replace(2, "Delta");
    cout << "After replacing position 2 with Delta: " << strList;

    cout << "Search for Gamma: " << (strList.search("Gamma") ? "found" : "not found") << endl;
    cout << "Length of strList: " << strList.getLength() << endl;

    return 0;
}
