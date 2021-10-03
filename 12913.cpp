#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<vector<int> > land)
{
    int rear = land.size() -1;
    
    for( int i = 0 ; i < rear ; i++){
        //for( int j = 0 ; i < 4 ; i++)
        land[i+1][0] += max(land[i][1],max(land[i][2], land[i][3]));
        land[i+1][1] += max(land[i][0],max(land[i][2], land[i][3]));
        land[i+1][2] += max(land[i][0],max(land[i][1], land[i][3]));
        land[i+1][3] += max(land[i][0],max(land[i][1], land[i][2]));
    }
    
    return *max_element(land[rear].begin(), land[rear].end());
}