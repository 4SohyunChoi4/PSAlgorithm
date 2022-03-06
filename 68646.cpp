#include <string>
#include <vector>
#include <iostream>
using namespace std;

int findMin(int newer, int min){
    if ( min > newer) return newer;
    else return min;
}
int solution(vector<int> a) {
    int answer=2; // 좌, 우는 무조건 추가됨

    int size = a.size();
    vector<int> left(size); //0부터 size-1까지 
    vector<int> right(size);
    
    left[0] = a[0];
    right[size-1] = a[size-1];
    for(int i=1; i<size-1;i++){
        left[i] = findMin(a[i], left[i-1]); //현재 값이랑 그 전의 맥스 값이랑 비교
    }
    
    for(int i=size-2; i>=0 ;i--){
        right[i] = findMin(a[i], right[i+1]); //현재 값이랑 그 전의 맥스 값이랑 비교
    }
    
    for(int i=1; i<a.size()-1;i++){
        if(a[i]<=left[i] || a[i]<=right[i]) {answer++; }//cout<<a[i]<<endl;}
    }

    return answer;
}