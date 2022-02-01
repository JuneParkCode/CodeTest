#include <string>
#include <vector>
#include <regex>
#include <iostream>
#include <set>
#include <map>

using namespace std;


long long time2int(string time){
    regex REG("([0-9]{2}):([0-9]{2}):([0-9]{2})");
    smatch matches;
    int h,m,s;
    if(regex_search(time,matches,REG)){
        h = stoi(matches[1].str());
        m = stoi(matches[2].str());
        s = stoi(matches[3].str());
    } 
    return h*3600 + m*60 + s;
}

string addZero(long long n){
    if(n<10){
        return "0"+to_string(n);
    } else {
        return to_string(n);
    }
}

string int2time(long long n){
    const int h = n/3600;
    const int m = (n - 3600*h)/60;
    const int s = (n - 3600*h - 60*m);
    return addZero(h)+":"+addZero(m)+":"+addZero(s);
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    long long lPlayTime = time2int(play_time);
    long long lAdvTime = time2int(adv_time);
    if(lPlayTime <= lAdvTime) return "00:00:00";

    set<long long> timeSet;
    map<long long, int> timeMap;
    vector<pair<long long, long long>> intLogs;

    regex rex("([0-9]{2}:[0-9]{2}:[0-9]{2})-([0-9]{2}:[0-9]{2}:[0-9]{2})");
    for(const string log : logs){
        smatch matches;
        if(regex_search(log, matches, rex)){
            const long long sTime = time2int(matches[1].str());
            const long long eTime = time2int(matches[2].str());
            timeSet.insert(sTime);
            timeSet.insert(eTime);
            intLogs.push_back({sTime,eTime});
        }
    }
    int i = 0;
    vector<long long> temp(timeSet.begin(), timeSet.end());
    vector<vector<long long>> bar;
    for(int i=0; i<temp.size(); i++){
        // time, count, duration
        const int duration = i<(temp.size()-1)? temp[i+1] - temp[i] : 0;
        bar.push_back({temp[i],0,duration});
        timeMap.insert({temp[i],i});
    }
    for(auto p : intLogs){
        auto sTime = p.first;
        auto eTime = p.second;
        for(int i = timeMap[sTime]; bar[i][0] < eTime; i++){
            if (sTime <= bar[i][0] && bar[i][0] < eTime) {
				bar[i][1]++;
			}
        }
    }
    
    long long max = 0;
    long long res = 0;
    for(int i = 0 ; i<bar.size() -1; i++){
        const long long sTime = bar[i][0];
        const long long eTime = sTime + lAdvTime;
        long long acc = 0;
        for(int j=i; j<bar.size(); j++){
            const long long time = bar[j][0];
            const long long count = bar[j][1];
            const long long duration = bar[j][2];
            if(time > eTime) break;
            if(time + duration <= eTime){
                acc += count * duration;
            } else {
                acc += (eTime - time) * count;
            }
        }
        if( max < acc ){
            max = acc;
            res = sTime;
        }
    }
    answer = int2time(res);
    return answer;
}

