#include <iostream>
#include <vector>

using namespace std;

// n: 접시 수, d: 초밥 가짓수, k: 연속 접시 수, c: 쿠폰 번호
int calcMaxSushi(vector<int> &belt, int n, int d, int k, int c) {
    vector<int> sushi(d + 1, 0);

    int count = 1;    
    sushi[c]++;

    for (int i = 0; i < k; i++) {
        if (sushi[belt[i]] == 0) {
            count++;
        }
        sushi[belt[i]]++;
    }

    int ans = count;

    // 슬라이딩 윈도우 (회전 처리)
    for (int i = k; i < n + k; i++) {
        int outIdx = (i - k) % n; 
        int inIdx  = i % n;       

        sushi[belt[outIdx]]--;
        if (sushi[belt[outIdx]] == 0) {
            count--;
        }

        if (sushi[belt[inIdx]] == 0) {
            count++;
        }
        sushi[belt[inIdx]]++;

        ans = max(ans, count);
    }

    return ans;
}

int main() {
    int n, d, k, c;
    cin >> n >> d >> k >> c;
    vector<int> belt(n);
    for (int i = 0; i < n; i++) {
        cin >> belt[i];
    }
    cout << calcMaxSushi(belt, n, d, k, c);
}
