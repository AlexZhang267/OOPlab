//
// Created by alex on 16-4-14.
//
#include <sstream>
#include "iostream"
#include "fstream"
#include "FamilyMart.h"

using namespace std;

void FamilyMart::product(string date) {
    ifstream infile("purchase.txt");
    string entry;
    getline(infile, entry);

    int index;
    string name;
    string tmp;
    double price;
    int life;
    string productDate;
    std::stringstream ss;

    bool hasInput = false;

    while (getline(infile, entry)) {
        // parse Commodity name
        index = entry.find("\t");
        name = entry.substr(0, index);

        //patse price
        entry = entry.substr(index + 1, entry.size());
        index = entry.find("\t");
        ss << entry.substr(0, index);
        ss >> price;

        //parse life
        entry = entry.substr(index + 1, entry.size());
        index = entry.find("\t");
        tmp = entry.substr(0, index);
        ss << tmp;
        ss >> life;

        //parse productDate
        productDate = entry.substr(index + 1, entry.size());


        if (productDate == date) {
//            setNoCommodityDay(0);
            hasInput = true;
            if (name == "milk") {
                Milk milk(productDate);
                FamilyMart::commodityVector.push_back(milk);
            } else if (name == "yogurt") {
                Yogurt yogurt(productDate);
                FamilyMart::commodityVector.push_back(yogurt);
            } else if (name == "lunch") {
                Lunch lunch(productDate);
                FamilyMart::commodityVector.push_back(lunch);
            } else if (name == "bread") {
                Bread bread(productDate);
                FamilyMart::commodityVector.push_back(bread);
            } else if (name == "sausage") {
                Sausage sausage(productDate);
                FamilyMart::commodityVector.push_back(sausage);
            } else if (name == "oden") {
                Oden oden(productDate);
                FamilyMart::commodityVector.push_back(oden);
            } else if (name == "bun") {
                Bun bun(productDate);
                FamilyMart::commodityVector.push_back(bun);
            } else if (name == "fruit") {
                Fruit fruit(productDate);
                FamilyMart::commodityVector.push_back(fruit);
            }

        }
    }

    if(!hasInput){
        addNoCommodityDay();
    }

    cout << "We now have these commodity.=============================================" << endl;
    for (int i = 0; i < commodityVector.size(); ++i) {
        cout << commodityVector[i].getName() << "   (produced at " << commodityVector[i].getProductDate() << ")" <<
        endl;
    }
    cout << "=========================================================================" << endl;

}

bool FamilyMart::handlePurchase(string commodity, double discount) {


    for (int i = 0; i < commodityVector.size(); ++i) {
        if (commodityVector[i].getName() == commodity) {
            std::vector<Commodity>::iterator it = commodityVector.begin() + i;
            cout << "You buy a " << commodityVector[i].getName() << " with a discount "
            << discount << ", so " << commodityVector[i].getPrice() * discount << ", please" << endl;
            moneyAdd(commodityVector[i].getPrice() * discount);
            commodityVector.erase(it);
            return false;
        }
    }
    cout << "Sorry, " << commodity << " is not available" << endl;
    return false;
}


void FamilyMart::reduceLife() {
    for (int i = 0; i < commodityVector.size(); ++i) {
        commodityVector[i].reduceLife();
        cout << commodityVector[i].getName() << commodityVector[i].getProductDate() << endl;
    }

    for (int i = 0; i < commodityVector.size(); ++i) {
        if (commodityVector[i].getShelfLife() == 0) {
            std::vector<Commodity>::iterator it = commodityVector.begin() + (i);
            cout << commodityVector[i].getName() << " is expired." << endl;
            commodityVector.erase(it);
            i--;
        }
    }
}

void FamilyMart::moneyAdd(double d) {
    money += d;
}