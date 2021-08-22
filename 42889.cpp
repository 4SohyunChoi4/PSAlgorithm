#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(const pair<float, int> &a, const pair<float, int> &b)
{
    if(a.first==b.first)
        return a.second < b.second;
    return a.first > b.first;
}
vector<int> solution(int N, vector<int> stages) { 
    //전체 스테이지의 개수 N, 게임을 이용하는 사용자가 현재 멈춰있는 스테이지의 번호가 담긴 배열 stages
    vector<int> answer; //실패율이 높은 스테이지부터 내림차순으로 스테이지의 번호가 담겨있는 배열
   vector<pair<float, int>>::iterator it;
    vector<pair<float, int>> answer_pair;
    int size = stages.size();
    //1번부터 N번까지 반복
    for(int i=1 ; i <= N ; i++ ){
        int j=0;
        float cnt=0;
         while(j<size){ // 분모값
            if(stages[j] >= i){
                cnt+=1;
            }
            j++;
        }
            // i개수 / i번이상의 총 개수 -> map (key, value) 에서 value로
        //answer_pair[i-1] = count(stages.begin(), stages.end(), i) /cnt;
        if(cnt==0)
            answer_pair.push_back(pair<float, int>(0,i));
        else
            answer_pair.push_back(pair<float, int> ((float)count(stages.begin(), stages.end(), i) /cnt, i));
        cout<<count(stages.begin(), stages.end(), i)<< " "<< cnt<< endl;
    }
    // 에서 first값으로 정렬
    sort(answer_pair.begin(), answer_pair.end(), greater<pair<float, int>>());
    sort(answer_pair.begin(), answer_pair.end(), cmp);
    

    //key값만 추출
    for(it = answer_pair.begin(); it!=answer_pair.end(); it++)
        answer.push_back(it->second);
    return answer;
}