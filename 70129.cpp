#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer; // 이진 변환의 횟수, 제거된 0의 개수
    int sum=0, cnt=0;
    while( s.length() > 1){
        string temp="";
        for(int i=0; i<s.length(); i++){
            if(s.substr(i,1).compare("1") == 0) temp+="1";
            else sum++;
        }
        s=temp;
        int size =count(s.begin(), s.end(), '1');
        sum+= s.length() - size;
        temp="";
        while(size!=0){
            temp += to_string(size%2);
            size/=2;
        }
        reverse(temp.begin(), temp.end());
        s=temp;
        cnt++;
    }
    answer.emplace_back(cnt);
    answer.emplace_back(sum);//제거된 0의 개수
    return answer;
}