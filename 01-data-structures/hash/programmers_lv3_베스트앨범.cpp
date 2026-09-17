#include <unordered_map>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> m;  // 장르별 총 재생횟수
    vector<string> genarr;  // 장르 종류 배열
    vector<pair<int, string>> plygen;  // 장르별 총횟수 순위

    for(int i=0;i<genres.size();i++) {  // 해시 m에 장르별 총 재생횟수 합하기 
        string str = genres[i];
        if(m[str]==0) genarr.push_back(str); // 장르 종류도 벡터genarr에 추가
        m[str] += plays[i];
    }
    for(int j=0;j<genarr.size();j++) {  // 벡터 plygen에 장르랑 총횟수 넣고 
        plygen.push_back({m[genarr[j]], genarr[j]});
    }
    sort(plygen.rbegin(), plygen.rend());  // 이어서 plygen을 총횟수 크기순으로 정렬 

    for(int q=0;q<genarr.size();q++) {  // 총횟수가 큰 장르대로 두곡 뽑기
        vector<pair<int, int>> plyarr;
        for(int k=0;k<genres.size();k++) {
            if(genres[k]==plygen[q].second) plyarr.push_back({-plays[k], k});
        }
        sort(plyarr.begin(), plyarr.end());  // 해당 장르를 재생횟수 순대로 정렬
        //  장르별로 재생횟수 많은 순으로 2개씩 뽑기 
        answer.push_back(plyarr[0].second);
        if(plyarr.size()>=2) answer.push_back(plyarr[1].second);
    }
    
    return answer;
}