
using namespace std;
int bits(int n)
{
    int numberOfones = 0;
    while(n)
    {
        numberOfones += n%2;
        n = n>> 1;
    }
    return numberOfones;
}
int solution(int n)
{

    int numberOfones = bits(n);
    while(1)
    {
        if(bits(++n)==numberOfones)
            return n;
    }
}