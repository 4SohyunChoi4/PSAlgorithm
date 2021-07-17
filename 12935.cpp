#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    vector<int>::iterator iter;
    
    if(arr.size()==1){ //인덱스가 1일 때
        answer.push_back(-1);
        return answer;
    }
    else{
        auto lesser = minmax_element(arr.begin(),arr.end());
       iter=find(arr.begin(),arr.end(),*lesser.first);//찾은 최소값을 찾는다
        arr.erase(iter);//삭제한다
       return arr;   
    }
}