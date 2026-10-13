#include <algorithm>
#include <vector>

using namespace std;

int dfs(int k, vector<vector<int>>& dungeons, vector<bool>& used) {
    int answer = 0;

    for (int i = 0; i < dungeons.size(); i++) {
        if (used[i] || k < dungeons[i][0]) continue;

        used[i] = true;
        answer = max(answer, 1 + dfs(k - dungeons[i][1], dungeons, used));
        used[i] = false;
    }

    return answer;
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> used(dungeons.size(), false);
    return dfs(k, dungeons, used);
}