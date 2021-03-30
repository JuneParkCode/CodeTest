#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays){
    typedef multimap<int,int,greater<int>> song;

    map<string,int> countGenre;
    multimap<int,string,greater<int>> sortedGenre;

    map<string,song> container_genr;

    vector<int> answer;
    
    auto it= genres.begin();
    int idx = 0;
    while(it!=genres.end()){ // 각 장르에 음악을 넣는 과정
        const string Genre = genres[idx];
        const int Plays = plays[idx];
        countGenre[Genre] += plays[idx];    // 처음에 empty key를 선언하고 연산이 되는 것에 주목.
        container_genr[Genre].insert(pair<int,int>(plays[idx],idx));
        it++,idx++;
    }

    for(auto m : countGenre){   // 플레이 횟수 많은 장르별로 sort
        sortedGenre.insert(pair<int,string>(m.second,m.first));
    }
    // 장르별 컨테이너에 플레이 순위로 정렬되었음.

    for(auto g: sortedGenre){    // answer에 순서대로 집어넣는 과정
        int count = 0;
        for(auto i : container_genr[g.second]){ //song pair
            int idx = i.second;
            answer.push_back(idx);
            if(++count  == 2)
                break;
        }
    }
    return answer;
}