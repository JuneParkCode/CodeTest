#include <iostream>
#include <algorithm>
#include <vector>

// DEFINE TO SOLVE
#define NM_IN_CM 10000000
#define LIMITS_OF_LEGO_N 1000000
// MACRO FUNCTIONS
#define NM2CM(nm) (nm / NM_IN_CM)
#define CM2NM(cm) (cm * NM_IN_CM)

using namespace std;

int WIDTH;
int NUMBER_OF_LEGO;
int *LEGOS;

void getInput(const int a)
{
    WIDTH = CM2NM(a);
    cin >> NUMBER_OF_LEGO;
    LEGOS = new int[NUMBER_OF_LEGO];
    for (int i = 0; i < NUMBER_OF_LEGO; ++i)
        cin >> LEGOS[i];
    sort(LEGOS, LEGOS + NUMBER_OF_LEGO);
}

void solver()
{
    long long res;
    int l = 0, r = NUMBER_OF_LEGO - 1;
    while (l < r)
    {
        res = LEGOS[l] + LEGOS[r];
        if (WIDTH == res)
        {
            cout << "yes " << LEGOS[l] << " " << LEGOS[r] << endl;
            return ;
        }
        if (res > WIDTH)
            --r;
        else
            ++l;
    }
    cout << "danger" << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    int a;
    while (cin >> a)
    {
        getInput(a);
        solver();
        delete [] LEGOS;
    }
    return (0);
}