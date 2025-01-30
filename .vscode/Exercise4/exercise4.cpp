#include <iostream>
#include <cstdlib>
#include <ctime>

int generateRandom(int min, int max) {
    return rand() % (max - min + 1) + min;
}

bool isPowerOfTwoMinusOne(int n) {
    return n == 3 || n == 7 || n == 15 || n == 31 || n == 63;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int playerWins = 0, robotWins = 0;
    const int maxWins = 2;

    std::cout << "This is a best of 3 tournament. First to 2 wins will be champion!!!\n";

    while (playerWins < maxWins && robotWins < maxWins) {
        int pile = generateRandom(10, 100);
        bool playerTurn = generateRandom(0, 1) == 0;
        bool robotSmart = generateRandom(0, 1) == 1;

        std::cout << "\nThere are " << pile << " marbles on the table." << std::endl;
        if (!playerTurn) {
            std::cout << "Robot goes first!" << std::endl;
        }
        if (robotSmart) {
            std::cout << "Robot is smart!" << std::endl;
        }
        else {
            std::cout << "Robot is playing stupid!" << std::endl;
        }

        while (pile > 1) {
            int take;
            if (playerTurn) {
                std::cout << "Player make your move.\nHow many marbles do you want? " << std::endl;
                std::cin >> take;
                while (take < 1 || take > pile / 2) {
                    std::cout << "Invalid move. You must take between 1 and " << pile / 2 << " marbles.\nHow many marbles do you want? " << std::endl;
                    std::cin >> take;
                }
                std::cout << "Player wants " << take << " marbles." << std::endl;
            }
            else {
                if (robotSmart) {
                    // Smart mode: Try to make the pile a power of two minus one
                    bool foundMove = false;
                    for (int target : {63, 31, 15, 7, 3}) {
                        if (pile > target && pile - target <= pile / 2) {
                            take = pile - target;
                            foundMove = true;
                            break;
                        }
                    }
                    if (!foundMove) {
                        take = generateRandom(1, pile / 2);
                    }
                }
                else {
                    // Stupid mode: Take a random legal value
                    take = generateRandom(1, pile / 2);
                }
                std::cout << "Robot wants " << take << " marbles." << std::endl;
            }

            pile -= take;
            std::cout << "There are " << pile << " marbles left on the table." << std::endl;

            playerTurn = !playerTurn;
        }

        if (playerTurn) {
            std::cout << "*********************Robot loses!*************************" << std::endl;
            playerWins++;
        }
        else {
            std::cout << "*********************Player loses!************************" << std::endl;
            robotWins++;
        }

        std::cout << "\nCurrent Score: Player " << playerWins << " - " << robotWins << " Robot\n";
    }

    if (playerWins == maxWins) {
        std::cout << "\nPlayer wins the tournament!" << std::endl;
    }
    else {
        std::cout << "\nRobot wins the tournament!" << std::endl;
    }

    return 0;
}