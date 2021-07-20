#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(vector<string> seoul) {
    int i = find(seoul.begin(), seoul.end(), "Kim") - seoul.begin();
    
    string answer = "김서방은 "+ to_string(i)+"에 있다";
    return answer;
}