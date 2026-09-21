#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q;

    for(int i = 0; i < priorities.size(); i++) {
        q.push({priorities[i], i});
    }

    int cnt = 0;

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        bool higher = false;

        for(int i = 0; i < priorities.size(); i++) {
            if(priorities[i] > cur.first) {
                higher = true;
                break;
            }
        }

        if(higher) {
            q.push(cur);
        }
        else {
            cnt++;
            priorities[cur.second] = 0;

            if(cur.second == location)
                return cnt;
        }
    }

    return cnt;
}