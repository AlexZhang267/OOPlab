#include <iostream>
#include <fstream>

using namespace std;

string getDict();

string dir = "F:"; //当前路径是放exe的路径，为了方便就用了绝对路径

int main() {
    // Your code here
    string s = getDict();

    unsigned int index = 0;

    ifstream result("result.txt");
    ofstream answer("answer.txt");

    while (!result.eof()) {
        result >> index;

        // 当result读到末尾时，eof()返回的仍然是true，
        // 需要在执行上一条语句之后添加以下if语句才可以避免将最后一个字符输出两遍
        if (result.eof()) {
            break;
        }

        try {
//            cout << s.at(index);
            printf("%c",s.at(index));
            answer << s.at(index);
        } catch (exception exception1) {
            cout << "\\nERROR: Out of Bounds!" << endl;
        }
    }
    return 0;
}

string getDict() {
    string s;
    ifstream in("dict.txt");
    getline(in, s);
    return s;
}