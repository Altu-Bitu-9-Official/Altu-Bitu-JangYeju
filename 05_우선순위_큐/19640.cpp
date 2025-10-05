#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct info{
    int idx;
    int line_num;
    int work_days;
    int urgency;
};

struct cmp{
    bool operator()(const info &a, const info &b){
        if(a.work_days != b.work_days)
            return a.work_days < b. work_days;
        if(a.urgency != b.urgency)
            return a.urgency < b.urgency;
        return a.line_num > b.line_num;
    }
};

int simulation(int m, int d, vector<queue<info>> &lines){
    priority_queue<info, vector<info>, cmp> pq;

    for(int i=0;i<m;i++){
        if(!lines[i].empty()){
            pq.push(lines[i].front());
            lines[i].pop();
        }
    }

    int cnt = 0;

    while(!pq.empty()){
        info cur = pq.top();
        pq.pop();

        if(cur.idx == d){
            return cnt;
        }

        cnt++;

        if(!lines[cur.line_num].empty()){
            pq.push(lines[cur.line_num].front());
            lines[cur.line_num].pop();
        }
    }

    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,k,d,h;
    cin >> n >> m >> k;

    vector<queue<info>> lines(m); 

    for(int i=0;i<n;++i){
        cin >> d >> h;
        lines[i%m].push({i,i%m,d,h});
    }

    cout << simulation(m, k, lines) << '\n';
    return 0;
}