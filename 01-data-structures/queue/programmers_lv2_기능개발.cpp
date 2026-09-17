#include <string>
#include <queue>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;

    for(int i = 0; i < progresses.size(); i++) {
        int day = (100 - progresses[i] + speeds[i] - 1) / speeds[i];
        q.push(day);
    }
    while(!q.empty()) {
        int day = q.front();
        int cnt = 0;
        while(!q.empty() && q.front() <= day) {
            q.pop();
            cnt++;
        }
        answer.push_back(cnt);
    }

    return answer;
}