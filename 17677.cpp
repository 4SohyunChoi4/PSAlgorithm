#include <string>
#include <iostream>
#include <vector>
#include <ctype.h>
#include <algorithm>
using namespace std;

int solution(string str1, string str2) {
    string temp1, temp2;
    float jacard;
    int answer;
    int min_size, max_size;
    vector <string> str1_v, str2_v, intersect_v, union_v;
//    vector <string>::iterator it;

    if(str1.length()>=1){
        //str1_v
        for(int i=0;i<str1.length()-1;i++){
                 if(isalpha(str1[i]) && isalpha(str1[i+1]))//첫, 두번째 자리가 문자일 때
                    {
                        temp1=str1.substr(i,2);
                        transform(temp1.begin(),temp1.end(),temp1.begin(),::tolower);//소문자로               
                        str1_v.push_back(temp1);
                    }
       //     else
        //        continue;
        }
   }
    if(str2.length()>=1){
        //str2_v
        for(int i=0;i<str2.length()-1;i++){
                 if(isalpha(str2[i]) && isalpha(str2[i+1]))//첫, 두번째 자리가 문자일 때
                    {
                        temp2=str2.substr(i,2);
                        transform(temp2.begin(),temp2.end(),temp2.begin(),::tolower);//소문자로               
                        str2_v.push_back(temp2);
                    }
           // else
           //     continue;
        }
    }
    /*
    for(it=str1_v.begin();it!=str1_v.end();it++)
        cout<<"str1 : "<<*it<<endl;
    cout<<endl;
    for(it=str2_v.begin();it!=str2_v.end();it++)
        cout<<"str2 : "<<*it<<endl;
    cout<<endl;
    */
    //intersect_v
    vector <string> temp(str1_v); 
    sort(temp.begin(),temp.end());
    temp.erase(unique(temp.begin(),temp.end()),temp.end());//str1에서 중복 제거한 temp
    for(int i=0;i<temp.size();i++)
        if(find(str2_v.begin(),str2_v.end(),temp[i])!=str2_v.end()){ //str1에 있는 값이 str2에도 있으면(중복이면)
            min_size=min(count(str1_v.begin(),str1_v.end(),temp[i]),count(str2_v.begin(),str2_v.end(),temp[i])); //적은 개수 만큼 추가(교집합)
            for(int k=0;k<min_size;k++)
                intersect_v.push_back(temp[i]);
            }
    
    temp.insert(temp.end(), str2_v.begin(), str2_v.end() );//temp에서 나오는 값 전부 합침
    sort(temp.begin(),temp.end());
    temp.erase(unique(temp.begin(),temp.end()),temp.end());//str1에서 중복 제거한 temp
    for(int i=0;i<temp.size();i++){
            max_size=max(count(str1_v.begin(),str1_v.end(),temp[i]),count(str2_v.begin(),str2_v.end(),temp[i])); //많은 개수 만큼 추가(합집합)
            for(int k=0;k<max_size;k++)
                union_v.push_back(temp[i]);    
    }
    /*
    for(it=intersect_v.begin();it!=intersect_v.end();it++)
        cout<<"intersect : "<<*it<<endl;
    cout<<endl;
    for(it=union_v.begin();it!=union_v.end();it++)
        cout<<"union : "<<*it<<endl;
    cout<<endl; 
    */
    if(union_v.empty() && intersect_v.empty())// 집합 A와 집합 B가 모두 공집합일 경우
        jacard=1.0;
    else
        jacard=float(intersect_v.size())/float(union_v.size());
    answer=int(jacard * 65536);
    return answer;
}