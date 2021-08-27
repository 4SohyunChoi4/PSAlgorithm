#include <string>
#include <vector>
using namespace std;

int solution(int n) {
    int answer = 1, sum = 0, j=1;
    for(int i = j ; i <=(n+1)/2 ; i ++){
        sum+=i;
        if(sum==n)
        {
            answer++;
            sum=0;
            i=(j++);
            continue;
        }
        else if(sum>n)
        {
            sum=0;
            i=(j++);
            continue;
        }
    }
    return answer;
}