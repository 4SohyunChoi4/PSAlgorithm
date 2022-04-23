#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <memory.h>
using namespace std;

vector<int> graph[200];
int check[200];
int answer=0;

void dfs(int start) {
    stack<int> st;
    int sth;
    st.push(start);
    check[start] = true;
    cout<<start<<endl;
    while(!st.empty()) {
        int sth = st.top(); 
        st.pop();
        for(int i=0; i<graph[sth].size();i++){
            if(check[graph[sth][i]]== false){
                check[graph[sth][i]] = true;
                cout<<graph[sth][i]<<endl;
                st.push(graph[sth][i]);
                //break;
            }
        }
    }
    answer++;
}

int solution(int n, vector<vector<int>> computers) {
    memset(check, sizeof(check), false);
    for(int i=0; i<computers.size(); i++){
        for(int j=0 ; j< computers.size(); j++){
            int u, v;
            if(computers[i][j] == 1 && i != j)
            {                
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }    
    for(int i=0; i<computers.size();i++) {
        if(check[i]==false) dfs(i);
    }


    return answer;
}