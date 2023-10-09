#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// List of words for the game
vector<string> words = {"programming", "computer", "hangman", "algorithm", "puzzling", "knapsack"};

// Function to choose a random word from the list
string chooseRandomWord() {
    srand(static_cast<unsigned int>(time(nullptr)));
    int randomIndex = rand() % words.size();
    return words[randomIndex];
}

// Function to display the current state of the word
void displayWord(const string& word, const vector<bool>& guessed) {
    for (size_t i = 0; i < word.length(); ++i) {
        if (guessed[i]) {
            cout << word[i] << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

int main() {
    string wordToGuess = chooseRandomWord();
    vector<bool> guessed(wordToGuess.length(), false);
    int incorrectGuesses = 0;
    const int maxIncorrectGuesses = 6;

    cout << "Welcome to Hangman!" << endl;

    while (incorrectGuesses < maxIncorrectGuesses) {
        cout << "\nCurrent word: ";
        displayWord(wordToGuess, guessed);

        char guess;
        cout << "Guess a letter: ";
        cin >> guess;

        bool found = false;
        for (size_t i = 0; i < wordToGuess.length(); ++i) {
            if (wordToGuess[i] == guess) {
                guessed[i] = true;
                found = true;
            }
        }

        if (!found) {
            incorrectGuesses++;
            cout << "Incorrect guess. You have " << maxIncorrectGuesses - incorrectGuesses << " attempts left." << endl;
        }

        // Check for win
        if (guessed == vector<bool>(wordToGuess.length(), true)) {
            cout << "Congratulations! You guessed the word: " << wordToGuess << endl;
            break;
        }
    }

    if (incorrectGuesses == maxIncorrectGuesses) {
        cout << "Sorry, you ran out of attempts. The word was: " << wordToGuess << endl;
    }

    cout << "Thanks for playing Hangman!" << endl;

    return 0;
}
