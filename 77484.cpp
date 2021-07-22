#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int ranking(int num){
    switch(num)
    {
        case 6:
            return 1;
            break;
        case 5:
            return 2;
            break;
        case 4:
            return 3;
            break;
        case 3:
            return 4;
            break;
        case 2:
            return 5;
            break;
        default:
            return 6;
    }
}
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int min=0, max=0, worst_rank, best_rank;
    vector<int>::iterator it;
    
    int zero_num=0;
    //처음부터 끝까지 하나씩 for문으로 돌려서 find
    for( int i=0 ; i< win_nums.size() ; i++){
        if(lottos[i]==0){// 0의 개수는 미리 더해둔다
            zero_num++;
            continue;
        }
        it = find(win_nums.begin(), win_nums.end(), lottos[i]);
        if(it != win_nums.end())//값이 당첨번호에 있을 때
        {
            cout<<lottos[i]<<endl;
            min++;
            //win_nums[it-win_nums.begin()];
        }
    // 당첨확률 높아지려면 +(0의 개수), 아니면 아무것도 더하지 않는다
        
    }
    max = min + zero_num;
    answer.push_back(ranking(max));
    answer.push_back(ranking(min));

    return answer;
}