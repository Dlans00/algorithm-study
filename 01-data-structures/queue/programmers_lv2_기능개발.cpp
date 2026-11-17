include <string>
#include <queue>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;

    for(int i = 0; i < progresses.size(); i++) { 
        int day = (100 - progresses[i] + speeds[i] - 1) / speeds[i]; // 남은 작업량을 작업 속도로 나눈 값을 올림하여 필요한 일수 계산
        q.push(day);
    }
    while(!q.empty()) { // 모든 기능이 배포될 때까지 반복
        int day = q.front(); // 가장 앞에 남은 기능의 완료일이 이번 배포일
        int cnt = 0;
        while(!q.empty() && q.front() <= day) { // 앞에서부터 이번 배포일까지 완료되는 기능들을 함께 배포
        // 아직 완료되지 않은 기능을 만나면 그 뒤의 기능도 배포할 수 없음
            q.pop();
            cnt++;
        }
        answer.push_back(cnt); // 이번 배포의 기능 수 저장
    }

    return answer;
}
