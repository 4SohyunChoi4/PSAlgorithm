#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    vector<int> stack;
    vector<int>::iterator iter;
    int answer = 0;
    stack.push_back(0);
    
    for(iter=moves.begin(); iter!=moves.end(); iter++)
    {
        //moves 값들 하나씩 board의 해당하는 위치에서 빼낸다
        for(int i=0; i<board.size(); i++)
        {
            if(board[i][*iter-1] != 0)
            {//제일 앞에서부터 탐색해서 0이 아니면
                if(stack.back()==board[i][*iter-1])
                { //만약 제일 뒤에 값이랑 같으면
                    stack.pop_back();//맨 뒤 값 없앤다
                    answer+=2; 
                }
                else 
                    stack.push_back(board[i][*iter-1]);//저장
                board[i][*iter-1]=0;//board 기존의 값을 0으로 바꾼다
                break;
            }
        }
    }
    //1,5,3,5,1,2,1,4 -> 4, 3, 1, 1, 3, 2, 0, 4
    return answer; //터뜨려 사라진 인형의 개수
}