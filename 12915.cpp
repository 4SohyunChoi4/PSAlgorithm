#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    
    multimap<char, string> m;
    map<char, string>::iterator iter;
    sort(strings.begin(), strings.end());
    for(int i=0 ; i< strings.size(); i++){
        m.insert(make_pair(strings[i][n], strings[i]));
    }
    for(iter = m.begin() ; iter != m.end() ; iter++){
        //cout<< iter->first << " " <<iter->second << endl;
        answer.push_back(iter->second);
    }
    return answer;
}