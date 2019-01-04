//
//  Ten.cpp
//  Algorithm
//
//  Created by taoxiaofei on 2019/1/3.
//  Copyright © 2019年 easy. All rights reserved.
//  字符串的全排列

#include "Ten.hpp"

void CalcAllPermutation(string perm, int from, int to){
    if (to <= 1) {
        return;
    }
    if (from == to) {
        for (int i = 0; i <= to; i++) {
            cout << perm[i];
        }
        cout << endl;
    }else{
        for (int j = from; j <= to; j++){
            swap(perm[j], perm[from]);
            CalcAllPermutation(perm, from + 1, to);
            swap(perm[j], perm[from]);
        }
    }
}

// 字典序排列
bool CalcAllPermutation(string* perm, int num){
    int i;
    
    for (i = num - 2; (i >= 0) && (perm[i] >= perm[i+1]); --i) {
        ;
    }
    
    if (i < 0) {
        return false;
    }
    
    int k;
    
    for (k = num - 1; (k > i) && (perm[k] <= perm[i]); --k) {
        ;
    }
    
    swap(perm[i], perm[k]);
    reverse(perm+i+1, perm+num);
    
    return true;
}
