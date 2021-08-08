#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int num) {
    int count=0;
    long num2 =num;
    while(num2!=1)
    {
    if(!(num2%2)) //짝수
        num2/=2;
    else
        num2=num2*3+1;
    count++;
    if(count==500){
        return -1;
    }
    }
    return count;
}