#include <iostream>
#include <vector>

using namespace std;

bool check(const vector<int>& light, int n, int m, int length){
    if(light[0] > length) {
        return false;
    }
    for(int i=1; i< m; i++){
        if(light[i]-light[i-1] > 2* length){
            return false;
        }
    }
    if(n - light[m-1] > length){
        return false;
    }
    return true;
}

int binarySearch(int n, int m, const vector<int>* light){
    int start = 0;
    int end = n;
    int result= end;
    int mid= (start + end) / 2;

    while(start <= end){
        int mid= (start + end) / 2;
        if(check(*light, n, m, mid)){
            result = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return result;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> light(m);
    for(int i=0; i<m; i++){
        cin >> light[i];
    }
    int result = binarySearch(n, m, &light);
    cout << result;

    return 0;
}