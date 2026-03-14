#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>
#include <deque>
#include<random>
#include<chrono>
#define ACE 14
using namespace std;

struct Card{
    int rank;
    int suit;
};

vector<Card> curr_hand;
vector<Card> deck;
mt19937 r(time(0));
uniform_int_distribution<int> dist(0,51);

void hand(){
    bool used[52]={false};
    curr_hand.clear();

    while(curr_hand.size()<5){
        int x=dist(r);
        if(!used[x]){
            used[x]=true;
            curr_hand.push_back(deck[x]);
        }
    }
}

bool flush(){
    for(int i=1;i<5;i++){
        if(curr_hand[i].suit!=curr_hand[i-1].suit)
        return false;
    }
    return true;
}

bool straight(){
    if(curr_hand[0].rank==2&&
    curr_hand[1].rank==3&&
    curr_hand[2].rank==4&&
    curr_hand[3].rank==5&&
    curr_hand[4].rank==14)
    return true;
    for(int i=1;i<5;i++){
        if(curr_hand[i].rank!=curr_hand[i-1].rank+1)
        return false;
    }
    return true;
}

int rankcnt(){
    int cnt=1;
    vector<int> cntt;
    for(int i=1;i<5;i++){
        if(curr_hand[i].rank==curr_hand[i-1].rank)
        cnt++;
        else{
            if(cnt!=1) cntt.push_back(cnt);
            cnt=1;
        }
    }
    if(cnt!=1) cntt.push_back(cnt);

    sort(cntt.begin(),cntt.end());
    if(cntt.size()==2){
        if(cntt[0]<cntt[1]) 
        return 5;
        else return 4;
    }
    else if(cntt.size()==1){
        if(cntt[0]==4)
        return 3;
        else if(cntt[0]==3)
        return 2;
        else 
        return 1;
    }
    return 0;
}

int main(){
    int suit,rank;

    for(suit=0; suit<4; suit++){
        for(rank=2; rank<=14; rank++){
            deck.push_back({rank, suit});
        }
    }
    
    vector<int> test={1000,10000,100000,1000000,10000000};
    int testsize=test.size();

    for(int k=0;k<testsize;k++){

    int straightflush_cnt=0,four_of_a_kind_cnt=0,full_house_cnt=0;
    int flush_cnt=0,straight_cnt=0,three_of_a_kind_cnt=0;
    int two_pair_cnt=0,pair_cnt=0,highcard_cnt=0;
    cout<<"\n";
    int simulation=test[k];
    auto start = chrono::high_resolution_clock::now();
    int t=simulation;
    while(t--){
        hand();
        sort(curr_hand.begin(),curr_hand.end(),[](Card& a, Card& b){
            return a.rank<b.rank;
        });

        bool straightt=straight();
        bool flushh=flush();
        int rankcntt=rankcnt();

        if(straightt&&flushh)
        {straightflush_cnt++;continue;}

        if(rankcntt==3)
        {four_of_a_kind_cnt++;continue;}

        if(rankcntt==5)
        {full_house_cnt++;continue;}

        if(flushh)
        {flush_cnt++;continue;}

        if(straightt)
        {straight_cnt++;continue;}

        if(rankcntt==2)
        {three_of_a_kind_cnt++;continue;}

        if(rankcntt==4)
        {two_pair_cnt++;continue;}

        if(rankcntt==1)
        {pair_cnt++;continue;}

        highcard_cnt++;
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    float theo_straightflush=0.0000139f;
    float theo_four_of_a_kind=0.0002400f;
    float theo_full_house=0.0014410f;
    float theo_flush=0.0019650f;
    float theo_straight=0.0039250f;
    float theo_three_of_a_kind=0.0211280f;
    float theo_two_pair=0.0475390f;
    float theo_pair=0.4225690f;
    float theo_highcard=0.5011770f;

    float sim_straightflush=(float)straightflush_cnt/simulation;
    float sim_four_of_a_kind=(float)four_of_a_kind_cnt/simulation;
    float sim_full_house=(float)full_house_cnt/simulation;
    float sim_flush=(float)flush_cnt/simulation;
    float sim_straight=(float)straight_cnt/simulation;
    float sim_three_of_a_kind=(float)three_of_a_kind_cnt/simulation;
    float sim_two_pair=(float)two_pair_cnt/simulation;
    float sim_pair=(float)pair_cnt/simulation;
    float sim_highcard=(float)highcard_cnt/simulation;
    
    cout<<"Total Simulations:  "<<simulation<<"\n\n";
    cout<<"-----------------------------------------------------------\n";
    cout<<"Hand              Simulated    Theoretical  Error\n\n";
    cout<<"Straight Flush:   "<<sim_straightflush<<" "<<theo_straightflush<<" "<<abs(sim_straightflush-theo_straightflush)<<"\n";
    cout<<"Four of a Kind:   "<<sim_four_of_a_kind<<" "<<theo_four_of_a_kind<<" "<<abs(sim_four_of_a_kind-theo_four_of_a_kind)<<"\n";
    cout<<"Full House:       "<<sim_full_house<<" "<<theo_full_house<<" "<<abs(sim_full_house-theo_full_house)<<"\n";
    cout<<"Flush:            "<<sim_flush<<" "<<theo_flush<<" "<<abs(sim_flush-theo_flush)<<"\n";
    cout<<"Straight:         "<<sim_straight<<" "<<theo_straight<<" "<<abs(sim_straight-theo_straight)<<"\n";
    cout<<"Three of a Kind:  "<<sim_three_of_a_kind<<" "<<theo_three_of_a_kind<<" "<<abs(sim_three_of_a_kind-theo_three_of_a_kind)<<"\n";
    cout<<"Two Pair:         "<<sim_two_pair<<" "<<theo_two_pair<<" "<<abs(sim_two_pair-theo_two_pair)<<"\n";
    cout<<"Pair:             "<<sim_pair<<" "<<theo_pair<<" "<<abs(sim_pair-theo_pair)<<"\n";
    cout<<"High Card:        "<<sim_highcard<<" "<<theo_highcard<<" "<<abs(sim_highcard-theo_highcard)<<"\n";
    cout<<"-----------------------------------------------------------\n";
    cout<<"\nRuntime: "<<duration.count()<<" ms\n";

    cout<<"\n\n";
}

    cout<<"These results demonstrate Monte Carlo convergence, where simulated probabilities approach theoretical values as the number of simulations increases.\n";
    return 0;
}

