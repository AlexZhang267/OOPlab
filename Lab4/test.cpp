/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年06月11日 星期六 10时06分22秒
 ************************************************************************/

#include <iostream>
#include <string>
#include "Bignum.h"
using namespace std;
int main(){
    string as = "123456789123456789123456789";
    string bs = "123456789123456789";
    string cs = "987654321";
    string ds = "987654321987654321";
    string es = "123456789123456789";

    Bignum a(as);
    Bignum b(bs);
    Bignum c(cs);
    Bignum d(ds);
    Bignum e(es);
    Bignum sum = a + b;
    Bignum diff = a - b;
    Bignum test = a + b - c;
    Bignum bd = b*d;
    Bignum bde = b * d / e;
    cout << sum.num << endl;
    cout << diff.num << endl;
    cout << test.num << endl;
    cout << bde.num << endl;
    cout << bde << endl;
    // cout << as << bs << endl;
}
