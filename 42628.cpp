#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> min_q; //낮은 순으로(오름차순)
    priority_queue<int, vector<int>, less<int>> max_q;
    int num = operations.size();
    int cnt =  0;
    for(int j=0; j<num ; j++) {
        if(operations[j][0]=='I'){
        min_q.push(stoi(operations[j].substr(2)));
        max_q.push(stoi(operations[j].substr(2)));
        cnt++;
        }
        else if(cnt > 0){ // D가 들어왔을 때
            if(operations[j].substr(2) == "-1") { //최솟값 빼기
                min_q.pop();
            }
            else{
                max_q.pop();
            }
            cnt--;
        }
        if(cnt == 0)
        {
            while(!min_q.empty()) min_q.pop();
            while(!max_q.empty()) max_q.pop();
        }
    }
    if(cnt == 0){
            answer.push_back(0);
            answer.push_back(0);
        }
        else{            
            answer.push_back(max_q.top());
            answer.push_back(min_q.top());
        }
    return answer;
}
