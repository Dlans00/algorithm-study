#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    stack<int> ing;
    stack<int> comp;
    vector<int> cur_trucks_time;
    int time = 0, idx = 0, cur_cnt = 0, cur_w = 0;
    for(int k=0;k<truck_weights.size();k++) cur_trucks_time.push_back(0);
    while(comp.size()!=truck_weights.size()) {
        time++;
        for(int i=0;i<cur_trucks_time.size();i++) {
            if(cur_trucks_time[i]!=0) cur_trucks_time[i]++;
        }
        if((cur_cnt+1)<=bridge_length&&(cur_w+truck_weights[idx])<=weight) {
            ing.push(truck_weights[idx]);
            cur_trucks_time[idx] = 1;
            cur_w+=truck_weights[idx];
            idx++;
            cur_cnt++;
        }
        for(int j=0;j<cur_trucks_time.size();j++) {
            if(cur_trucks_time[j]==bridge_length) {
                comp.push(ing.top());
                ing.pop();
                cur_cnt--;
                cur_w-=truck_weights[j];
            }
        }
    }
    answer = time+1;
    return answer;
}