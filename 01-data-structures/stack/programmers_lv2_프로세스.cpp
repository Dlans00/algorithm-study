#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> q;
    queue<int> qidx;
    for(int j=0;j<priorities.size();j++) {
        q.push(priorities[j]);
        qidx.push(j);
    }
    int chk = 0;
    while(!q.empty()) {
        chk = 0;
        for(int i=0;i<priorities.size();i++) {
            if(q.front()<priorities[i]) {
                q.push(q.front());
                qidx.push(qidx.front());
                q.pop();
                qidx.pop();
                chk = 1;
                break;
            }
        }
        if(chk!=1) {
            answer++;
            if(qidx.front()==location) break; 
            priorities[qidx.front()] = -1;
            q.pop();
            qidx.pop();
        }
    }
    return answer;
}