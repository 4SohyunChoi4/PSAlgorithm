#include <string>
#include <algorithm>
#include <ctype.h>
#include <vector>
#include <iostream>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int>::iterator iter;

    vector<int> num;
    string num_str="";
    for(int i=0 ; i < dartResult.size();i++){
        if(isdigit(dartResult[i])){//만약에 숫자이면
            if(dartResult[i]=='0' && isdigit(dartResult[i-1]) && i!=0){
                cout<<"실행"<<endl;
                num.back()=10;
            }
            else
                num.push_back(stoi(dartResult.substr(i,1)));
            continue;
        }
        switch(dartResult[i]){//문자이면 S D T에따라 
            case 'S':
                break;
            case 'D':
                num.back()*=num.back();
                 break;
            case 'T':
                num.back()*=num.back()*num.back();
                break;
            case '*':
                num.back()*=2;
                if(num.size()>1)
                    num[num.size()-2]*=2;
                break;
            case '#':
                num.back()*=-1;
                break;
          /*  case '0':
                num.back()=10;
               break;*/
        }
    }
    for(iter = num.begin(); iter != num.end() ; iter++){
        cout << *iter << " ";
        answer+=*iter;
    }
    
    
    //else이면
    // *이면 *2, #이면 -1
    return answer;
}