#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    string word;
    cin >> word;

    vector<int> base(26, 0);
    for(char c : word) base[c - 'A']++;

    int result = 0;

    for(int i = 1; i < n; i++) { 
        string w;
        cin >> w;

        vector<int> cur(26, 0);
        for(char c : w) cur[c - 'A']++;

        int diff = 0;
        for(int j = 0; j < 26; j++) {
            diff += abs(base[j] - cur[j]);
        }

        int lenDiff = abs((int)word.size() - (int)w.size());

        if((lenDiff == 0 && diff <= 2) || (lenDiff == 1 && diff == 1)) {
            result++;
        }
    }

    cout << result;
}



