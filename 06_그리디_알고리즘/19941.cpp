#include <iostream>
#include <string>
using namespace std;

int countHamburgers(int n, int k, string& str){
    int cnt =0;
    for( int i=0; i<n;i++){
        if(str[i] != 'P') continue;

        for(int j=i-k;j<=i+k;j++){
            if(j<0 || j>=n) continue;
            if(str[j] == 'H'){
                cnt++;
                str[j] = 'X';
                break;
            } 
        }
    }
    return cnt;
}

int main(){
    int n,k;
    string s;

    cin >> n >> k >> s;
    cout << countHamburgers(n,k,s);

    return 0;
}