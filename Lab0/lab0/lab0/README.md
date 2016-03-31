# OOP Lab0

Getting started with C++

**Deadline:** 23:59. Sunday, March 20, 2016 (GMT+8)

For any further question, you can turn to Zhongyi Tong (13302010039@fudan.edu.cn) or Jiacheng Xu (13302010009@fudan.edu.cn) for help.

## Set up your environment

In this course, we recommand you to use **CLion** as your C++ IDE, which supports OS X, Linux and Windows. We believe the consistent experience and powerful GUI will make it friendly and familiar to the beginners. In the following labs, starter code will be provided in the format of a CLion project. **You are free to turn it into a Visual Studio project or whatever you like.**

### What you need to do

1. Download CLion on JetBrains's [official website](https://www.jetbrains.com/clion/).
2. [Apply for free stuent license](https://www.jetbrains.com/shop/eform/students). You can get access to all desktop products including IntelliJ IDEA, WebStorm, CLion and other IDEs.
3. Activate and config your IDE.
4. Download lab materials at FTP. Compress and directly import the project into CLion.
   ```
   ftp://10.132.141.33//classes/14/152 面向对象程序设计(陈辰)/LAB/lab0.zip
   ```

### Useful resources

- [CLion Quick Start Guide](https://www.jetbrains.com/clion/help/quick-start-guide.html)
- [Installing Clion Windows](https://www.youtube.com/watch?v=00_Nj94aDQk)

## Your fist C++Program

In this lab, you are required to write a translator that converts a sequence of characters to corresponding ACSII code. The behavior of your program should be exactly the same as the given `Translator.java`.

You can find the following contents in your lab:

- **Input:** `dict.txt` contains a sequence of characters, which **ends with a space**.
- **Output:** `result.txt` contains a sequence of integers, which **ends with a space**. The integers are split by space, and each integer represents the ith character in `dict.txt` (eg, `"9 20 18 19 "` stands for `"just"`).
- `translator.cpp` Your code to implement this lab. Click green triangle at upper-right hand to run your program.

After finishing the program, consider and answer the following questions:

1. Describe the similarities and differences of C++ and JAVA. 
2. Learn more about the CLion IDE, especially the refractoring and debugging tool.
3. Get to know the pre-processor for C++.

## Submission

Your submission should include the project directory with an `answer.txt`. Compress your directory to `studentID_name.zip`.

Submit your work to:

```
ftp://10.132.141.33//classes/14/152 面向对象程序设计(陈辰)/WORK_UPLOAD/lab0
```