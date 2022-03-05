#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;
struct genr{
    string name;
    int plays;
    genr(string str,int n){
        name = str;
        plays = n;
    }
};
struct song{
    int idx;
    int plays;
    song(int idx_,int plays_){
        idx = idx_;
        plays = plays_;
    }
};
struct sortSongs
{
	bool operator() (const song& left, const song& right) const
	{
		if (left.plays == right.plays) {
			return left.plays > right.plays;
		}
		else {
			return left.plays > right.plays;
		}
	}
};
struct sortGenr
{
	bool operator() (const genr& left, const genr& right) const
	{
		if (left.plays == right.plays) {
			return left.plays > right.plays;
		}
		else {
			return left.plays > right.plays;
		}
	}
};

vector<int> sortVectors(vector<song> &songs){  // Genre내 song을 sort 할 때 이용
    vector<int> sortedVector;
    multiset<song,sortSongs> sortedSet;
    for(auto s : songs){
        sortedSet.insert(s);
    }
    int i = 0;
    for(auto s: sortedSet){
        sortedVector.push_back(s.idx);
        if(++i ==2)
            break;
        //cout << s.plays << " " << s.idx << " " <<endl; test
    }
    return sortedVector;
}
vector<string> sortGenre(vector<genr> &genre){  // Genre내 song을 sort 할 때 이용
    vector<string> sortedVector;
    multiset<genr,sortGenr> sortedSet;
    for(auto s : genre){
        sortedSet.insert(s);
    }
    for(auto s: sortedSet){
        sortedVector.push_back(s.name);
        //cout << s.plays << " " << s.idx << " " <<endl; test
    }
    return sortedVector;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    // [장르 1(가장 많이 재생된 장르) , 많이 재생된 순으로] ... [장르 n(가장 적게 재생된 장르)]
    // 1. 장르별로 재생된 횟수를 알아야함
    // 2. 장르 내에서 많이 재생된 순서대로 정렬 - [고유번호 - 재생횟수]
    // 3. 장르별 플레이 횟수로 정렬
    // 4. 곡 별 플레이 횟수로 정렬
    // 5. 각 순서대로 push..
    
    map<string,int> genreCount; // Genre, plays
    map<string,vector<song>> genreMap;
    map<string,vector<int>> genreSongSorted;
    vector<genr> genrData;
    vector<string> sortedGenr;

    auto it= genres.begin();
    int idx = 0;
    while(it!=genres.end()){ // 각 장르에 음악을 넣는 과정
        const string Genre = genres[idx];
        const int Plays = plays[idx];
        genreCount[Genre] += plays[idx];
        song newSong(idx,plays[idx]);
        genreMap[Genre].push_back(newSong);
        it++,idx++;
    }
    for(auto g: genreCount){
        genr newGenr(g.first,g.second);
        genrData.push_back(newGenr);
    }
    sortedGenr = sortGenre(genrData);

    for(auto g :genreMap){
        genreSongSorted[g.first] = sortVectors(g.second);
    }
    for(auto g: sortedGenr){
        for(auto i: genreSongSorted[g]){
            answer.push_back(i);
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