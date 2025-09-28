#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isbalanced(const string& str){
    stack<char> s;
    for(char ch : str){
        if(ch == '(' || ch == '['){
            s.push(ch);
        } else if(ch == ')'){
            if(s.empty() || s.top() != '(')
                return false;
            s.pop();
        } else if(ch == ']'){
            if(s.empty() || s.top() != '[')
                return false;
            s.pop();
        }
    }
    return s.empty();
}

int main(){
    while(true){
        string str;
        getline(cin, str);

        if(str == ".")
            break;
        if(isbalanced(str))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}