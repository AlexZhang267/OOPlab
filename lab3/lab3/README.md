# OOP Lab3

##### C ++ Preprocessor

**Deadline:** 23:59. Saturday, May 21, 2016 (GMT+8)

For any further question, you can turn to Zhongyi Tong (13302010039@fudan.edu.cn) or Jiacheng Xu (13302010009@fudan.edu.cn) for help.

## Set up

In this lab, you are required to write a simple C++ preprocessor.

Download the starter code at:

```json
ftp://10.132.141.33//classes/14/152 面向对象程序设计(陈辰)/LAB/lab3
```

You can find the following contents:

- `/test`: a test folder that contains raw C++ code segments
- `/test/run_tests.sh`: a grading script to test your processed code segment
- `lab3.cpp`: entrance for your preprocessor

**Note:** The package you download is a CLion project by default. If you are using other environments, adjust it as you wish. But remember to specify your environment in your documentation.

## Introduction

### What does the preprocessor do?

The preprocessor takes a look at your source code just before it goes off to the compiler, does a little formatting, and carries out any instructions you have given it.

**Like what?**

Well, preprocessor instructions are called *preprocessor directives*, and they all start with a `#`.

**Like #include?**

Exactly. Each `#` command that the preprocessor encounters results in a modification to the source code in some way.

### Preprocessor directives

There are common directives like `#include`, `#define`, `#undef`, ` #ifdef`,  `#ifndef`, ` #if`,  `#endif`, etc. There are also predefined macros like `__FILE__`, `__TIME__`, etc.

In this lab, our preprocessor needs to deal with these directives in simple scenarios. There are also Preprocessor Operators, Predefined Macros, Pragmas, or complex directives, which are left as bonus.

**Quiz question:** Describe the usage of each directive above and answer the question: why do we need a preprocessor to do this instead of using functions at runtime.

**References:** http://www.cplusplus.com/doc/tutorial/preprocessor/

### How to implement a preprocessor?

There are easy ways, and hard ways. To simplify, the preprocessor is just a string processor, that stores "tokens" and replaces them with regex in the following context. There are plenty of differnt angles, and how you abstract the prolem is very important. Your preprocessor is supposed to have a well designed structure, with elegant code style .

**References:** [The GNU C Preprocessor Internals](https://gcc.gnu.org/onlinedocs/cppinternals/), [MSDN C/C++ Preprocessor Reference](https://msdn.microsoft.com/en-us/library/y4skk93w.aspx), etc

### What to do in this lab?

- Implement your code. `lab3.cpp` provides an extrance for your preprocessor.
- Test your preprocessor. There are two test files in `/test` folder —— `test1` is very simple and helps you debug at early stage, `test2` is complicated and used to verify cases in all scenarios.
- Run `test/run_tests.sh` to run all tests. Make sure you are under `/test`.
- If you are developing extra features, you must provide additional tests as well.
- Write well organized documentation to describe your project structure. Don't forget to include the quiz question above.

**Left:** unprocessed code segment; **Right:** processed code segment.

![](https://camo.githubusercontent.com/1abc46e451e406ac7971b865494867a9f5b4e8f1/68747470733a2f2f6c68332e676f6f676c6575736572636f6e74656e742e636f6d2f2d386e4354694f4e6d4532512f5654454238564c6e7736492f414141414141414142734d2f5f387466494b6244532d512f73302f312e706e67)

## Grading Criteria

##### Directives (60%)

- `#include` - 10%
- `#define` basic (check1 to check5) - 10%
- ` #ifdef` - 10%
- ` #if` - 10%
- `#define` function (PART 3) - 10%
- `#define` function (PLUSES) - 10%
- bonus - up to 20%

You can get whole 60% if you pass two provided tests.

##### Code (25%)

- Project structure - 20%
- Code style - 5%

##### Documentation (15%)

- Quiz question - 5%
- Documentation - 10%

## Submission

Your submission should include the project directory with an `answer.txt`. Compress your directory to `studentID_name.zip`.

Submit your work to:

```json
ftp://10.132.141.33//classes/14/152 面向对象程序设计(陈辰)/WORK_UPLOAD/lab3
```