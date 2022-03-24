#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int sum = brown + yellow;
    int col, row;
    vector<int> divisor;
    //소인수분해해서 약수 구한다
    for(int i= sum/2; i >=2 ; i--){
        if(sum % i == 0)
            divisor.emplace_back(i); //절반만 저장해도 될듯
    }
    cout<<endl; 
    for(int i=0; i<divisor.size() ; i++){
        row = divisor[i];
        col = sum / row;
        if(row < col) break;
        //cout<<row<<" "<<col<<endl;
        else if((row - 2) * (col - 2) == yellow) {
            answer.emplace_back(row);
            answer.emplace_back(col);
        }
    }
    return answer;
}