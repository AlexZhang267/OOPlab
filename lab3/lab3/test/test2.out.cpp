//
// Created by TongZhongyi on 5/10/16.
// WARNING: You are not allowed to modify this file!
//
#include "iostream"
#include "test2.h"

#define FALSE 0
#define TRUE 1
#define NOTFALSE TRUE
#define PRODUCT (a*b)

int main() {
#ifdef LAB2_H
    a = 3;
    b = 5;
    int s = sum(a, b);
    int p = PRODUCT;
    int flag = 1;
    std::cout << "#include pass!" << std::endl;
#endif

#define PART2

#ifdef PART2
    flag++;
    std::cout << "#define check1 pass!" << std::endl;
    std::cout << "#ifdef pass!" << std::endl;
#undef PART2
#endif

#ifdef PART2
    std::cout<<"#undef fail!"<<std::endl;
#else
    flag++;
    std::cout << "#undef pass! " << std::endl;
    std::cout << "#else pass!" << std::endl;
#endif

#ifndef PART2
    flag++;
    std::cout << "#ifndef pass!" << std::endl;
#endif

#if 0
    std::cout<<"#if fail!"<<std::endl;
#else
#if 1
    flag++;
    std::cout << "#if pass!" << std::endl;
#else
    std::cout<<"#if fail!"<<std::endl;
#endif
#endif

#if TRUE
    flag++;
    std::cout << "#define check2 pass!" << std::endl;
#else
    std::cout<<"#define check2 fail!"<<std::endl;
#endif

#if NOTFALSE
    flag++;
    std::cout << "#define check3 pass!" << std::endl;
#endif

#ifdef TRUE
    flag++;
    std::cout << "#define check4 pass!" << std::endl;
#endif

    if (s == 8 && p == 15) {
        flag++;
        std::cout << "#define check5 pass!" << std::endl;
    } else {
        std::cout << "#define check5 fail!" << std::endl;
    }

    if (flag == 9) {
        std::cout << "PART 2 pass!!!!!" << std::endl;
    } else {
        std::cout << "PART 2 fail!!!!!" << std::endl;
    }


#define PART3
#ifdef PART3
#define DOUBLE(arg) (2*arg)
    int d = DOUBLE(a);
    if (d == 2 * a) {
        std::cout << "PART 3 pass!!!!!" << std::endl;
    } else {
        std::cout << "PART 3 fail!!!!!" << std::endl;
    }
#else
    std::cout<<"Please try to make the test of part 3 work, e.g. add one line in this file!!"<<std::endl;
#endif


#define PLUSES
#ifdef PLUSES
#define Cong(arg) "PLUSES "#arg
    std::cout << Cong(pass) << "!!!!!" << std::endl;
#else
    cout<<"Please try to make the test of pluses work, e.g. add one line in this file!!"<<std::endl;
#endif
    return 0;
}
