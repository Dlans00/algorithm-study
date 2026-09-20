#include<string>
#include<stack>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> stk;
    for(int i=0;i<s.size();i++) {
        if(s[i]=='(') stk.push('(');
        else if(stk.empty()) {
            answer = false;
            break;
        }
        else stk.pop();
    }
    if(stk.empty()==0) answer = false;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}