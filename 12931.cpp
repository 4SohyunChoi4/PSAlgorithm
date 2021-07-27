#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>

using namespace std;
int solution(int n)
{
    int answer = 0;
    string num = to_string(n);
    int len = num.length();

    for(int i=len-1;i>=0; i--){
        answer+= num[i]-'0';
       // cout<<atoi()<<endl;
    }
    return answer;
}