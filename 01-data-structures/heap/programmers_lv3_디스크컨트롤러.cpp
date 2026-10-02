#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Job {
    int time;
    int start;
    int num;
};

struct cmp {
    bool operator()(Job a, Job b) {
        if(a.time != b.time) return a.time > b.time;
        if(a.start != b.start) return a.start > b.start;
        return a.num > b.num;
    }
};

int solution(vector<vector<int>> jobs) {
    int n = jobs.size();

    vector<vector<int>> arr;
    for(int i = 0; i < n; i++) {
        arr.push_back({jobs[i][0], jobs[i][1], i});
    }

    sort(arr.begin(), arr.end());

    priority_queue<Job, vector<Job>, cmp> pq;

    int idx = 0;
    int now = 0;
    int total = 0;

    while(idx < n || !pq.empty()) {

        while(idx < n && arr[idx][0] <= now) {
            pq.push({arr[idx][1], arr[idx][0], arr[idx][2]});
            idx++;
        }

        if(pq.empty()) {
            now = arr[idx][0];
            continue;
        }

        Job cur = pq.top();
        pq.pop();

        now += cur.time;
        total += now - cur.start;
    }

    return total / n;
}