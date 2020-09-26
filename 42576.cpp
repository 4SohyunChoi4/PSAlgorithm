#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    string answer=" ";
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    vector<string>::iterator it_p, it_c;
    
    for(it_p=participant.begin(),it_c=completion.begin();
        it_c!=participant.end();
        it_p++,it_c++)
        if(*it_p!=*it_c)
        {
            answer = *it_p;
            break;
        }
    return answer;
}