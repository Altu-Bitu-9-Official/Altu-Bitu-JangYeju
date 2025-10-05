#include <iostream>

using namespace std;

void add(int &s, int x){
    s |= (1 << x);
}

void remove(int &s, int x){
    s &= ~(1 << x);
}

void check(int &s, int x){
    if(s & (1 << x)){
        cout << 1 << '\n';
    }else{
        cout << 0 << '\n';
    }
}

void toggle(int &s, int x){
    s ^= (1 << x);
}

void all(int &s){
    s = (1 << 21) - 1;
}

void empty(int &s){
    s = 0;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m,x;
    cin >> m;

    int s = 0;
    string op;

    while(m--){
        cin >> op;
        if(op == "add"){
            cin >> x;
            add(s, x);
        }else if(op == "remove"){
            cin >> x;
            remove(s, x);
        }else if(op == "check"){
            cin >> x;
            check(s, x);
        }else if(op == "toggle"){
            cin >> x;
            toggle(s, x);
        }else if(op == "all"){
            all(s);
        }else if(op == "empty"){
            empty(s);
        }
    }
    return 0;
}
