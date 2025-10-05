#include <iostream>

using namespace std;

int year_cal(int earth, int sun, int moon){
    if(earth == 15)
        earth =0;
    if(sun == 28)
        sun =0;
    if(moon == 19)
        moon =0;
    
    int year=1;
    while(1){
        if(year%15==earth && year%28==sun && year%19==moon){
            return year;
        }
        year++;
    }
}

int main(){
    int e=0; int s=0; int m=0;
    cin >> e >> s >> m;

    cout << year_cal(e,s,m);

    return 0;
}