//
//  Six.cpp
//  Algorithm
//
//  Created by taoxiaofei on 2019/1/3.
//  Copyright © 2019年 easy. All rights reserved.
//

#include "Six.hpp"
#include <string>

using namespace std;

// O(n*m)次操作。显然，时间开销太大
bool StringContain(string &a,string &b){
    for (int i = 0; i < b.length(); ++i) {
        int j;
        for (j = 0; (j < a.length()) && (a[j] != b[i]); ++j) {
            if (j >= a.length()) {
                return false;
            }
        }
    }
    return true;
}

// 排序轮询
bool StringContain1(string &a, string &b){
    const int p[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
    
    int f = 1;
    for (int i = 0; i < a.length(); ++i) {
        int x = p[a[i] - 'A'];
        if (f % x) {
            f *= x;
        }
    }
    
    for (int i = 0; i < b.length(); ++i) {
        int x = p[b[i] - 'A'];
        if (f % x) {
            return false;
        }
    }
    
    return true;
}
