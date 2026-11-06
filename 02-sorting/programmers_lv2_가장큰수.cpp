#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {    // sort 함수에서 정렬 비교규칙을 정의하는 함수. 
    return a + b > b + a;   // 이어붙였을 때 더 큰 값을 앞으로 오게 정렬.
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;

    for(int i = 0; i < numbers.size(); i++) {
        v.push_back(to_string(numbers[i]));
    }

    sort(v.begin(), v.end(), compare);  // compare 함수를 이용하여 정렬

    for(int i = 0; i < v.size(); i++) {
        answer += v[i];
    }

    if(answer[0] == '0') return "0";  // 가장 앞에 온 숫자가 0이면 뒤의 모든 숫자가 0이므로 "0"을 반환

    return answer;
}