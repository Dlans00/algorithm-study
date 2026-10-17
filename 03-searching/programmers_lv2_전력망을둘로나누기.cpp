#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

int dfs(int node, int parent, vector<vector<int>>& graph,
        int n, int& answer) {
    int count = 1;

    for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];
        if (next == parent) continue;

        count += dfs(next, node, graph, n, answer);
    }

    if (parent != 0) {
        answer = min(answer, abs(n - 2 * count));
    }

    return count;
}

int solution(int n, vector<vector<int>> wires) {
    vector<vector<int>> graph(n + 1);
    int answer = n;

    for (int i = 0; i < wires.size(); i++) {
        int a = wires[i][0];
        int b = wires[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0, graph, n, answer);
    return answer;
}