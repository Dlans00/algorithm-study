#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef struct {
    int job_num;
    int job_reqtime;
    int job_time;
} element;

// 우선순위 큐의 비교 기준
struct compare {
    bool operator()(const element& a, const element& b) const {
        if (a.job_time != b.job_time) {
            return a.job_time > b.job_time;
        }

        if (a.job_reqtime != b.job_reqtime) {
            return a.job_reqtime > b.job_reqtime;
        }

        return a.job_num > b.job_num;
    }
};

// 아직 큐에 넣지 않은 작업들을 요청 시각순으로 정렬
bool requestCompare(const element& a, const element& b) {
    if (a.job_reqtime != b.job_reqtime) {
        return a.job_reqtime < b.job_reqtime;
    }

    return a.job_num < b.job_num;
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int count = jobs.size();

    vector<element> arr;
    priority_queue<element, vector<element>, compare> pq;

    for (int i = 0; i < count; i++) {
        arr.push_back({i, jobs[i][0], jobs[i][1]});
    }

    sort(arr.begin(), arr.end(), requestCompare);

    int cur_t = 0;
    int idx = 0;  // 아직 큐에 넣지 않은 첫 작업의 위치

    while (idx < count || !pq.empty()) {
        // 대기 작업이 없으면 다음 작업의 요청 시각까지 이동
        if (pq.empty() && idx < count) {
            cur_t = max(cur_t, arr[idx].job_reqtime);
        }

        // 현재 시각까지 요청된 작업을 모두 큐에 추가
        while (idx < count && arr[idx].job_reqtime <= cur_t) {
            pq.push(arr[idx]);
            idx++;
        }

        // 가장 우선순위가 높은 작업 하나만 처리
        element current = pq.top();
        pq.pop();

        cur_t += current.job_time;
        answer += cur_t - current.job_reqtime;
    }

    return answer / count;
}