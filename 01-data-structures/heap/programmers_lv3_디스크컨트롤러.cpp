#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;

typedef struct{
    int job_time; // 작업 소모 시간
    int job_reqtime; // 작업 요청 시간
    int jod_num; //작업 번호
} element;

struct compare { // 작업 소모 시간, 요청 시간, 번호순으로 정렬
    bool operator()(element a, element b) {
        if(a.job_time!=b.job_time) return a.job_time>b.job_time;
        else if(a.job_reqtime!=b.job_reqtime) return a.job_reqtime>b.job_reqtime;
        else return a.jod_num>b.jod_num;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    vector<vector<int>> arr;
    priority_queue<element, vector<element>, compare> pq; // compare로 힙 정렬
    for(int i=0;i<jobs.size();i++) {
        arr.push_back({jobs[i][0], jobs[i][1], i});   // 요청 시각, 소모 시간, 작업번호
    }
    
    sort(arr.begin(), arr.end()); // 요청시간으로 먼저 정렬한 후(arr배열 원소순)
    
    int cur_t = 0, idx = 0, chk = 0;
    while(chk<jobs.size()) {
        while(idx<jobs.size()&&cur_t>=arr[idx][0]) { // 요청시간이 현재시각보다 이르고 전체 작업 수 끝날 때까지
            pq.push({arr[idx][1], arr[idx][0], arr[idx][2]}); // 힙에 삽입
            idx++;
        }

        if(!pq.empty()) { // 매번 힙이 비어있지 않으면 작업 하나 소모
                cur_t+=pq.top().job_time;
                answer+=cur_t-pq.top().job_reqtime;

                pq.pop(); // 해당 작업 힙에서 제외
                chk++;
        }
        else cur_t++;

    }
    answer/=jobs.size();
    return answer;
}
