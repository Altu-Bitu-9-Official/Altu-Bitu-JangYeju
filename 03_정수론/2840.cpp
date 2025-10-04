#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<char> wheel(n, '?'); //처음 바퀴 칸 모두 미정
    int pos = 0;

    bool possible = true;

    for(int i = 0; i < k; i++){
        int s;
        char c;
        cin >> s >> c;

        pos = (pos + s)%n; //시계방향으로 s칸 이동

        if(wheel[pos] != '?' && wheel[pos] != c){
            possible = false;
        }

        for(int j=0; j< n;j++){
            if(j != pos && wheel[j]==c){
                possible = false;
            }
        }
        wheel[pos] = c;
    }
    if(!possible){
        cout << "!" << '\n';
        return 0;
    }

    for(int i=0; i<n;i++){
        cout << wheel[(pos -i + n )%n];
    }
    cout << '\n';
    return 0;
}