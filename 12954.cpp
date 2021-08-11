#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {//x간격, 총 n개
    vector<long long> answer;
    int num=x;
    for(int i=0 ; i<n ; i++){
        answer.push_back(num);
        num += x;
    }
    return answer;
}