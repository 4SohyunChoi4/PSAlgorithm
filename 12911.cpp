#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int cnt_one(int n){
  string bi_n="";
  while(n>=1){
       bi_n  += to_string(n%2);
        n/=2;
  }
  return count(bi_n.begin(), bi_n.end() ,'1');//1의 개수
}

int solution(int n) {
    int answer = n+1;
    int cnt_n, cnt_answer;
    
    cnt_n=cnt_one(n);// 원래 숫자에서 2진수 1의 개수
    
    while(1)
    {
        cnt_answer=cnt_one(answer);
        if(cnt_answer== cnt_n)
            break;
        answer++;
    }

    
    //n의 다음 큰 숫자와 n은 2진수로 변환했을 때 1의 갯수가 같습니다.

    return answer;
}