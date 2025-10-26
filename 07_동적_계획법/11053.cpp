#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getLISLength(int n, vector<int>& sequence) {
    vector<int> lis(n,1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (sequence[i] > sequence[j]) {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }
    return *max_element(lis.begin(), lis.end());
}

int main() {
    int n;
    cin >> n;
    vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }
    cout << getLISLength(n, sequence);
    return 0;
}