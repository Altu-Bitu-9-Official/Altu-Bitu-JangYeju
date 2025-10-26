#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

static inline void rotateCW(string &s) {
    s = s.back() + s.substr(0, 7);
}
static inline void rotateCCW(string &s) {
    s = s.substr(1) + s[0];
}

int main() {
    int t; 
    cin >> t;

    vector<string> gears(t);
    for (int i = 0; i < t; ++i) cin >> gears[i];

    int k; 
    cin >> k;

    while (k--) {
        int idx, dir;             // dir: 1(시계), -1(반시계)
        cin >> idx >> dir;
        --idx;                    
    
        vector<int> rot(t, 0);
        vector<int> seen(t, 0);

        queue<int> q;
        rot[idx] = dir;
        seen[idx] = 1;
        q.push(idx);

        while (!q.empty()) {
            int cur = q.front(); q.pop();

            int l = cur - 1;
            if (l >= 0 && !seen[l]) {
                if (gears[l][2] != gears[cur][6]) {
                    rot[l] = -rot[cur];
                    seen[l] = 1;
                    q.push(l);
                } else {
                    seen[l] = 1;
                }
            }

            int r = cur + 1;
            if (r < t && !seen[r]) {
                if (gears[cur][2] != gears[r][6]) {
                    rot[r] = -rot[cur];
                    seen[r] = 1;
                    q.push(r);
                } else {
                    seen[r] = 1;
                }
            }
        }

        for (int i = 0; i < t; ++i) {
            if (rot[i] == 1) {
                rotateCW(gears[i]);
            } else if (rot[i] == -1) {
                rotateCCW(gears[i]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < t; ++i) {
        if (gears[i][0] == '1') ++ans;
    }
    cout << ans << '\n';
    return 0;
}
