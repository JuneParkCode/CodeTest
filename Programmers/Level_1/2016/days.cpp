#include <string>
#include <vector>
using namespace std;

string solution(int month, int day) {
    vector<string> days {"SUN","MON","TUE","WED","THU","FRI","SAT"};
    vector<int> monthdays {31,29,31,30,31,30,31,31,30,31,30,31};
    const int C = 4; // 01.01.2016 = friday... idx == 5 , (d + C)%7 == idx
    int totalday = 0;
    for(int i=0; i<month-1; i++)
        day += monthdays[i];
    totalday += day;
    return days[(totalday + C) % 7];
}