#include <vector>
#include <iostream>
using namespace std;
int isPrimeNum(int num){
    for(int i=2; i<num; i++){
        if(num%i == 0){
            return 0; //소수가 아님
        }
    }
    return 1;
}
int solution(vector<int> nums) {
    int count = 0;
// 3개를 골라 더했을 때 소수가 되는 경우의 개수
    for(int i=0 ; i< nums.size(); i++){
            for(int j=i+1 ; j< nums.size(); j++){
                for(int k=j+1 ; k< nums.size(); k++){
                    count+=isPrimeNum(nums[i]+nums[j]+nums[k]);
    }
    }
    }
    return count;
}
