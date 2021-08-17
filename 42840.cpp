#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) { //정답이 순서대로 들은 배열
    //3,3,1,1,2,2,4,4,5,5,
    vector<int> winner; // 가장 많은 문제를 맞힌 사람
    vector<int> student;
    
    int score1 = 0;
    int std1_size;
    vector<int> std1 = {1,2,3,4,5}; //1,2,3,4,5
    std1_size = std1.size();
    
    int score2 = 0;
    int std2_size;
    vector<int> std2 = {2,1,2,3,2,4,2,5};
    std2_size = std2.size();

    int score3 = 0;
    int std3_size;
    vector<int> std3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    std3_size = std3.size();

    for(int i=0; i<answers.size(); i++){
        if(answers[i] == std1[i%std1_size]){
            score1++;
        }        
        if(answers[i] == std2[i%std2_size]){
            score2++;
        }        
        if(answers[i] == std3[i%std3_size]){
            score3++;
        }
    }
    
    /*
    switch(max{score1,score2,score3}){
        case score1:
    }*/
    if(score1 == max({score1,score2,score3}))
        winner.push_back(1);    
    if(score2 == max({score1,score2,score3}))
        winner.push_back(2);    
    if(score3 == max({score1,score2,score3}))
        winner.push_back(3);
    
    
    return winner;
}