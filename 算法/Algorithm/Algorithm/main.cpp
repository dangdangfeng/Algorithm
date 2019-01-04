//
//  main.m
//  Algorithm
//
//  Created by taoxiaofei on 2018/12/28.
//  Copyright © 2018年 easy. All rights reserved.
//

#include <iostream>
#include "Ten/Ten.hpp"

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
//    CalcAllPermutation("abc", 0, 3);
    string* str = new string;
    string s = "abc";
    *str = s;
    CalcAllPermutation(str, 3);
    return 0;
}
