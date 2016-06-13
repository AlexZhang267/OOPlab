/*************************************************************************
	> File Name: run.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年06月12日 星期日 09时57分22秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include"Bignum.h"
#include"func.cpp"
using namespace std;

int find_ope(const string& str);
string trim(string& str);
Bignum operate(Bignum& b1, Bignum& b2, char o);


int main(){
    char buff[256];
    ifstream is("sample.in");
    ofstream os("result.txt");
    if(!is.is_open()){
        cout << "ERROR: open sample.in" << endl;
        return -1;
    }
    while(!is.eof()){
        is.getline(buff,250);
        string str = buff;

        Bignum num1;
        Bignum num2;
        Bignum num3;

        /*
         * construct the operand according to the input line
         */
        char o1 = '0';
        char o2 = '0';
        int index1 = find_ope(str);
        o1 = str[index1];
        string operand1 = str.substr(0,index1);
        str = str.substr(index1 + 1,str.length() - index1 - 1);

        int index2 = find_ope(str);
        if(index2 != -1){
            o2 = str[index2];
        }

        string operand2 = str.substr(0, index2);
        string operand3 = str.substr(index2 + 1,str.length() - index2 - 1);

        operand1 = trim(operand1);
        operand2 = trim(operand2);
        operand3 = trim(operand3);

        num1 = Bignum(operand1);
        num2 = Bignum(operand2);

        Bignum res = operate(num1, num2, o1);
        if(index2 != -1){
            stringstream ss;
            ss << operand3;
            ss >> num3;
            res = operate(res, num3, o2);
        }

        /*
         * res is the final result
         * i use the overloded << to print it
         */

        //cout << "res: " << res << endl;
        os << res << endl;
    }
    os.close();
}


/*
 * find the index of operator and return index
 */
int find_ope(const string& str){
    int len = str.length();
    for(int i = 0; i < len; i++){
        switch(str[i]){
            case '+':
                return i;
                break;
            case '-':
                return i;
                break;
            case '*':
                return i;
                break;
            case '/':
                return i;
                break;
        }
    }
    return -1;
}

/*
 *remove spaces in the input string
 */
string trim(string& str){
    int len = str.length();
    string res;
    for (int i = 0; i < len; i++){
        if(str[i] != ' '){
            res += str[i];
        }
    }
    return res;
}

/*
 *use two operands (b1 b2) and a operator to calculate the result
 */
Bignum operate(Bignum& b1, Bignum& b2, char o){
    
    switch(o){
        case '+':
            return (b1 + b2);
            break;
        case '-':
            return (b1 - b2);
            break;
        case '*':
            return (b1 * b2);
            break;
        case '/':
            return (b1 / b2);
            break;
    }
    // if the operator is not valid, return a 0 bignum
    return Bignum();
}
