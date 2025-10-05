#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq; //최소 힙

    for(int i=0;i<n*n;i++){
        cin >> x;

        pq.push(x);

        if(pq.size()>n){
            pq.pop();
        }
    }

    cout << pq.top();
    }