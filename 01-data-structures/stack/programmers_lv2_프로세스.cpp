#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> q;
    queue<int> qidx;
    
    for(int j=0;j<priorities.size();j++) { // 우선순위와 원래 인덱스를 같은 순서로 저장
        q.push(priorities[j]);
        qidx.push(j);
    }
    
    int chk = 0;
    while(!q.empty()) {
        chk = 0;
        
        for(int i=0;i<priorities.size();i++) {
            if(q.front()<priorities[i]) { // 우선순위가 더 높은 프로세스가 있으면 현재 프로세스를 뒤로 이동
                q.push(q.front());
                qidx.push(qidx.front());
                q.pop();
                qidx.pop();
                chk = 1;
                break;
            }
        }
        if(chk!=1) { // 우선순위가 더 높은 프로세스가 없으면 현재 프로세스 실행
            answer++;
            
            if(qidx.front()==location) break; 
            
            priorities[qidx.front()] = -1; // 실행된 프로세스는 이후 우선순위 비교에서 제외
            q.pop();
            qidx.pop();
        }
    }
    return answer;
}
