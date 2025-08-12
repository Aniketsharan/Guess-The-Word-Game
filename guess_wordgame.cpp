#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

int main() {
    // List of words to guess from
    std::vector<std::string> words = {"apple", "banana", "computer", "orange", "guitar", "coffee"};

    // Seed random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Pick a random word
    std::string secretWord = words[std::rand() % words.size()];

    // String to track guessed letters
    std::string guessedWord(secretWord.size(), '_');

    int attemptsLeft = 6; // Number of wrong guesses allowed
    std::vector<char> guessedLetters;

    std::cout << "=== Word Guessing Game ===\n";
    std::cout << "Guess the word! You have " << attemptsLeft << " wrong attempts allowed.\n";

    while (attemptsLeft > 0 && guessedWord != secretWord) {
        std::cout << "\nWord: " << guessedWord << "\n";
        std::cout << "Attempts left: " << attemptsLeft << "\n";
        std::cout << "Guessed letters: ";
        for (char c : guessedLetters) std::cout << c << " ";
        std::cout << "\nEnter a letter: ";

        char guess;
        std::cin >> guess;
        guess = std::tolower(guess);

        // Check if already guessed
        if (std::find(guessedLetters.begin(), guessedLetters.end(), guess) != guessedLetters.end()) {
            std::cout << "You already guessed that letter!\n";
            continue;
        }

        guessedLetters.push_back(guess);

        // Check if guess is in the word
        bool correctGuess = false;
        for (size_t i = 0; i < secretWord.size(); i++) {
            if (secretWord[i] == guess) {
                guessedWord[i] = guess;
                correctGuess = true;
            }
        }

        if (!correctGuess) {
            attemptsLeft--;
            std::cout << "Wrong guess!\n";
        } else {
            std::cout << "Good guess!\n";
        }
    }

    // Game over message
    if (guessedWord == secretWord) {
        std::cout << "\nCongratulations! You guessed the word: " << secretWord << "\n";
    } else {
        std::cout << "\nGame Over! The word was: " << secretWord << "\n";
    }

    return 0;
}
