/*************************************************************************
	> File Name: Bignum.h
	> Author: 
	> Mail: 
	> Created Time: 2016年06月11日 星期六 09时47分22秒
 ************************************************************************/

#ifndef _BIGNUM_H
#define _BIGNUM_H
#include <iostream>
#include <string>
#include "istream"
using namespace std;

class Bignum{
public:
    string num;
    Bignum(string& n):num(n){}

    friend const Bignum operator+(const Bignum& left, const Bignum& right);
    friend const Bignum operator-(const Bignum& left, const Bignum& right);
    friend const Bignum operator*(const Bignum& left, const Bignum& right);
    friend const Bignum operator/(const Bignum& left, const Bignum& right);
    friend istream& operator>>(istream& is, Bignum& bn);
    friend ostream& operator<<(ostream& os, const Bignum& bn);
}; 
#endif
