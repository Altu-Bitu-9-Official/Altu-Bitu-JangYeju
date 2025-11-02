#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;
const int MAX_N=11;
const int ADD =0, SUB =1, MUL=2, DIV=3;
const int EXP_NUM=4;

int n;
int nums[MAX_N];
int expression[EXP_NUM];
int max_val = -INF, min_val = INF;

void backtracking(int idx, int current_value){
    if(idx == n-1){
        max_val = max(max_val, current_value);
        min_val = min(min_val, current_value);
        return;
    }

    for(int exp=0;exp<EXP_NUM;exp++){
        if(expression[exp] > 0){
            expression[exp]--;

            switch(exp){
                case ADD:
                    backtracking(idx+1, current_value + nums[idx+1]);
                    break;
                case SUB:
                    backtracking(idx+1, current_value - nums[idx+1]);
                    break;
                case MUL:
                    backtracking(idx+1, current_value * nums[idx+1]);
                    break;
                case DIV:
                    backtracking(idx+1, current_value / nums[idx+1]);
                    break;
            }
            expression[exp]++;
        }
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    for(int i=0;i<EXP_NUM;i++){
        cin >> expression[i];
    }
    backtracking(0, nums[0]);
    cout << max_val << '\n' << min_val; 
    return 0;
}
