//
// Created by alex on 16-4-14.
//

#ifndef LAB2_FAMILYMART_H
#define LAB2_FAMILYMART_H

#include "vector"
#include "Commodity.h"
#include "iostream"
#include "fstream"

using namespace std;

class FamilyMart {
private:
    vector<Commodity> commodityVector;
    double money=0;
public:
    FamilyMart() {}

    void product(string date);///to product commodity

    const vector<Commodity> &getCommodityVector() const {
        return commodityVector;
    }

    bool handlePurchase(string commodity, double discount = 1);

    void reduceLife();

    void moneyAdd(double d);


    double getMoney() const {
        return money;
    }
};
#endif //LAB2_FAMILYMART_H
