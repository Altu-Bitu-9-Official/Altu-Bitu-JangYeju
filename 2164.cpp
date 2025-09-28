#include <iostream>
#include <queue>

using namespace std;

int main(){
    int N;
    cin >> N;
    queue<int> q;

    // 큐에 1부터 N까지 수 넣기
    for(int i=1; i<=N; i++){
        q.push(i);
    }

    while(q.size()>1){
        q.pop();
        int front = q.front();
        q.pop();
        q.push(front);
    }

    cout << q.front() <<endl;
    return 0;
}