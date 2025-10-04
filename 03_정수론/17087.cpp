#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int n, s;
    cin >> n >> s;

    vector<int> positions(n);
    for (int i = 0; i < n; ++i) {
        cin >> positions[i];
    }

    int result = 0;
    for (int i = 0; i < n; ++i) {
        int distance = abs(positions[i] - s);
        result = gcd(result, distance);
    }

    cout << result << '\n';
    return 0;
}