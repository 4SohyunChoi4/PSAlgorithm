#include <string>
#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

vector<int> solution(int n) {
    int size = n;
    vector<int> answer;
    int blocks[size][size];   
    memset(blocks, 0, sizeof(blocks));
    int num = 0;
    int i=0, j=0;
    int cnt;
    while(size>0){//num이 total이 될 때까지..
        //위->아래
        cnt=0;
        while(cnt<size){
            blocks[i++][j] = ++num;
            cnt++;
        }
        size--;
        i--; j++;
        //좌->우
        cnt=0;
        while(cnt<size){
            blocks[i][j++] = ++num;
            cnt++;
        }
        size--;
        i--; j-=2;
        cnt=0;
        //대각선 왼쪽 위로        
        while(cnt<size){
            blocks[i--][j--] = ++num;
            cnt++;
        }
        size--;
        i+=2; j++;
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(blocks[i][j]!=0) 
                answer.push_back(blocks[i][j]);
            else
                continue;
        }
    }
    
    return answer;
}