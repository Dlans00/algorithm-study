#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_set<string> s(phone_book.begin(), phone_book.end());
    
    for(int i=0;i<phone_book.size();i++) {
        
        for(int j=1;j<phone_book[i].size();j++) { // 길이 1부터 전화번호 길이 - 1까지 확인하여 자기 자신은 제외
            string str = phone_book[i].substr(0, j); // 앞에서 j글자를 추출
            
            if(s.find(str)!=s.end()) { // 접두어와 일치하는 전화번호가 집합에 있으면 조건 위반
                answer = false;
                break; // 현재 전화번호의 접두어 검사 종료
            }
        }
    }
    return answer;
}
