#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b, int c)
{
    int least;
    a < b ? least = a : least = b;
    return c < least ? least = c : least = least;
}

int leastcoins(int max, int n, int coins, vector<int>& memo)
{
    if(n == max)
        return coins;
    if(n > max)
        return 99999;

    if(memo[n] != -1)
        return memo[n];

    return memo[n] = min(leastcoins(max,n + 1,coins + 1,memo), leastcoins(max,n + 10,coins + 1,memo), leastcoins(max,n + 25,coins + 1,memo));
}

int main()
{
    int max = 10000;
    vector<int> memo(max, -1);
    cout << leastcoins(max,0,0,memo) << endl;
    return 0;
}
