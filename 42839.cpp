#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

vector<int> number;
vector<int> perms;

void permutation(int depth, int n, int r){
    int num = 0;
    if(depth == r){
        for(int i=0; i<r; i++){
            num*=10;
            num += number[i];
        }
        perms.emplace_back(num);
        return;
    }
    for(int i = depth; i<n ; i++){
        swap(number[depth], number[i]);
        permutation(depth+1, n, r);
        swap(number[depth], number[i]);
    }
}
int solution(string numbers) {
    int size = numbers.length();
    bool flag = true;
    
    //numbers에 있는 값들 하나씩 빼서 벡터에 넣는다
    for(int i=0; i < size ;i++){
        number.emplace_back(stoi(numbers.substr(i, 1)));
    }
 
    /*for(int i=1; i <= size ;i++){
        permutation(0, size, i); //size P i
    */
    
    for(int k=1; k<=size; k++){
        vector<int> check;
        for(int i=0; i<k ; i++)
            check.push_back(1);
        for(int i=0; i<size-k; i++)
            check.push_back(0);
        
        sort(check.begin(), check.end());
        
        do{          
            vector<int> comb;
            int num=0;
            for(int i=0; i<size; i++){

                if(check[i]==1){
                    //cout<<number[i]<<" ";
                    comb.emplace_back(number[i]);
                }
            }
            //cout<<endl;
                for(int i=0; i<comb.size(); i++){
                    //cout<<comb[i]<<" ";
                }
            sort(comb.begin(), comb.end());
            do{
                int num=0;
                for(int i=0; i<comb.size(); i++){
                    num*=10;
                    num += comb[i];   
                    //cout<<comb[i]<<" ";
                }
               // cout<<endl;
                perms.emplace_back(num);
            }while(next_permutation(comb.begin(), comb.end()));
        
        }while(next_permutation(check.begin(), check.end()));
    }
    
    //answer 중복 제거
    sort(perms.begin(), perms.end());
    perms.erase(unique(perms.begin(), perms.end()), perms.end());
    
    int answer = perms.size();
    //answer에 있는 값들 중에 소수가 있는지 찾는다
    for(int i=0; i<perms.size() ; i++){
        int num = perms[i];
        //cout<<num<<endl;
        if(num<2) {
            //cout<<"빠진 넘은:"<<num<<endl;
            answer--; 
        }
        else{
            for(int j=2; j<=num/2 ;j++){
                if(num%j ==0) {
                    //cout<<"빠진 넘은:"<<num<<endl;
                    answer--; 
                    break;
                }
            }
        }
    }
    return answer;
}