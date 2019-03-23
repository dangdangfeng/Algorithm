//
//  Twelve.cpp
//  Algorithm
//
//  Created by taoxiaofei on 2019/1/8.
//  Copyright © 2019年 easy. All rights reserved.
//

#include "Twelve.hpp"
#include <iostream>
#include <time.h>

using namespace std;

struct Time {
    int hour, minute;
    double second;
    double convertToSeconds (){
        hour++;
        return 0.01;
    }
    Time (int hour, int min, double secs);
    Time currentTime(int hour, int min, double secs);
};
Time::Time (int h, int m, double s){
    hour = h; minute = m; second = s;
}
Time currentTime (int h, int m, double s){
    return {h,m,s};
}

double convertToSeconds (const Time& time) {
    return time.hour + time.minute;
}

void printTime (Time& t){
    cout << t.hour << ":" <<t.minute << ":" <<t.second<<endl;
}

void addTimeFill(const Time& t1, const Time& t2, Time &sum){
    sum = {20, 59, 3.1};
}

void main1()
{
    
    cout<<"Hello, world."<<endl;
    string first;
    first = "Hello,";
    first.find('e');
    
    getline(cin, first);
    
    Time time = {11, 59, 3.14159};
    
    printTime(time);
    
    Time sum = {11, 59, 3.14159};
    addTimeFill(time, time, sum);
    
    getline(cin, first);
    
    for (int i = 0; i < 5; i++) {
        long x = random();
        cout<<x<<endl;
    }
}









