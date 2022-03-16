#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#define SIZEOF001 3

using namespace std;

int findLast0(string &num){
    int position=0;
    for(int i=num.size(); i>=0;i--){
        if(num[i] == '0' ){
            return i+1;
        }
    }
    return position;
}

string makeSmallest(string& num) {
    stack<char> st;//stack으로 찾아야 O(N)의 시간복잡도로 찾을 수 있음
    int numberOf110 = 0;   
    for(int i=0; i<num.size();i++){
        st.push(num[i]);        
        if(st.size()>=SIZEOF001 && st.top()=='0'){
            char three = st.top();
            st.pop();
            char two = st.top();
            st.pop();
            char one = st.top();
            st.pop();
            //st의 마지막 세 개가 110이면
            if(one == '1' && two == '1' && three == '0'){
                numberOf110 ++;
            }
            else
            {
                st.push(one);
                st.push(two);
                st.push(three);
            }
        }
    }
    num="";
    while(!st.empty()){
        num += st.top();
        st.pop();
    }
    reverse(num.begin(), num.end());
    
    int start=0;
    int position = -1;
    int lastZero=findLast0(num);//처음 0의 위
    string temp = "";
    string result="";
    for(int i=0; i<lastZero; i++){
        result+=num[i];
    }
    while(numberOf110--){
        temp += "110";
    }
    result += temp;
  //  cout<<lastZero;
    for(int i=lastZero; i<num.length(); i++){
        result+=num[i];
    }
    
    return result;
}
vector<string> solution(vector<string> s) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<string> answer;
    for(int i=0; i<s.size(); i++){
        answer.emplace_back(makeSmallest(s[i]));
    }
    return answer;
}