#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int cnt = 0, sco_len = scoville.size();
    priority_queue<int, vector<int>, greater<int>> minheap;   // MinHeap을 우선순위 큐로 구현. greater<int>를 통해 오름차순 정렬.
    
    for(int i=0;i<scoville.size();i++) {
        minheap.push(scoville[i]);
    }

    int a, b;
    while(minheap.top()<K&&sco_len>=2) {  // 최소값이 K보다 작고, !!남아있는 원소가 2개 이상일 때(혼합 가능) 조건 추가!!
        a = minheap.top();
        minheap.pop();
        b = minheap.top();
        minheap.pop();
        
        minheap.push(a + 2 * b);
        cnt++;   // 섞은 횟수 증가
        sco_len--;  // 섞은 횟수만큼 원소가 줄어들기 때문에, 남아있는 원소의 개수도 1 감소
    }
    answer = cnt;
    if(minheap.top()<K) answer = -1;
    return answer;
}