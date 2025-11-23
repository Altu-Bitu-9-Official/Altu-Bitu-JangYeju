#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(int num, vector<int>& card, int n){
    int left=0;
    int right=n-1;
    while(left <= right){
        int mid= (left + right) / 2;
        if(card[mid] == num){
            return 1;
        } else if(card[mid] < num){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    
    int n, m, num;
    cin >> n;
    vector<int> card(n);
    for(int i=0; i<n; i++){
        cin >> card[i];
    }
    sort(card.begin(), card.end());
    cin >> m;
    while(m--){
        cin >> num;
        cout << binarySearch(num, card, n) << ' ';
    }
    return 0;
}