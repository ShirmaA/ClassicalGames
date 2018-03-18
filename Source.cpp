#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <cctype>
#include <Windows.h>
using namespace std;
int main() {
	const int max_wrong = 8;
	string name;
	char yn, a;
	vector<string> words;
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");
	words.push_back("GUESS");
	words.push_back("COMPUTER");
	words.push_back("TECHNOLOGIES");
	words.push_back("ARTIFICIAL");
	words.push_back("INTELLIGENCE");
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());
	string theWord = words[0];
	int wrong = 0, amountofWords = 0;
	string soFar(theWord.size(), '-');
	string used = "";
	cout << "Welcome to Hangman! What is your name?";
	cin >> name;
	cout << "Can you guess the word I've set, " << name << " ?" << endl;
	cout << "Good luck!" << endl;
	cout << "I'm sure you'll need it..." << endl;
	while ((wrong < max_wrong) && (soFar != theWord)) {
		cout << "You have " << (max_wrong - wrong) << " incorrect guesses left" << endl;
		cout << "You've used the following letters:\n" << used << endl;
		cout << "So far the word is:\n" << soFar << endl;
		char guess;
		cout << "Enter your guess: ";
		cin >> guess;
		system("cls");
		guess = toupper(guess);
		while (used.find(guess) != string::npos) {
			cout << "You've already guessed: " << guess << endl;
			cout << "Enter your guess: ";
			cin >> guess;
			guess = toupper(guess);
		}
		used += guess;

		if (theWord.find(guess) != string::npos) {
			cout << "That's right " << guess << " is in the word." << endl;

			for (int i = 0; i < theWord.length(); i++) {
				if (theWord[i] == guess) {
					soFar[i] = guess;
				}
			}
		}
		else {
			cout << "Sorry, " << guess << " isn't in the word." << endl;
			wrong++;
		}
	}
	if (wrong == max_wrong) {
		cout << "You've been hanged!" << endl;
	}
	else {
		cout << "You guessed it!" << endl;
	}
	cout << "The word is " << theWord << endl;
}




