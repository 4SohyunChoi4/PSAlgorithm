#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> d, int budget) {
//부서별로 신청한 금액이 들어있는 배열 d, 예산 budget
    int count = 0; //최대 몇 개의 부서에 물품을 지원할 수 있는지
    vector<int>::iterator it;
    //d를 오름차순으로 정렬한다
    sort(d.begin(), d.end());

    //첫번째부터 끝까지 반복문으로 빼본다
    for(it=d.begin();it!=d.end();it++){
        if(budget - *it < 0)
            break;
        budget -= *it;
        count++;
    }
    //그 다음을 뺐을 때 -가되면 (do while로)
    
    
    return count;
}