#ifndef STICKS_CONFIG_H
#define STICKS_CONFIG_H

#include <algorithm>
#include <vector>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include "time.h"

// This class defines what is a configuration for the 21 sticks game
using namespace std;


class Sticks
{
public:
    Sticks(int start = 21)
    {
        n_sticks = start;
        n_turns = 0;
        first_player = 0;
    }

    void take_sticks(int sticks){
        n_sticks = n_sticks - sticks;
    }

    void print_sticks(){
        cout<<n_sticks;
    }

    int who(){
        srand(time(0));
        first_player = rand()%2;
        return first_player;
    }

    bool winner(){
        return (n_turns+first_player)%2!=0;
    }

    bool IsValid(unsigned int n){
        if( n > 3) return false;
        else if(n<1) return false;
        else if(n>n_sticks) return false;
        return true;
    }

    void AI_choose(){
        unsigned int ai;
        while(true){

            srand(time(0));
            ai = (n_sticks - 1) % 4;
            if(ai == 0)
                ai = rand() % 3 + 1;
            if(IsValid(ai)) break;
            else cout<<"Invalid choice"<<endl;
        }
        cout<<"Computer chooses "<<ai<<"sticks"<<endl;
        take_sticks(ai);
    }

    void player_choose(){
        unsigned int player;
        while(true){
            cout<<"Choose a number (1-3)"; cin>>player;
            if(IsValid(player)) break;
            else cout<<"Invalid choice"<<endl;

        }
        take_sticks(player);
    }



    bool check_end_game(){
        if (n_sticks==1) return true;
        else return false;
    }

    void update_turns(){
        n_turns += 1;
        cout<<n_turns<<endl;
    }

protected:
    int n_sticks;
    int n_turns;
    int first_player;
};

#endif // STICKS_GAME_H
