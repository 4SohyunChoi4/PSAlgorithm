#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums) //. N마리 폰켓몬의 종류 번호가 담긴 배열
{
    int answer = 0; //가장 많은 종류의 폰켓몬을 선택하는 방법을 찾아, 그때의 폰켓몬 종류 번호의 개수
    int half_size = nums.size() / 2;
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    //unique한 총 개수
    answer=nums.size();
    //만약 전체 N/2 개수보다 unique한 값이 크면
    if(answer > half_size)
        answer = half_size;
    //N/2를 리턴한다
    return answer;
}