#include <iostream>
#include <sstream>
#include "FamilyMart.h"
#include "Customer.h"

using namespace std;

void updateDate(string &date) {
    int index = date.find("/");;
    string year = date.substr(0, index);
    date = date.substr(index + 1, date.size());
    index = date.find("/");
    string sMonth = date.substr(0, index);
    string sDay = date.substr(index + 1, date.size());
    int iDay;
    int iMonth;
    std::stringstream ss;
    ss << sDay;
    ss >> iDay;

    iDay++;


    if (iDay > 30) {
        iDay %= 30;
        ss.str("");
        ss.clear();
        ss << sMonth;
        ss >> iMonth;
        iMonth++;
        ss.str("");
        ss.clear();
        ss << iMonth;
        ss >> sMonth;
    }

    ss.str("");
    ss.clear();

    ss << iDay;
    ss >> sDay;

    date = year + "/" + sMonth + "/" + sDay;

}


int main() {
    string date = "2016/4/23";
    string input;
    cout << "Welcom to this program, N for exit, any key for go on" << endl;
    cin >> input;
    FamilyMart familyMart;

    cout << "FamilyMart Open"<< endl;

    while (input != "N") {
        cout << "today is " << date << endl;
        if (familyMart.getNoCommodityDay() == 3) {
            cout << "FamilyMart is closed" << endl;
            return 0;
        }

        familyMart.product(date);
        Customer::purchase(familyMart);
        cout << "The FamilyMart has earned " << familyMart.getMoney() << endl;
        cin >> input;
        updateDate(date);
        familyMart.reduceLife();
    }

    return 0;
}

