/*************************************************************************
	> File Name: func.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年06月11日 星期六 09时59分30秒
 ************************************************************************/

#include<iostream>
#include "Bignum.h"
#include <string>
#include "strstream"
#include "istream"
using namespace std;


/*
 * There are some help functions
 */
int find_max(int a, int b);

//fill max - str.length() zeros before str's beginning
string& fill_string(int num, string& str);

//reverse the string
string reverse_string(string str);

//calculate the sum between two char
char add_char(char a, char b, int& mark);

//calculate the difference of two char
char minus_char(char a, char b, int& mark);

//calculate the product of a string a char
string multiply_string_char(string str, char c);

//calculate the product of two char
char multiply_char(char a, char b, int& mark);

//calculate the quotient if two string
Bignum& divide_string(string a, string b , Bignum& res);

//convert a char to an int
int char_to_int(char c);

// compare two string number
bool is_bigger(string a, string b);

//convert an int to strng
string int_to_str(int a);


/*
 * the six overloded functions
 */
const Bignum operator+(const Bignum& left, const Bignum& right){
    
    string ls = left.num;
    string rs = right.num;
    
    int max = find_max(ls.length(), rs.length());
    
    ls = fill_string(max-ls.length(),ls);
    rs = fill_string(max-rs.length(),rs);

    ls = reverse_string(ls);
    rs = reverse_string(rs);
    
    string sum="";
    int mark = 0;
    for(int i = 0; i < max; i++){
        sum += add_char(ls[i], rs[i], mark);
    }

    if(mark != 0){
        strstream ss;
        string tmp;
        ss << mark;
        ss >> tmp;
        sum += tmp;
    }
    sum = reverse_string(sum);
    return Bignum(sum);
}

const Bignum operator-(const Bignum& left, const Bignum& right){
    string ls = left.num;
    string rs = right.num;
    
    /*
     * The left value should not smaller the right one
     */
    if (ls.length() < rs.length()){
        cout << "ls:" << ls << endl;
        cout << "rs:" << rs << endl;
        cout << "ERROR: left_value is smaller than right value"<< endl;
        string s = "-1";
        return Bignum(s);
    }

    int max = find_max(ls.length(),rs.length());

    /*
     * There is no need to fill left value
     */
    rs = fill_string(max-rs.length(),rs);

    ls = reverse_string(ls);
    rs = reverse_string(rs);

    string diff="";
    int mark = 0;

    for(int i = 0; i < max; i++){
        diff += minus_char(ls[i],rs[i],mark);
    }

    diff = reverse_string(diff);

    string res="";
    bool record = false;
    for(int i = 0; i<diff.length(); i++){
        if(!record && diff[i]!='0'){
            record = true;
        }
        if(record){
            res += diff[i];
        }
    }
    return Bignum(res);
}


const Bignum operator*(const Bignum& left, const Bignum& right){
    string ls = left.num;
    string rs = right.num;

    int llength = ls.length();
    string pro = "0";
    string tmp = "";
    Bignum ret(pro);
    
    ls = reverse_string(ls);
    rs = reverse_string(rs);

    for(int i = 0; i < llength; i++){
        tmp = multiply_string_char(rs,ls[i]);
        tmp = fill_string(i, tmp);
        tmp = reverse_string(tmp);
        Bignum tmpBig(tmp);
        ret = ret + tmpBig;
    }
    return ret;
}


const Bignum operator/(const Bignum& left, const Bignum& right){
    string a="0";
    Bignum res(a);
    res = divide_string(left.num, right.num, res);
    return res;
}

istream& operator>>(istream& is,Bignum& bn){
    string num ="";
    is >> num;
    bn = Bignum(num);
    return is;
}

ostream& operator<<(ostream& os,const Bignum& bn){
    string num = bn.num;
    os << num;
    return os;
}





/*
 * the definition of the help functions
 */
int find_max(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}

string& fill_string(int num, string& str){
    if(num < 0){
        cout << "ERROR: fill string num < 0" << endl;
        return str;
    }
 //   int num = max - str.length();
    for (int i = 0; i < num ;i++){
        str = "0"+str;
    }
    return str;
}

string reverse_string(string str){
    string res = "";
    int len = str.length();
    for(int i = len-1; i >= 0; i--){
        res += str[i];
    }
    return res;
}

char add_char(char a, char b, int& mark){
    /*cout << "ADD_CHAR: a is " << a << endl;
    cout << "ADD_CHAR: b is " << b << endl;
    cout << "ADD_CHAR: mark is " << mark << endl;
    */
    int an = char_to_int(a);
    int bn = char_to_int(b);
    int sum = an + bn + mark;
    //cout << "ADD_CHAR: sum = "<<sum<<",an is "<< an <<",bn is  "<<bn<<endl;
   /* strstream ss;
    string s;
    ss << sum;
    ss >> s;
    */
    string s = int_to_str(sum);
    if(s.length() == 2){
        mark = char_to_int(s[0]);
        return s[1];
    }else if (s.length() == 1){
        mark = 0;
        return s[0];
    }else{
        cout << "ERROR: add_char" << endl;
        mark = 0;
        return -1;
    }
}

char minus_char(char a, char b, int& mark){
    int an = char_to_int(a);
    int bn = char_to_int(b);
        int diff = an + mark + 10 - bn;
    if((an + mark) >= bn){
        int diff = an + mark - bn;
        mark = 0;
        string s = int_to_str(diff);
        return s[0];
    }else{
        mark = -1;
        string s = int_to_str(diff);
        return s[0];
    }
}

string multiply_string_char(string s, char c){
    string pro="";
    int mark = 0;
    for(int i = 0; i < s.length(); i++){
        pro += multiply_char(s[i],c,mark);
    }
    if(mark != 0){
        pro += int_to_str(mark);
    }
    return pro;
}


char multiply_char(char a, char b, int& mark){
    int an = char_to_int(a);
    int bn = char_to_int(b);

    int product = an * bn + mark;

    string pro_str = int_to_str(product);
    if(pro_str.length()==2){
        mark = char_to_int(pro_str[0]);
        return pro_str[1];
    }else if (pro_str.length() == 1){
        mark = 0;
        return pro_str[0];
    }else{
        mark = 0;
        cout << "ERROR: multiply_char" << endl;
        return '0';
    }
}


int char_to_int(char c){
    return (int)c - 48;
}

string int_to_str(int a){
    strstream ss;
    string s;
    ss << a;
    ss >> s;
    return s;
}

Bignum& divide_string(string a, string b, Bignum& res){
    if(!is_bigger(a,b)){
        return res;
    }
    int zero_num=0;

    Bignum a_num(a);
    Bignum b_num(b);

    int llength = a.length();
    int rlength = b.length();
    string l1 = a.substr(0,rlength);
    string l2 = a.substr(rlength, llength - rlength);

    zero_num = llength - rlength;

    if(!is_bigger(l1,b)){
        l1 = a.substr(0,rlength+1);
        l2 = a.substr(rlength+1, llength - rlength -1);
        zero_num = zero_num - 1;
    }

    char count = '0';
    string tmp = b;

    do{
        tmp = b;
        count ++;
        tmp = reverse_string(tmp);
        tmp = multiply_string_char(tmp,count);
        tmp = reverse_string(tmp);
   }while(is_bigger(l1,tmp));

    count --;
    string count_str="";
    count_str = count_str + count;
    count_str = fill_string(zero_num, count_str);
    count_str = reverse_string(count_str);

    Bignum count_num(count_str);
    res = res + count_num;
    Bignum tmp_num = count_num * b_num;
    Bignum aa = a_num - tmp_num;
    return divide_string(aa.num,b,res); 
}


bool is_bigger(string a, string b){
    if(a.length() < b.length()){
        return false;
    }else if(a.length() > b.length()){
        return true;
    }else{
        int len = a.length();
        for(int i = 0; i < len; i++){
            if(char_to_int(a[i]) > char_to_int(b[i])){
                return true;
            }else if(char_to_int(a[i]) < char_to_int(b[i])){
                return false;
            }
        }

        // they are equal
        return true;
    }
}
