#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double average = 0;
    double sum =0;
    vector<int>::iterator iter;
    for(iter=arr.begin() ; iter != arr.end(); iter++){
        sum+=*iter;
    }
    average = sum/arr.size();
    return average;
}