#include "DoublyList.hpp"
#include <string>
#include <iostream>
using namespace std;

int main() {
    // Create list of strings
    DoublyList<string> slist;
    slist.append("Apple");
    slist.append("Banana");
    slist.append("Cherry");
    cout << "Initial string list: " << slist;

    // Insert
    slist.insert(1, "Mango");
    cout << "After inserting Mango at pos 1: " << slist;

    // Remove
    slist.remove(2);
    cout << "After removing element at pos 2: " << slist;

    // Replace
    slist.replace(1, "Grape");
    cout << "After replacing element at pos 1 with Grape: " << slist;

    // Search
    cout << "Searching for Cherry: " << (slist.search("Cherry") ? "Found" : "Not Found") << endl;
    cout << "Searching for Mango: " << (slist.search("Mango") ? "Found" : "Not Found") << endl;

    // Get element
    cout << "Element at pos 1: " << slist.getElement(1) << endl;

    // Length check
    cout << "Length of string list: " << slist.getLength() << endl;

    // Test with integers
    DoublyList<int> ilist;
    ilist.append(10);
    ilist.append(20);
    ilist.append(30);
    ilist.insert(1, 15);
    ilist.replace(2, 25);
    cout << "Integer list: " << ilist;
    cout << "Search for 25: " << (ilist.search(25) ? "Found" : "Not Found") << endl;

    return 0;
}
