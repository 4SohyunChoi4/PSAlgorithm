#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    string answer = "";
    string odd = "Odd";
    string even = "Even";
    
    if (num<0)
        num= abs(num);
    if ( num %2 ==1)
        answer=odd;
    else
        answer=even;
    return answer;
}