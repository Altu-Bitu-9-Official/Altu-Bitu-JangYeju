#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

long long calculateMinSpeed(int n, const vector<int>& v){
    long long v_min = v[n-1];
    for(int i=n-2;i>=0;--i){
        if(v_min < v[i]){
            v_min=v[i];
        }
        long long m = ceil((double)v_min / v[i]);
        v_min = v[i]*m;
    }
    return v_min;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);

    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    cout << calculateMinSpeed(n,v) << "\n";
    return 0;
}

