#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {   // !!!! Queue pair을 이용한 방법 !!!!
    int answer = 0;
    queue<pair<int, int>> q; // 넣은 time, weight
    int time = 0, idx = 0, cur_cnt = 0, cur_w = 0;
    while(idx < truck_weights.size() || !q.empty()) {
        time++;
        if(!q.empty() && (time-q.front().first==bridge_length)) {
            cur_cnt--;
            cur_w-=q.front().second;
            q.pop();
        }
        if(idx < truck_weights.size()&&(cur_cnt+1)<=bridge_length&&(cur_w+truck_weights[idx])<=weight) {
            q.push({time, truck_weights[idx]});
            cur_w+=truck_weights[idx];
            idx++;
            cur_cnt++;
        }
    }
    answer = time;
    return answer;
}