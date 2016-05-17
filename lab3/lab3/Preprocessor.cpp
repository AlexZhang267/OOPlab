//
// Created by alex on 16-5-17.
//

#include <sstream>
#include "Preprocessor.h"
//#include "boost/regex.hpp"

void Preprocessor::preprocess(string raw_code) {
    vector<string> code_vector;
    code_vector = read_line(raw_code, code_vector);

    for (int i = 0; i < code_vector.size(); i++) {
        string line = code_vector[i];
        handle_line(line);
    }
}

vector<string> &Preprocessor::read_line(string raw_code, vector<string> &code_vector) {
    istringstream is(raw_code);
    string tmp;
    while (getline(is, tmp)) {
        code_vector.push_back(tmp);
    }
    cout << code_vector.size() << endl;
    return code_vector;
}

void Preprocessor::handle_line(string line) {
    regex reg("#(\\s)*define");

    cout << regex_match(line,reg) << endl;


    for (int i = 0; i < regex_vector.size(); ++i) {

//        cout << i << endl;
//        cout << (string)regex_vector[i] << endl;
        if (regex_match(line,regex_vector[i])){
            cout << line << endl;
        }

    }
//    cout << line << endl;
}

void Preprocessor::handle_directive(string directive) { }


