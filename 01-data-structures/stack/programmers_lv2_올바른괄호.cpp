#include<string>
#include<stack>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> stk; // 아직 짝을 찾지 못한 여는 괄호 저장
    
    for(int i=0;i<s.size();i++) {
        if(s[i]=='(') stk.push('('); // 여는 괄호이면 스택에 저장
        else if(stk.empty()) { // 닫는 괄호인데 짝이 될 여는 괄호가 없으면 올바르지 않음
            answer = false;
            break;
        }
        else stk.pop(); // 닫는 괄호와 짝이 되는 여는 괄호 하나 제거
    }
    if(stk.empty()==0) answer = false; // 여는 괄호가 남아 있으면 짝이 맞지 않으므로 false

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}
