#include "sticks.h"

using namespace std;

int main(int argc, char ** argv)
{
    auto sticks = Sticks();
    int first_player = sticks.who();
    switch (first_player) {
    case 0:
        cout<<"You begin!";
        break;
    case 1:
        cout<<"Computer begins!";
        break;
    }
    bool game = true;
    while(game){
        if (sticks.check_end_game()) {
            cout<<"End game"<<endl; game=false; break;}
        cout<<"Number of remaining sticks: ";
        sticks.print_sticks();
        cout<<" "<<endl;

        switch (first_player) {
        case 0:
            sticks.player_choose();
            sticks.update_turns();
            if (sticks.check_end_game()) {
                cout<<"End game"<<endl; game=false; break;}
            cout<<"Number of remaining sticks: ";
            sticks.print_sticks();cout<<" "<<endl;

            sticks.AI_choose();
            sticks.update_turns();
            break;
        case 1:
            sticks.AI_choose();
            sticks.update_turns();
            if (sticks.check_end_game()) {
                cout<<"End game"<<endl; game=false;break;}
            cout<<"Number of remaining sticks: ";
            sticks.print_sticks();cout<<" "<<endl;

            sticks.player_choose();
            sticks.update_turns();
            break;
        }




    }
    if (sticks.winner()) cout<<"Well done!";
    else cout<<"Looser! Try again!";
}
