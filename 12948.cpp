#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    //전화번호의 뒷 4자리를 제외한 나머지 숫자를 전부 *으로 가린 문자열
    int size = phone_number.size();
    string star = "";
    for(int i=0 ; i < size-4; i++)
        star+="*";
    phone_number.replace(0,size-4,star);
    return phone_number;
}