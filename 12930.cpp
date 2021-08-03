#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    int count=0;
    // 짝수번째 알파벳은 대문자로, 홀수번째 알파벳은 소문자로
    for(int i=0 ; i<s.size() ; i++){
        if(s[i]==32){
            answer+=s[i];
            count=0;
        }
        else
        {
            if(count%2) //홀수일 때 -> 소문자
            {
                if(isupper(s[i]))//대문자일 때
                    answer+=tolower(s[i]);
                else
                    answer+=s[i];
            }
            else //짝수일 때 -> 대문자
            {
                if(islower(s[i]))//소문자일 때
                    answer+=toupper(s[i]);
                else
                    answer+=s[i];
            }
        count++;
        }
    }
    
    return answer;
}