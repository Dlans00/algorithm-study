#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {    // 스택 하나 사용, O(n) 시간복잡도
    int n = prices.size();
    vector<int> answer(n, 0);
    stack<int> stk; 3 3 3 1 0   014    43110

    for(int i = 0; i < n; i++) {
        while(!stk.empty() && prices[stk.top()] > prices[i]) { // 다음 초에 감소한다고 판단되면 그 전의 감소한 모든 인덱스에서
            int idx = stk.top();
            stk.pop();  // 스택에서 pop하고

            answer[idx] = i - idx; // 해당 인덱스만 answer 원소값으로 (최초로 감소한 순간까지의 시간 차)할당
        }

        stk.push(i);
    } // 스택에는 다음 초에 감소하지 않는 인덱스들만 추가된 상태.

    while(!stk.empty()) {
        int idx = stk.top();
        stk.pop();

        answer[idx] = n - 1 - idx; // 감소하지 않은 인덱스들은 마지막 인덱스까지의 시간 차를 answer 원소값으로 할당
    }

    return answer;
}
int main() {
    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }       
    cout << "result : ";
    vector<int> answer = solution(prices);
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;   
}