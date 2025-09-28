#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string A, B;
    cin >> A >> B;

    while(A.length()<B.length()) 
        A="0"+A;
    while(B.length()<A.length())
        B="0"+B;

    string result = "";
    int carry = 0;

    for(int i=A.length()-1;i>=0;i--){
        int sum = (A[i]-'0') + (B[i]-'0') + carry;
        carry = sum / 10;
        result += char((sum % 10) + '0') + result;
    }
    if (carry>0){
        result = char(carry + '0') + result;
    }
    cout << result << endl;
    return 0;
}