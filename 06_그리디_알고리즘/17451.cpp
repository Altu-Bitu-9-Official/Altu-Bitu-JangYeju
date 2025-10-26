#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int calculateMinSpeed(int n, const vector<int>& v){
    int v_min = v[n-1];
    for(int i=n-2;i>=0;--i){
        if(v_min < v[i]){
            v_min=v[i];
        }
        int m = ceil((double)v_min / v[i]);
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

