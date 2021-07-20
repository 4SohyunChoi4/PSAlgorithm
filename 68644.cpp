#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> set;
    // 두개 수 더한다
    for(int i=0; i<numbers.size() ; i++)
    {
        for(int j=i+1; j<numbers.size(); j++){
            set.insert(numbers[i] + numbers[j]);
        }
    }
    //오름차순으로 배열
   // sort(answer.begin(),answer.end());
    //answer.erase(unique(answer.begin(), answer.end()), answer.end());
    answer.assign(set.begin(), set.end());
    return answer;
}