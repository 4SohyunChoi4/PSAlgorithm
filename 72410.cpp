#include <string>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include <bits/stdc++.h>
using namespace std;

bool IsBool (int i) { return ( !isalnum(i) && i!='-' && i!='.' && i!='_'); }

string solution(string new_id) {
    char point = '.';
    char end;
    
    //1단계
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower); 
    //2단계
    new_id.erase(remove_if(new_id.begin(), new_id.end(),IsBool),new_id.end());
    //3단계
    new_id.erase( unique( std::begin( new_id ), std::end( new_id ), 
                          [=]( const auto &c1, const auto &c2 ) { return c1 == point && c1 == c2; } ),
             std::end( new_id ) ); 
    //4단계
    if(new_id[0]=='.') new_id.erase(0,1);
    if(new_id[new_id.size()-1]=='.') new_id.erase(new_id.size()-1,1);
    //5단계
   if(new_id.size()==0)
        new_id+="a";
    //6단계
    if(new_id.size()>=16)
    {
        new_id.erase(15,new_id.size()-15);
        if(new_id[14]=='.')
            new_id.erase(14,1);
    }
    //7단계
    end=new_id[new_id.size()-1];
    while(new_id.size()<=2){
        new_id+=end;
    }
        
    return new_id;
}