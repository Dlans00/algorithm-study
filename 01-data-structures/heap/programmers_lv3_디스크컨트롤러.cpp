#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;

typedef struct{
    int job_time;
    int job_reqtime;
    int jod_num;
} element;

struct compare {
    bool operator()(element a, element b) {
        if(a.job_time!=b.job_time) return a.job_time>b.job_time;
        else if(a.job_reqtime!=b.job_reqtime) return a.job_reqtime>b.job_reqtime;
        else return a.jod_num>b.jod_num;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    vector<vector<int>> arr;
    priority_queue<element, vector<element>, compare> pq;
    for(int i=0;i<jobs.size();i++) {
        arr.push_back({jobs[i][0], jobs[i][1], i});   // 요청 시각, 소모 시간, 작업번호
    }
    
    sort(arr.begin(), arr.end());
    
    int cur_t = 0, idx = 0, chk = 0;
    while(chk<jobs.size()) {
        while(idx<jobs.size()&&cur_t>=arr[idx][0]) {
            pq.push({arr[idx][1], arr[idx][0], arr[idx][2]});
            idx++;
        }

        if(!pq.empty()) {
                cur_t+=pq.top().job_time;
                answer+=cur_t-pq.top().job_reqtime;

                pq.pop();
                chk++;
        }
        else cur_t++;

    }
    answer/=jobs.size();
    return answer;
}