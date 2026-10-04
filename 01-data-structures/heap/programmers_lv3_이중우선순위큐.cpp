#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <utility>

using namespace std;

vector<int> solution(vector<string> operations) {
    priority_queue<pair<int, int>> maxHeap;
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> minHeap;

    vector<bool> removed(operations.size(), false);

    for (int i = 0; i < operations.size(); i++) {
        int num = stoi(operations[i].substr(2));

        if (operations[i][0] == 'I') {
            maxHeap.push({num, i});
            minHeap.push({num, i});
        }
        else if (num == 1) {
            while (!maxHeap.empty() && removed[maxHeap.top().second])
                maxHeap.pop();

            if (!maxHeap.empty()) {
                removed[maxHeap.top().second] = true;
                maxHeap.pop();
            }
        }
        else {
            while (!minHeap.empty() && removed[minHeap.top().second])
                minHeap.pop();

            if (!minHeap.empty()) {
                removed[minHeap.top().second] = true;
                minHeap.pop();
            }
        }
    }

    while (!maxHeap.empty() && removed[maxHeap.top().second])
        maxHeap.pop();

    while (!minHeap.empty() && removed[minHeap.top().second])
        minHeap.pop();

    if (maxHeap.empty()) return {0, 0};

    return {maxHeap.top().first, minHeap.top().first};
}