#include "dict.h"
#include <iostream>

using namespace std;

bool Dict::add(const word &w) {
    // Your code here
//    cout << "ADD " << size << endl;


    for (int i = 0; i < 5000; i++) {

        /*
         * Should test the  == "" means the position is unoccupied
         */
        if (dict[i].key == "") {
            dict[i].key = w.key;
            dict[i].value = w.value;
            size++;
            return true;

            /*
             * Should test the below code whether work correctly
             */
        } else if (dict[i].key == w.key) {
            dict[i].value = w.value;
            return true;
        }
    }

    cout << "This dictionary can hold 5000 words at most." << endl;

    return false;
}

string Dict::search(const string &key) {
    // Your code here
//    cout << "SEARCH" << endl;
    for (int i = 0; i < size; ++i) {
        if (dict[i].key == key){
            return dict[i].value;
        }
    }
    return "";
}

string Dict::remove(const string &key) {
    // Your code here
//    cout << "REMOVE" << endl;

    for (int i = 0; i < size; i++) {
        if (dict[i].key == key) {
            dict[i].key = dict[size - 1].key;
            dict[i].value = dict[size - 1].value;
            dict[size - 1].key = "";
            dict[size - 1].value = "";
            size--;
            break;
        }
    }

    return "";
}

string Dict::update(const word &w) {
    // Your code here
//    cout << "UPDATE" << endl;
    for (int i = 0; i < size; ++i) {
        if(dict[i].key == w.key){
            dict[i].value = w.value;
            break;
        }
    }
    return "";
}

void Dict::printDict() {
    cout << "Now the dict is:\n";
    for (int i = 0; i < size; ++i)
        cout << dict[i].key << ": " << dict[i].value << endl;
}