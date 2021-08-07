#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    double num = sqrt(n);
    if((num - (int)num) == 0){ // 정수이면
        return pow(num+1,2);
    }
    else
        return -1;
}