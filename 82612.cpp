#include <iostream>
using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long price_sum=0;
    long long i=0;
    while(count>0){
        price_sum+=price*count;
        count--;
    }
    answer=price_sum-money;
    if(answer<0)
        return 0;
    return answer;
}