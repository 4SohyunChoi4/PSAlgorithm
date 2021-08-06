#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdlib.h>

using namespace std;

long long solution(long long n) {
    //long long answer_int = 0;
    string answer="";
    string str = to_string(n);
    //sort(str, str.size());
    vector <char> vec;
    for(int i=0 ; i<str.size(); i++){
        vec.push_back(str[i]);
    }
    sort(vec.begin(),vec.end(), greater<int>());
    
    for(int i=0 ; i<str.size(); i++){
        answer+=vec[i];
    }
    cout<<atoi(answer.c_str());
    
    
    return atoll(answer.c_str());
}