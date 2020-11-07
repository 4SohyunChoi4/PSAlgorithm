#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}
*/

vector<int> solution(vector<vector<int>> v) { 
    vector<int> ans; // x, y 이렇게 들어갈 것..
    
    vector<int> x; //x좌표만
    vector<int> y; //y좌표만

    for(int i=0;i<3;i++){
        x.push_back(v[i][0]);
        y.push_back(v[i][1]);
        
    }
    sort(x.begin(), x.end()); // x좌표 기준으로 정렬
    sort(y.begin(), y.end()); // y좌표 기준으로 정렬
    if (x[0]==x[1])
        ans.push_back(x[2]);
    else 
        ans.push_back(x[0]);
 
    if (y[0]==y[1])
        ans.push_back(y[2]);
    else 
        ans.push_back(y[0]);    
    return ans;
}

int main(){
/*
[[1, 4], [3, 4], [3, 10]]	[1, 10]
[[1, 1], [2, 2], [1, 2]]	[2, 1]
*/
    vector<vector<int>> input;
    vector <int> sub;
    vector<vector<int>>:: iterator iter;
    
    input.push_back(sub);
    input.push_back(sub);
    input.push_back(sub);

    input[0].push_back(1);
    input[0].push_back(4);

    input[1].push_back(3);
    input[1].push_back(4);
    
    input[2].push_back(3);
    input[2].push_back(10);
    
    //input.push_back(sub);
    input.push_back(solution(input)); 

    for(int i=0;i<4;i++)
            cout<<input[i][0]<<"\t"<<input[i][1]<<endl;
}



