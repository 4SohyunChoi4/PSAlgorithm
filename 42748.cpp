#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<vector<int>>::iterator iter;
    //vector<int>::iterator iter2;
    
    for(iter=commands.begin();iter!=commands.end();iter++){
        int i= (*iter)[0];
        int j= (*iter)[1];
        int k= (*iter)[2];
        vector<int> new_arr(j-i+1);
        
        partial_sort_copy(array.begin()+i-1,array.begin()+j,new_arr.begin(), new_arr.end());
        
        /*for(iter2=new_arr.begin();iter2!=new_arr.end();iter2++)
        {
            cout<<*iter2<<" ";
        }
        cout<<endl;*/
        answer.push_back(new_arr[k-1]);
    }
    return answer;
}