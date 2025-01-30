#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int smartMove(int marbles) {
    int powerOfTwoMinusOne[] = { 63, 31, 15, 7, 3 };
    for (int i = 0; i < 5; i++) {
        if (marbles > powerOfTwoMinusOne[i]) {
            return marbles - powerOfTwoMinusOne[i];
        }
    }
    return getRandomNumber(1, marbles / 2);
}

int stupidMove(int marbles) {
    return getRandomNumber(1, marbles / 2);
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int playerWins = 0, robotWins = 0;
    int bestOf = 3;
    int targetWins = bestOf / 2 + 1;

    cout << "This is a best of " << bestOf << " tournament. First to " << targetWins << " wins will be champion!!!" << endl;

    while (playerWins < targetWins && robotWins < targetWins) {
        int marbles = getRandomNumber(10, 100);
        bool playerTurn = getRandomNumber(0, 1);
        bool robotSmart = getRandomNumber(0, 1);

        cout << "There are " << marbles << " marbles on the table." << endl;
        if (playerTurn) {
            cout << "Player goes first!" << endl;
        }
        else {
            cout << "Robot goes first!" << endl;
        }

        while (marbles > 1) {
            if (playerTurn) {
                int playerTake;
                cout << "Player, make your move. How many marbles do you want?" << endl;
                cin >> playerTake;
                while (playerTake < 1 || playerTake > marbles / 2) {
                    cout << "Invalid move. You must take between 1 and " << marbles / 2 << " marbles." << endl;
                    cin >> playerTake;
                }
                cout << "Player takes " << playerTake << " marbles." << endl;
                marbles -= playerTake;
                cout << "There are " << marbles << " marbles left on the table." << endl;
                playerTurn = false;
            }
            else {
                int robotTake;
                if (robotSmart) {
                    cout << "Robot is smart!" << endl;
                    robotTake = smartMove(marbles);
                }
                else {
                    cout << "Robot is stupid!" << endl;
                    robotTake = stupidMove(marbles);
                }
                cout << "Robot takes " << robotTake << " marbles." << endl;
                marbles -= robotTake;
                cout << "There are " << marbles << " marbles left on the table." << endl;
                playerTurn = true;
            }
        }

        if (playerTurn) {
            cout << "*********************Robot loses!*************************" << endl;
            playerWins++;
            cout << "Player needs one more win." << endl;
        }
        else {
            cout << "*********************Player loses!************************" << endl;
            robotWins++;
            cout << "Robot needs one more win." << endl;
        }

        cout << "Current score - Player: " << playerWins << ", Robot: " << robotWins << endl;
    }

    if (playerWins == targetWins) {
        cout << "Player wins the tournament!" << endl;
    }
    else if (robotWins == targetWins) {
        cout << "Robot wins the tournament!" << endl;
    }

    return 0;
}

