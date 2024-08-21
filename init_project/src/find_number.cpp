#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <cmath>

using namespace std;

int main(int argc, char ** argv)
{
    bool t=true;
    cout<<"Which type : 0 for you guess, 1 for the computer guesses";cin>>t;

    if(not t){
    srand(time(0));
    //srand(100);
    const unsigned int n = (rand() % 100) + 1;
    // cout << "Random number: " << n << '\n';
    unsigned int m;
    // ask the user for a number
    cout << "Please enter a number (1-100): "; cin >> m;
    while(m!=n)
    {


        // test against n

        if(m < n)
            cout << "Too small" << endl;
        else
            cout << "Too large" << endl;

        // ask the user for a number
        cout << "Please enter a number (1-100): "; cin >> m;
    }
    cout << "Congratulations!";
    }

    else{
        unsigned int n;
        cout<<"Enter your number (1-100)";cin>>n;

        unsigned int big_n = 100;
        unsigned int small_n = 1;

        srand(time(0));
        unsigned int guess = (rand() % 100) + 1;
        unsigned int response;

        while(true){
            cout<<"Is it "<< guess<<"?"<<endl;
            cout<<"Too small:0, Exact:1, Too big:2"; cin>>response;

            if(response==1){
                cout<<"Good game!";
                break;}
            else if(response==0){
                small_n = guess;
                guess = floor((big_n + guess)/2);
            }
            else{
                big_n = guess;
                guess = ceil((small_n + guess)/2);

            }
        }

    }
}
