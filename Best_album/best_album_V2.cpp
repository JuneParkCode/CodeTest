#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

struct GreaterInt
{
	bool operator() (const int& left, const int& right) const
	{
		if (left == right) {
			return left > right;
		}
		else {
			return left > right;
		}
	}
};
vector<int> solution(vector<string> genres, vector<int> plays){
    typedef multimap<int,int,GreaterInt> song;

    map<string,int> countGenre;
    multimap<int,string,GreaterInt> sortedGenre;

    map<string,song> container_genr;

    vector<int> answer;
    
    auto it= genres.begin();
    int idx = 0;
    while(it!=genres.end()){ // 각 장르에 음악을 넣는 과정
        const string Genre = genres[idx];
        const int Plays = plays[idx];
        countGenre[Genre] += plays[idx];    // ****
        container_genr[Genre].insert(pair<int,int>(plays[idx],idx));
        it++,idx++;
    }

    for(auto m : countGenre){   // 플레이 횟수 많은 장르별로 sort
        sortedGenre.insert(pair<int,string>(m.second,m.first));
    }

    for(auto g: sortedGenre){    // sort된 순서대로 장르 이름
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
int main(){
    vector<string> genres {"classic", "pop", "classic", "classic", "pop"};
    vector<int> plays {500, 600, 150, 800, 2500};
    vector<int> ans = solution(genres,plays);
    for(auto i : ans){
        cout <<  i << " ";
    }
    return 0;
}