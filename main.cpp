#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to get computer move
int getComputerMove() {
    return rand() % 3 + 1; // 1 = Rock, 2 = Paper, 3 = Scissors
}

// Function to decide winner
void decideWinner(int user, int computer) {
    if(user == computer) {
        cout << "It's a Draw!\n";
    }
    else if((user == 1 && computer == 3) ||
            (user == 2 && computer == 1) ||
            (user == 3 && computer == 2)) {
        cout << "You Win! 🎉\n";
    }
    else {
        cout << "Computer Wins! 😈\n";
    }
}
string getMoveName(int move) {
    if(move == 1) return "Rock";
    if(move == 2) return "Paper";
    if(move == 3) return "Scissors";
    return "Invalid";
}

int main() {
    srand(time(0));

    int userChoice, computerChoice;
    int userScore = 0, computerScore = 0;
    char playAgain;

    cout << "=== Rock Paper Scissors Game ===\n";
    int userMoves[100];  // store moves
int moveCount = 0;   // number of moves stored

    do {
        cout << "\n1. Rock\n2. Paper\n3. Scissors\n";
        cout << "Enter your choice: ";
        cin >> userChoice;
        
        userMoves[moveCount] = userChoice;
moveCount++;

        cout << "You chose: " << getMoveName(userChoice) << endl;

        int rock = 0, paper = 0, scissors = 0;

// Count frequency
for(int i = 0; i < moveCount; i++) {
    if(userMoves[i] == 1) rock++;
    else if(userMoves[i] == 2) paper++;
    else if(userMoves[i] == 3) scissors++;
}

// Predict user's most frequent move
if(rock >= paper && rock >= scissors) {
    computerChoice = 2; // AI plays Paper (beats Rock)
}
else if(paper >= rock && paper >= scissors) {
    computerChoice = 3; // AI plays Scissors (beats Paper)
}
else {
    computerChoice = 1; // AI plays Rock (beats Scissors)
}
        cout << "Computer chose: " << getMoveName(computerChoice) << endl;

        // Decide winner + update score
        if(userChoice == computerChoice) {
            cout << "It's a Draw!\n";
        }
        else if((userChoice == 1 && computerChoice == 3) ||
                (userChoice == 2 && computerChoice == 1) ||
                (userChoice == 3 && computerChoice == 2)) {
            cout << "You Win! 🎉\n";
            userScore++;
        }
        else {
            cout << "Computer Wins! 😈\n";
            computerScore++;
        }

        // Show score
        cout << "\nScore => You: " << userScore 
             << " | Computer: " << computerScore << endl;

        cout << "\nPlay again? (y/n): ";
        cin >> playAgain;

    } while(playAgain == 'y' || playAgain == 'Y');

    cout << "\nFinal Score => You: " << userScore 
         << " | Computer: " << computerScore << endl;

    cout << "Thanks for playing! 👋\n";

    return 0;
}
