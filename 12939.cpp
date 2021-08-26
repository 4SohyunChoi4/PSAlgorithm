#include <string>
#include <sstream>
#include <iostream>
#include <set>
using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss;
    set<int> num;
    set<int>::iterator it;
    int n;
    ss.str(s);
    while(ss >> n)
    {
        num.insert(n);
    }
    it=num.begin();
    answer+=to_string(*(num.begin()))+" "+to_string(*(num.rbegin()));
    return answer;
}