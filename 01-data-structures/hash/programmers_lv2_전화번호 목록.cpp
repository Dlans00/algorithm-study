#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_set<string> s(phone_book.begin(), phone_book.end());
    for(int i=0;i<phone_book.size();i++) {
        for(int j=1;j<phone_book[i].size();j++) {
            string str = phone_book[i].substr(0, j);
            if(s.find(str)!=s.end()) {
                answer = false;
                break;
            }
        }
    }
    return answer;
}