#include <iostream>
#include <vector>
using namespace std;

const int MOD = 10007;

int countCases(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;  
    dp[1] = 1;  

    for (int i = 2; i <= n; i++) {
        int vertical = dp[i-1];
        int horizontal = dp[i-2];
        dp[i] = (vertical + horizontal) % MOD;
    }

    return dp[n];
}

int main(){
    int n;
    cin >> n;
    cout << countCases(n);
    return 0;   
}