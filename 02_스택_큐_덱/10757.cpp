#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string a, b;
    cin >> a >> b;

    while(a.length()<b.length()) 
        a="0"+a;
    while(b.length()<a.length())
        b="0"+b;

    string result = "";
    int carry = 0;

    for(int i=a.length()-1;i>=0;i--){
        int sum = (a[i]-'0') + (b[i]-'0') + carry;
        carry = sum / 10;
        result = char((sum % 10) + '0') + result;
    }
    if (carry>0){
        result = char(carry + '0') + result;
    }
    cout << result << '\n';
    return 0;
}