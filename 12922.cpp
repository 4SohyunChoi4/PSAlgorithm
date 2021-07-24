#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int num;
    for(int i=0 ; i< n/2 ; i++){
        answer+= "수박"; //n의 반 개수만큼
    }
    if(n%2==1) answer+="수";//n의 나머지가 1이면 수 를 붙임

    return answer;
}