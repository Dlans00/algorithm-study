#include <string>

using namespace std;

int solution(string word) {
    string vowels = "AEIOU";
    int weight[] = {781, 156, 31, 6, 1};
    int answer = 0;

    for (int i = 0; i < word.size(); i++) {
        answer += vowels.find(word[i]) * weight[i] + 1;
    }

    return answer;
}