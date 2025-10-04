#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> getPrimes(int n){
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i=2; i*i<=n;i++){
        if(is_prime[i]){
            for(int j=i*i; j <= n; j += i ){
                is_prime[j] = false;
            }
        }else{
            continue;
        }
    }
    return is_prime;
}

int goldbach(int n, vector<bool> &is_prime){
    for(int a = 3; a<= n/2; a+=2){
        int b = n - a;
        if(is_prime[a] && is_prime[b]){
            return a;
        }
    }
    return 0;
}

int main(){
    vector<int> arr;
    int input;

    while(1){
        cin >> input;
        if(input == 0) break;
        arr.push_back(input);
    }

    int max_num= *max_element(arr.begin(),arr.end()); //벡터의 최댓값
    vector<bool> is_prime = getPrimes(max_num);

    for(int i=0;i<arr.size();i++){
        int a = goldbach(arr[i], is_prime);

        if(a != 0){
            cout << arr[i] << " = " << a << " + " << arr[i]-a << '\n';
        }else{
            cout << "Goldbach's conjecture is wrong.\n";
        }
        
    }
    return 0;
}