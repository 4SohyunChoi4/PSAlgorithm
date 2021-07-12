#include <string>
#include <vector>

using namespace std;
vector<vector<int>> answer;
void Hanoi_Tower(int n, int from, int tmp, int to)
{
    vector <int> sub;
    if(n==1)
    {
        sub.push_back(from);
        sub.push_back(to);
        answer.push_back(sub);
    }
    else
    {
        Hanoi_Tower(n-1, from, to, tmp);
        sub.push_back(from);
        sub.push_back(to);
        answer.push_back(sub);
        Hanoi_Tower(n-1,tmp,from,to);
   }
}
vector<vector<int>> solution(int n) {
    Hanoi_Tower(n,1,2,3);
    return answer;
}