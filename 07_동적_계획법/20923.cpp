#include <iostream>
#include <vector>
#include <deque>
using namespace std;

typedef vector<deque<int>> cards;
const int DO = 0, SU = 1;

string judge(const cards& deck){
    int a = deck[DO].size(), b = deck[SU].size();
    if (a > b) return "do";
    if (a < b) return "su";
    return "dosu";
}

void groundToDeck(deque<int>& deck, deque<int>& ground){
    while (!ground.empty()) {
        deck.push_back(ground.back());
        ground.pop_back();
    }
}

void ringbell(int player, cards& deck, cards& ground){
    groundToDeck(deck[player], ground[!player]);
    groundToDeck(deck[player], ground[player]);
}

int bellwho(const cards& ground){
    if((!ground[DO].empty() && ground[DO].front() == 5) ||
       (!ground[SU].empty() && ground[SU].front() == 5)) {
        return DO;
    }
    if(!ground[DO].empty() && !ground[SU].empty() &&
       ground[DO].front() + ground[SU].front()==5) {
        return SU;
    }
    return -1;
}

string play(int m, cards& deck, cards& ground){
    bool turn = DO;
    while(m--){
        ground[turn].push_front(deck[turn].front());
        deck[turn].pop_front();
        if(deck[turn].empty()){
            break;
        }
        int bell = bellwho(ground);
        if( bell != -1){
            ringbell(bell, deck, ground);
        }
        turn ^= 1;
    }
    return judge(deck);
}

int main(){
    int n, m, card1, card2;
    cards deck(2), ground(2);

    cin >> n >> m;
    while(n--){
        cin >> card1 >> card2;
        deck[DO].push_front(card1);
        deck[SU].push_front(card2);
    }
    cout << play(m, deck, ground);
    return 0;
}