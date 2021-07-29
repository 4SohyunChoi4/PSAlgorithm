#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    //최대공약수
    for(int i=n; i >=1 ; i-- )
    {
        if(n%i == 0 && m%i == 0)
        {
            answer.push_back(i);
            answer.push_back(n/i *  m/i * i);//최소공배수
            break; 
        }     
    }
    return answer;
}