#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string get_played_time(string s_time,string e_time)
{
    int start_time = stoi(s_time.substr(0,2)) * 60 + stoi(s_time.substr(3));
    int end_time = stoi(e_time.substr(0,2)) * 60 + stoi(e_time.substr(3));
    return to_string(end_time - start_time);
}
void get_scores(vector<string> &score_out,string score)
{
    int i=0;
    for(char c : score)
    {
        if( c == '#')
        {
            score_out[--i] += c;
        }
        else
        {
            score_out.push_back(string(1,c));
        }
        ++i;
    }
    return;
}
bool find(vector<string> &scores,vector<string> &melody,const int PLAY_TIME)
{
    const int M_LENGTH = melody.size();
    const int S_LENGTH = scores.size();
    
    int eq = 0;
    for(int i=0; i<PLAY_TIME; ++i)
    {
        if(eq==M_LENGTH)
            break;
        string &t_score = scores[i%S_LENGTH];
        string &m_score = melody[eq];
        if(t_score == m_score)
        {
            ++eq;
        }
        else
        {
            eq = 0;
        }
    }
    return eq==M_LENGTH;
}
// 음악 정보를 정리해서 내보냄.
// [0]      [1]        
// title    playedTime
void get_musicInfo(vector<vector<string>> &musicInfos,map<string,vector<string>> &musicScoreMap,const string s)
{
    const int SIZE = s.length();
    vector<string> temp;
    
    string tempStr = "";
    
    for(int i=0;i<SIZE;++i)
    {   
        if(s[i] == ',')
        {
            temp.push_back(tempStr);
            tempStr = "";
            ++i;
        }
        tempStr += string(1,s[i]);
    }
    temp.push_back(tempStr);

    // 음악 정보 기록
    string title = temp[2];
    string playedTime = get_played_time(temp[0],temp[1]);
    musicInfos.push_back({title,playedTime});
    
    // 악보 기록
    vector<string> scores;
    get_scores(scores,temp[3]);

    musicScoreMap[title] = scores;

    return;
}
string solution(string m, vector<string> musicinfos) {
    string answer;
    
    vector<string> melody;
    get_scores(melody,m);

    vector<vector<string>> music_info;
    map<string,vector<string>> musicScoreMap;
    // 문자열 정리 및 저장
    for(string s: musicinfos)
    {
        get_musicInfo(music_info,musicScoreMap,s);
    }

    int maximum = 0;
    for(vector<string> music : music_info)
    {
        string &title = music[0];
        int pTime = stoi(music[1]);
        vector<string> &scores = musicScoreMap[title];
        // 악보에 멜로디가 포함되고, 플레이 타임이 이전 정답보다 큰 경우...
        // answer를 변경함.
        if(find(scores,melody,pTime) && maximum < pTime)
        {
            answer = title;
        }
    }
    return answer;
}