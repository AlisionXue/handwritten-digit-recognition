#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()
#include <vector>

int getSmartMove(int currentMarbles) {
    // Calculate the best "smart" move (leaves a power of two minus one)
    for (int n = 1; (1 << n) - 1 <= currentMarbles; ++n) {
        int target = (1 << n) - 1;
        if (currentMarbles > target) {
            return currentMarbles - target;
        }
    }
    return rand() % (currentMarbles / 2) + 1; // Fallback if no smart move found
}

int getStupidMove(int currentMarbles) {
    // Return a random move
    return rand() % (currentMarbles / 2) + 1;
}

void playGame(bool computerFirst, bool computerSmart) {
    int marbles = rand() % 91 + 10; // Random pile between 10 and 100
    std::cout << "Initial marbles: " << marbles << std::endl;

    bool turn = computerFirst; // true if computer's turn

    while (marbles > 1) {
        if (turn) { // Computer's turn
            int move = computerSmart ? getSmartMove(marbles) : getStupidMove(marbles);
            std::cout << "Computer takes " << move << " marbles." << std::endl;
            marbles -= move;
        }
        else { // Player's turn
            std::cout << "Your turn. There are " << marbles << " marbles." << std::endl;
            int move = 0;
            std::cin >> move;
            while (move < 1 || move > marbles / 2) {
                std::cout << "Invalid move. Please take between 1 and " << marbles / 2 << " marbles." << std::endl;
                std::cin >> move;
            }
            marbles -= move;
        }
        turn = !turn; // Switch turns
        std::cout << marbles << " marbles left on the table." << std::endl;
    }

    std::cout << (turn ? "Player" : "Computer") << " loses!" << std::endl;
}

int main() {
    srand(time(0)); // Seed random number generator
    int playerWins = 0, computerWins = 0;

    while (playerWins < 2 && computerWins < 2) {
        bool computerFirst = rand() % 2 == 0;
        bool computerSmart = rand() % 2 == 0;
        playGame(computerFirst, computerSmart);

        // Determine who won and update scores
        // Assume playGame prints who loses, so the opposite of the last player is the winner
        if (computerFirst) { // If computer started and lost, player wins
            playerWins++;
        }
        else {
            computerWins++;
        }
    }

    std::cout << "Tournament result: " << (playerWins == 2 ? "Player wins!" : "Computer wins!") << std::endl;
    return 0;
}
