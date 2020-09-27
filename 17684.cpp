#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(string msg) {
    string w, c;
    int j;
    vector<int> answer;
    map<string,int> dic = {{"A",1},{"B",2}, {"C",3}, {"D",4},{"E",5},{ "F",6},{"G",7},{"H",8},{"I",9},{"J",10},{"K",11},{"L",12},{"M",13},{"N",14},{"O",15},{"P",16},{"Q",17},{"R",18},{"S",19},{"T",20},{"U",21},{"V",22},{"W",23},{"X",24},{"Y",25},{"Z",26}};
    
    for(int i=0;i<msg.length();){
        j=1;
      while(i+j!=msg.length() && dic.find(msg.substr(i,j+1)) != dic.end()){//그 다음 게 사전에 있으면
            j++;
        }           
/*        if(i==msg.length()-1){//마지막 한 글자는 c를 갖지 x
            w=msg.substr(i,j);
            answer.push_back(dic[w]); //answer에 출력
           break;
        }        */

       
        w=msg.substr(i,j);
        answer.push_back(dic[w]); //answer에 출력
        c=msg.substr(i+j,1);
    
        cout<<w<<endl;
            cout<<c<<endl;
            
            i+=w.length();//w의 길이만큼 i를 띄운다
            
            dic.insert(make_pair(w+c,dic.size()+1));//w+c를 사전에 추가
            cout<<"w+c: "<<w+c<<endl;
    }
    return answer;  
}