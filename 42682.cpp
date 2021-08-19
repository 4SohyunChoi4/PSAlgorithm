#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;//체육수업을 들을 수 있는 학생의 최댓값
    vector<int> new_lost;
    
    vector<int>::iterator it;
    vector<int>::iterator it2;
    
    vector<int>::iterator it_front;
    vector<int>::iterator it_end;
    
    for(it=lost.begin(); it!=lost.end(); it++){
        it2=find(reserve.begin(), reserve.end(), *it);
        if(it2!=reserve.end())
            {
                reserve.erase(it2);
            }
        else
            new_lost.push_back(*it);
    }
    
    for(it=new_lost.begin(); it!=new_lost.end(); it++){
        it_front = find(reserve.begin(), reserve.end(), *it+1); 
        it_end = find(reserve.begin(), reserve.end(), *it-1);
        //만약에 lost의 +-1의 값이 reserve값이 있으면

        if(it_front != reserve.end() ){
            reserve.erase(it_front);
            continue;
        }        
        if(it_end != reserve.end()){
            reserve.erase(it_end);
            continue;
        }
                //그 값을 reverse에서 제거한 후 continue
        answer--; // 아니면 answer--;
        
    }
    return answer;
}