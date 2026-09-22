#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    int time = 0, idx = 0, cur_cnt = 0, cur_w = 0;
    for(int i = 0; i < bridge_length; i++) {
        q.push(0);
    }
    while(idx<truck_weights.size()) {
        time++;
        cur_w-=q.front();
        if(q.front() != 0) {
            cur_cnt--;
        }
        q.pop();
        if((cur_cnt+1)<=bridge_length&&(cur_w+truck_weights[idx])<=weight) {
            q.push(truck_weights[idx]);
            cur_w+=truck_weights[idx];
            idx++;
            cur_cnt++;
        }
        else q.push(0);
    }
    answer = time+bridge_length;
    return answer;
}