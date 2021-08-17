#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;

int solution(int n) {
    int answer = 0, temp=n, three=1;
    string ternary = "";
    
    //3진법으로 바꾼 뒤 뒤집어진 상태로 둔다.
    while(temp>=3){
        ternary += to_string(temp % 3);
        temp /= 3;
    }
    ternary += to_string(temp);

    for(int i=ternary.size()-1 ; i >= 0 ; i--){
        answer += stoi(ternary.substr(i,1))*three;
        three*=3;
    }
    return answer;
}