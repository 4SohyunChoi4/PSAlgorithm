#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> int_answer; // 임시로 숫자로 넣을 공간

    for(int i=0;i<n;i++)
        int_answer.push_back(arr1[i] | arr2[i]); // temp에 bit연산한 결과 값을 넣는다.
    
    for(int i=0; i<n ;i++) 
    {   
        int temp=int_answer[i];
        string bin; //2진수로 바꾼걸 string으로 저장하도록 한다
        while(temp>=1)
        {
            if(temp%2==1)
                bin+="#";
            else
                bin+=" ";
            temp/=2;
        }
      //  answer.push_back(reverse(bin.begin(),bin.end()));
        while((bin.size())<n)
                bin+=" ";
        reverse(bin.begin(), bin.end());
        answer.push_back(bin);
        //cout<<bin<<endl;
    }
    return answer;
}