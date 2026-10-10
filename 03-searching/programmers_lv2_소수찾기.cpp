#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int dfs(string& numbers, vector<bool>& used,
        unordered_set<int>& checked, int num) {
    int count = 0;

    for (int i = 0; i < numbers.size(); i++) {
        if (used[i]) continue;

        int next = num * 10 + (numbers[i] - '0');

        if (checked.insert(next).second && isPrime(next)) {
            count++;
        }

        used[i] = true;
        count += dfs(numbers, used, checked, next);
        used[i] = false;
    }

    return count;
}

int solution(string numbers) {
    vector<bool> used(numbers.size(), false);
    unordered_set<int> checked;

    return dfs(numbers, used, checked, 0);
}