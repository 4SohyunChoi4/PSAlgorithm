#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

bool comp(string a, string b){
    return a.size() < b.size();
}

bool solution(vector<string> phone_book) {
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());
    
    for(int i=0; i<phone_book.size()-1; i++){
        int min=0;
        //if(phone_book[i].size() < phone_book[i+1].size())
        //{
            min = phone_book[i].size();
            if(!phone_book[i].compare(phone_book[i+1].substr(0,min)))
                return false;
        //}
        /*else
        {
            min = phone_book[i+1].size();
            if(!phone_book[i+1].compare(phone_book[i].substr(0,min)))
                return false; 
        }*/
    }
    /*
    set<char> initial_num;
    set<string> duplicated_num;
    //phone_book을 길이 순으로 
        
    // 만약 첫번째 숫자가 다 다르다면 true로 끝
    for(int i=0; i<phone_book.size(); i++){
        initial_num.insert(phone_book[i][0]);
    }
    if(initial_num.size() == phone_book.size())
        return true;

// 만약 answer= false가 되면 바로 탈출
    for(int i=0; i<phone_book.size()-1; i++){
        for(int j=i+1; j <phone_book.size(); j++){
           if(phone_book[i][0] == phone_book[j][0]){
               //cout<<phone_book[i]<<" "<<phone_book[j].substr(0, phone_book[i].length())<<endl;
               if(phone_book[i].compare(phone_book[j].substr(0, phone_book[i].length()))==0)
                {
                    return false;
                }
             }
        }    
    }
    */
    return answer;
}
