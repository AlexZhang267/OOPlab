//
// Created by alex on 16-4-15.
//
#include <sstream>
#include "iostream"
#include "Customer.h"
#include "FamilyMart.h"

using namespace std;


void Customer::purchase(FamilyMart &familyMart) {
//        familyMart.handlePurchase(commodity);
    ifstream infile("sell.txt");
    string entry;
    getline(infile, entry);

    int index;
    string name;
    double discount;
    std::stringstream ss;
    while (getline(infile, entry)) {
        index = entry.find("\t");
        name = entry.substr(0, index);


        if(index +1 !=entry.size()){
            ss << entry.substr(index + 1, entry.size()) << endl;;
            ss >> discount;
        }else{
            discount = 1;
        }

        bool close = familyMart.handlePurchase(name, discount);
        if(close){
            break;
        }
    }
};
