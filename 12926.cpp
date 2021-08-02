#include <string>
#include <vector>
#include <iostream>
#include <ctype.h>
using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i = 0 ; i < s.size(); i++){
        if(s[i]==32)//공백일 때
        //if(!islower(s[i]) && !isupper(s[i]))
            answer+=s[i];
        else{//소, 대문자일 때
            if(islower(s[i]+n) && islower(s[i]) || isupper(s[i]+n) &&isupper(s[i])){
                answer+=s[i]+n;
            }
            else {
                answer+= s[i]+n-26;
            }
        }
    }
    return answer;
}