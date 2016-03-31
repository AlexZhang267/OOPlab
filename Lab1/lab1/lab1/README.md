# OOP Lab1

**A Naive Dictionary**

**Deadline:** 23:59. Sunday, April 02, 2016 (GMT+8)

For any further question, you can turn to Zhongyi Tong (13302010039@fudan.edu.cn) or Jiacheng Xu (13302010009@fudan.edu.cn) for help.

## Description

In this lab, you are required to write a naive dictionary, which offers functions `add`, `delete`, `update` and `search`. You will get a better understanding of *struct*, *reference* and *pointer* in C++.

Download the starter code at:

```
ftp://10.132.141.33//classes/14/152 面向对象程序设计(陈辰)/LAB/lab1
```

You can find the following contents in your lab:

- `dict.h` is the header of your structure `Dict`.
- `dict.cpp` is the implementation of your structure `dict`. You code is required ***here*** to implement this lab.
- `dictionary.cpp` is the program to run. It tests your code and try to let its output make sense.

**Note:** The package you download is a CLion project by default. If you are using other environments, adjust it as you wish. But remember to tell us which environment you are using.

Beforing starting your lab, you need to know the difference between a reference and a pointer. Consider the following example.

### Reference and Pointer

```c++
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
 int a = 1;
 int *ap = &a;
 int &ar = a;
 cout << &a << endl;
 cout << &ap << endl;
 cout << &ar << endl;
 return 0;
}
```

**[Question 1]** What is the output of the program? Explain your output in brief.

**[Question 2]** References and pointers have the same performance in most cases, but they are different actually. List the differences as many as you could.

Answer these questions and submit with your code.

### Code your dictionary

**Note:** You are supposed to write your code only in `dict.cpp`, where there is commented with `Your code here`. **DO NOT** modify any other code so that we can test your code correctly, otherwise you may get 0 point. We will test your code with a large amount of data (5000 words perhaps), please check the robustness of your code.

We define a structure in this program:

```c++
typedef struct word
{
 	string key;   /* key with which the specified value is to be associated */
 	string value; /* value to be associated with the specified key */
} word;
```

The functions you should implement are:

**bool add(const word &w);**

> In this function you should insert a word in your dictionary. If the dictionary previously contained a mapping for the key, the old one should be replaced.

**string search(const string &key);**

> Returns the value to which the specified key is mapped, or"" if this map contains no mapping for the key.

**string remove(const string &key);**

> Removes the mapping for the specified key from this map if present.

**string update(const word &w);**

> Update an already existed word in your dictionary (NOTE: Do not insert the word to your dictionary if there was no such key)

**[Question 3]** Describe how you implement the four methods in dict.cpp.

Answer the question and submit with your code.

## Submission

Your submission should include the project directory with an `answer.txt`. Compress your directory to `studentID_name.zip`.

Submit your work to:

```
ftp://10.132.141.33//classes/14/152 面向对象程序设计(陈辰)/WORK_UPLOAD/lab1
```