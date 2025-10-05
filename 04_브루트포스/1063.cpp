#include <iostream>
#include <vector>
#include <string>

using namespace std;    

void move(vector<int> &king, vector<int> &stone, const string &op){
    int dx=0; int dy=0;

    if(op == "R"){
        dx =0; dy= 1;
    }
    else if(op == "L"){
        dx =0; dy= -1;
    }
    else if(op == "B"){
        dx =-1; dy= 0;
    }
    else if(op == "T"){
        dx =1; dy= 0;
    }
    else if(op == "RT"){
        dx =1; dy= 1;
    }
    else if(op == "LT"){
        dx = 1; dy= -1;
    }
    else if(op == "RB"){
        dx = -1; dy= 1;
    }
    else if(op == "LB"){
        dx = -1; dy= -1;
    }

    int nx=king[0]+dx;
    int ny=king[1]+dy;

    if(nx<0 || nx>=8 || ny<0 || ny>=8) return;

    if(nx == stone[0] && ny == stone[1]){
        int sx = stone[0]+dx;
        int sy = stone[1]+dy;
        if(sx<0 || sx>=8 || sy<0 || sy>=8) return;
        stone[0] = sx;
        stone[1] = sy;
    }

    king[0] = nx;
    king[1] = ny;
    
}

int main(){
    string k, s;
    int n;
    cin >> k >> s >> n;

    vector<int> king = {k[1]-'1', k[0]-'A'};
    vector<int> stone = {s[1]-'1', s[0]-'A'};

    string op;
    while(n--){
        cin >>op;
        move(king, stone, op);
    }

    cout << char(king[1]+'A') << king[0]+1 << '\n';
    cout << char(stone[1]+'A') << stone[0]+1 << '\n';
    return 0;
}