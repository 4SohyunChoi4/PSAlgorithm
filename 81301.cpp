#include <string>
#include <vector>
#include <ctype.h>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 0;
    string answer_str="";
    string number="";
    vector <string> numbers = {"zero", "one", "two", "three", "four",
                         "five","six","seven","eight","nine"};
    //for(int i=0;i<s.size();){
    int i=0;
    while(i<s.size()){
        if(isdigit(s[i])){//숫자일 때
            answer*=10;
            answer+=stoi(s.substr(i,1));
            i++;
        }
        else{
            while(isalpha(s[i])){
                //cout<<"s[i]: "<<s[i]<<endl;
                number+=s[i];
                if(find(numbers.begin(),numbers.end(),number)!=numbers.end()) //number가 numbers안에 있으면
                {
                    cout<<number<<endl;
                    answer*=10;
                     answer+=find(numbers.begin(),numbers.end(),number)-numbers.begin();//인덱스값 + 1
                    number="";//초기화
                }
                i++;
            }

        }
    }
    //cout<<answer_str;
    return answer;
}