#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";
    vector <int> sub;
    vector<float> avg(scores.size());
    vector<vector<int>> rev_scores;
    float size = scores.size();
    for(int i=0 ; i <size ; i++)
    {
        rev_scores.push_back(sub);

        for(int j=0 ; j< size ; j++)
        {
            //if(scores[i][i]==scores[j][i] && 
            rev_scores[i].push_back(scores[j][i]);
        }
        //만약에 중복값x이며 최대/최소값일 때는 삭제, /(n-1) 한다
        
        auto minmax = minmax_element(rev_scores[i].begin(), rev_scores[i].end());
        if(count(rev_scores[i].begin(), rev_scores[i].end(), rev_scores[i][i])==1
           && (*minmax.first==rev_scores[i][i] || *minmax.second==rev_scores[i][i]))
        {
            rev_scores[i][i]=0;
            avg[i]= accumulate(rev_scores[i].begin(), rev_scores[i].end(),0.0)/(size-1);
        }
        else
            avg[i]= accumulate(rev_scores[i].begin(), rev_scores[i].end(),0.0)/size;
    }
    
    for(int i=0 ; i <size ; i++)
    {
        cout<<avg[i]<<endl;
        if(avg[i]>=90)
            answer+="A";
        else if(avg[i]>=80)
            answer+="B";
        else if(avg[i]>=70)
            answer+="C";
        else if(avg[i]>=50)
            answer+="D";
        else
            answer+="F";
    }
    return answer;
}