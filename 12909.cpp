#include <string>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int boolean = 0;
    //음수가 되면 false로 리턴해버리깅
    for(int i=0 ; i < s.size() ; i++){
        if(s.substr(i,1).compare("(") == 0)
            boolean++;
        else// if(s.substr(i,1).compare(")") == 0)
            boolean--;
        if(boolean < 0)
            return false;
    }
    if(boolean!=0)
        answer=false;
    
    return answer;
}