#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;
int i;
bool compare (string a, string b) {
    return a[i] == b[i] ? a < b : a[i] < b[i];
}
string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    //vector<<vector> string> table_ss;
    vector<string> table_ss;
    vector<int> score(table.size());
    string temp;
    stringstream ss;
    sort (table.begin(), table.end(), compare); //table을 미리 사전순으로 정렬*점수 중복의 경우 고려)

    for(int i=0; i<table.size() ; i++){
        stringstream ss;
        ss.str(table[i]);
        int k=0;
        while(ss >> temp)// si, java, javascript sql python c#(size-index)
        {
            int num = find(languages.begin(), languages.end(),temp) - languages.begin();
            if(num != languages.size()){
                //temp값이 languages내에 있으면
                score[i]+=(table.size()-k+1)*preference[num]; // 인덱스값 * preference값(language의 index값과 같다)
            }
            k++;
        }
    }
   for(int i =0 ; i< score.size() ; i ++){
       cout<< score[i] <<endl;
   }


    //answer=table[max_element(score.begin(),score.end())-score.begin()];
    ss.str(table[max_element(score.begin(),score.end())-score.begin()]);
    ss>>temp;
    return temp;
}