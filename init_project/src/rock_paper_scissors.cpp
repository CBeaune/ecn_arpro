#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <cmath>

using namespace std;

int main(int argc, char ** argv)
{
    unsigned int choice;
    cout<<"Choose your fighter!"<<endl;
    cout<<"Rock:0, paper:1, scissors:2"; cin >> choice;

    srand(time(0));
    unsigned int pc_choice = rand()%3;
    cout<< "Computer choice is "<<pc_choice<<endl;

    /* 0 > 2, 1 > 0, 2 >1*/
    int match =( choice - pc_choice + 3)%3 ;
    if(match ==0) cout<<"Draw!";
    else if(match == 2) cout<<"Computer wins!";
    else cout<<"Well done!";


}
