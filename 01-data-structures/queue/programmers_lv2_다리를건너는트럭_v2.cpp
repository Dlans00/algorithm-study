#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {   // !!!! 가장 효율적인 방법 !!!!
    int answer = 0;
    queue<int> q;
    int time = 0, idx = 0, cur_cnt = 0, cur_w = 0;
    for(int i = 0; i < bridge_length; i++) {
        q.push(0);
    }
    while(idx<truck_weights.size()) { // 모든 트럭이 다리에 진입할 때까지 반복
        time++;
        cur_w-=q.front(); // 다리 맨 앞 칸을 비움: 트럭이 있으면 무게와 트럭 수 차감
        if(q.front() != 0) {
            cur_cnt--;
        }
        q.pop();
        if((cur_cnt+1)<=bridge_length&&(cur_w+truck_weights[idx])<=weight) { // 다음 트럭이 진입해도 다리 길이와 최대 하중을 넘지 않는 경우
            q.push(truck_weights[idx]);
            cur_w+=truck_weights[idx];
            idx++; // 다음 트럭을 가리키도록 이동
            cur_cnt++;
        }
        else q.push(0); // 진입할 수 없으면 맨 뒤 칸을 빈칸으로 채움
    }
    answer = time+bridge_length;
    return answer;
}
