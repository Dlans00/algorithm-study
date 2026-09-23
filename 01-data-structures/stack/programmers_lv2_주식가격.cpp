#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n, 0);
    stack<int> stk;

    for(int i = 0; i < n; i++) {
        while(!stk.empty() && prices[stk.top()] > prices[i]) {
            int idx = stk.top();
            stk.pop();

            answer[idx] = i - idx;
        }

        stk.push(i);
    }

    while(!stk.empty()) {
        int idx = stk.top();
        stk.pop();

        answer[idx] = n - 1 - idx;
    }

    return answer;
}