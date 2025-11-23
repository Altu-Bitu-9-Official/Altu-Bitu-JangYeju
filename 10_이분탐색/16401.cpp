#include <iostream>
#include <vector>

using namespace std;

#define MAX_COOKIES 1000000000

int binarySearch(int m, vector<int> &cookie){
    int right =MAX_COOKIES;
    int left=1;
    int rest=0;

    while(left <= right){
        int mid= (left + right) / 2;
        int count=0;
        for(int i=0; i< cookie.size(); i++){
            count += cookie[i] / mid;
        }
        if(count >= m){
            left = mid + 1;
            rest = mid;
        } else {
            right = mid - 1;
        }
    }
    return rest;
}

int main(){
    int m, n;
    cin >> m >> n;
    vector<int> cookie(n);

    for(int i=0; i<n; i++){
        cin >> cookie[i];
    }
    cout << binarySearch(m, cookie);
    return 0;
}