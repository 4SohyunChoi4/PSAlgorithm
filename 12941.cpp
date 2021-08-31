#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    //가장 작은 값 나열 * 가장 큰 값 나열 해서 곱하면 될듯?
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());
    
    for(int i=0; i< A.size(); i++)
       answer +=A[i]*B[i];
    return answer;
}