#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string word = "computer"; // word to guess
    string guessed(word.size(), '_'); // underscores for hidden word
    int wrongGuesses = 0;
    const int maxGuesses = 6;
    char guess;
    vector<char> usedLetters;

    cout << "=== Welcome to Hangman ===" << endl;

    while (wrongGuesses < maxGuesses && guessed != word) {
        cout << "\nWord: " << guessed << endl;
        cout << "Wrong guesses left: " << maxGuesses - wrongGuesses << endl;
        cout << "Enter a letter: ";
        cin >> guess;

        // check if already guessed
        if (find(usedLetters.begin(), usedLetters.end(), guess) != usedLetters.end()) {
            cout << "You already guessed that letter!" << endl;
            continue;
        }
        usedLetters.push_back(guess);

        bool found = false;
        for (size_t i = 0; i < word.size(); i++) {
            if (word[i] == guess) {
                guessed[i] = guess;
                found = true;
            }
        }

        if (!found) {
            wrongGuesses++;
            cout << "Wrong guess!" << endl;
        }
    }
   if (guessed == word) {
 cout << "\n?? Congratulations! You guessed the word: " << word << endl;
    } else {
        cout << "\n?? Game Over! The word was: " << word << endl;
    }

    return 0;
}

