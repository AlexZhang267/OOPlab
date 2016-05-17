//
// Created by alex on 16-5-17.
//
#include <vector>
#include <regex>
#include "iostream"
#include "string"
using namespace std;

#ifndef LAB3_PREPROCESSOR_H
#define LAB3_PREPROCESSOR_H


class Preprocessor {
private:
    vector<regex> regex_vector;

public:
    Preprocessor(){
        regex_vector.push_back(regex("# *define"));
    }


    void preprocess(string raw_code);
    vector<string> &read_line(string raw_code, vector<string> &code_vector);
    void handle_line(string line);
    void handle_directive(string directive);

};


#endif //LAB3_PREPROCESSOR_H
