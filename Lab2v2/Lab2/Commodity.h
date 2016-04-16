//
// Created by alex on 16-4-14.
//

#ifndef LAB2_COMMODITY_H
#define LAB2_COMMODITY_H

#include "iostream"
using namespace std;

class Commodity{
protected:
    string name;
    double price;
    string productDate;
    int shelfLife;
    int discount;
public:
    Commodity(){}
    Commodity(string name, double price, string productDate, int shelfLife, int discount = 1):name(name),
    price(price), productDate(productDate), shelfLife(shelfLife), discount(discount){}

    const string &getName() const {
        return name;
    }

/*
     * getter, and no setter, once the commodity produced, its attributes can't be modified;
     */


    double getPrice() const {
        return price;
    }

    const string &getProductDate() const {
        return productDate;
    }

    int getShelfLife() const {
        return shelfLife;
    }

    void reduceLife(){
        shelfLife --;
    }

    void setDiscount(int discount) {
        Commodity::discount = discount;
    }
};

class Milk:public Commodity{
public:
    Milk(string productDate):Commodity("milk",5.5, productDate,7){}
};

class Yogurt : public Commodity {
public:
    Yogurt(string productDate):Commodity("yogurt",5.9,productDate,10){}
};

class Lunch:public Commodity{
public:
    Lunch(string productDate):Commodity("lunch",11.8,productDate,2){}
};

class Bread : public Commodity {
public:
    Bread(string productDate):Commodity("bread",4.5,productDate,3){}
};

class Sausage : public Commodity {
public:
    Sausage(string productDate):Commodity("sausage",3,productDate,1){}
};

class Oden : public Commodity {
public:
    Oden(string productDate):Commodity("oden",6,productDate,1){}
};

class Bun : public Commodity {
public:
    Bun(string productDate):Commodity("bun",2,productDate,1){}
};

class Fruit : public Commodity {
public:
    // there is something strange about shelfLife, in purchase.txt the shelfLife is not a fixed value;
    Fruit(string productDate):Commodity("fruit",4.2,productDate,1){}
};
#endif //LAB2_COMMODITY_H
