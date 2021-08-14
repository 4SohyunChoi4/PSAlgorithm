#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int left, int right) {
    int answer = 0; //약수의 개수가 짝수인 수는 더하고, 약수의 개수가 홀수인 수는 뺀 수
    int count = 0;
    //약수의 개수는 처음부터 2개
    for(int i=left ; i <= right ; i++){
        count = 1;
        for(int j=1 ; j <i ; j++){
            if(i % j == 0)
                count++;
        }
        if(count%2==0) //짝수이면
            answer+=i;
        else
            answer-=i;
    }
    return answer;
}