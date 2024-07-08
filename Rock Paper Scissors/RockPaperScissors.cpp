#include<iostream>
#include<cstdlib> 
#include<ctime>
using namespace std;

int choice;

string Paper = R"(
 __________
|1         |____
|       ________|
|       _________|
|Paper _________|
|____________|)";

string Rock = R"(
 __________
|2    _____|
|     ______|
|     _____|
|Rock ____|
|_______|)";

string Scissors = R"(
 __
|3  |__________
|       _______|
|       ________|
|Scissors_|
|_______|)";

// equal
// choice == 1 ==> [randomNumner ==  2] win 
// choice == 1 ==> [randomNumner ==  3] lose
// 
// choice == 2 ==> [randomNumner ==  1] lose
// choice == 2 ==> [randomNumner ==  3] win
//
// choice == 3 ==> [randomNumner ==  1] win
// choice == 3 ==> [randomNumner ==  2] lose

int generateRandom() {
    return 1 + rand()% 3;
}

void play(){
    int life = 2;
    while(life)
    {
        cout << "*** Rock Paper Scissors ***" << endl;
        cout << Paper << endl;
        cout << Rock << endl;
        cout << Scissors << endl << endl;
        
        cout << "Choose a number : ";
        cin >> choice;

        if (choice < 1 || choice > 3) {
            cout << "Invalid choice. Choose 1, 2 or 3!" << endl;
            continue;
        }

        int randomNumber = generateRandom();

        cout << "--------------------" << endl;
        cout << "You chose: " << choice << endl;
        cout << "Computer chose: " << randomNumber << endl;
        cout << "--------------------" << endl;

        if(choice == randomNumber) {
            cout << "Equal!" << endl << endl;
            life--;
            cout << "You got " << life << " chances remained!" << endl;
        }else if((choice == 1 && randomNumber == 2) ||
                  (choice == 2 && randomNumber == 3) || 
                  (choice == 3 && randomNumber == 1)){
                    cout << "You Win!" << endl << endl;
                    break;
                  }
        else if((choice == 1 && randomNumber == 3) ||
                  (choice == 2 && randomNumber == 1) || 
                  (choice == 3 && randomNumber == 2)){
                    life--;
                    if(life == 0) {
                        cout << "You Lost!" << endl;
                    }else {
                        cout << "You got " << life << " chances remained!" << endl << endl;
                    }
                  }
    }
}

int main() {

    srand(time(0));
    play();
}
