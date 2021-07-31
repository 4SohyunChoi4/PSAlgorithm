#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    vector<char> vec;
    for(int i=0 ; i<s.size(); i++){
        vec.push_back(s[i]);
    }
    sort(vec.begin(), vec.end(), greater<char>());
    for(int i=0 ; i<vec.size(); i++){
        answer+=vec[i];
    }
    return answer;
}