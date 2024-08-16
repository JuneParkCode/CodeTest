#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<vector<int>> test(1,vector<int>(1,0));

    cout << test[0][0] << endl;;
    cout << test[0].size() << endl;
    test[0].clear();
    cout << test[0].size() << endl;
}