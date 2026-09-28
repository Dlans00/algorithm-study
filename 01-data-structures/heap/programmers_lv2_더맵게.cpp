#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for (int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }

    int answer = 0;

    while (pq.top() < K) {
        if (pq.size() < 2) return -1;

        long long first = pq.top();
        pq.pop();

        long long second = pq.top();
        pq.pop();

        long long mixed = first + second * 2;

        pq.push(mixed);
        answer++;
    }

    return answer;
}