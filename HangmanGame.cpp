#include <iostream>
#include <string>
#include <vector>

using namespace std;

string name;
string friendsName;
string word;
string hint;
vector <char> foundLetters;
vector <char> misses;
vector <char> guesses;
int numberOfLetters;
int hangman = 0;
vector <int> lives;


void intro() {
	foundLetters.clear();
	misses.clear();
	guesses.clear();
	lives.clear();

	cout << "Welcome to hangman." << endl;
	cout << "Please enter your name: ";
	getline(cin, name);
	cout << endl;
}




void setDifficulty(int difficulty){
	lives.push_back(0);
	if (difficulty == 1){
		for (int i = 1; i <= 10; i++)
			lives.push_back(i);
	}
	else {
		for (int i = 5; i <= 10; i++)
			lives.push_back(i);
	}
}

void pickDifficulty() {
	int difficulty = 0;
	cout << "Please enter 1 for easy difficulty (9 lives) or 2 for hard difficulty (6 lives): ";
	cin >> difficulty;
	cin.ignore();
	cout << endl;
	setDifficulty(difficulty);
}





void createBlanks(string word){
	for (size_t i = 0; i < word.size(); i++) {
		if (word.at(i) != ' '){
			foundLetters.push_back('_');
			numberOfLetters++;
		}
		else foundLetters.push_back(' ');
	}
}

void friendsTask() {
	cout << "Hi " << name << ". Please give this phone to a friend to enter a word." << endl;
	cout << endl;

	cout << "This is Hangman. Hello " << name << "'s friend." << endl;
	cout << "Please enter your name: ";
	getline(cin, friendsName);
	cout << endl;
	cout << "Now enter a word for " << name << " to guess: ";
	getline(cin, word);

	createBlanks(word);

	cout << endl;
	cout << "Please enter a hint for " << name << " if you wish, otherwise, just press enter." << endl;
	getline(cin, hint);

	for (int i = 0; i < 50; i++) {
		cout << endl;
	}
}





void print() {
	cout << "Guess the word: ";
	for (size_t i = 0; i < foundLetters.size(); i++) {
		cout << foundLetters.at(i);
	}
	cout << endl;
	if (!guesses.empty()) {
		cout << "Misses: ";
		for (size_t i = 0; i < misses.size(); i++) {
			cout << misses.at(i);
			if (i != misses.size() - 1)
				cout << ",";
		}
		cout << "\n\n\n";
	}
}



void startGame(){
	cout << friendsName << " has entered a word for you to guess." << endl;
	if (!hint.empty()) {
		cout << friendsName << " has given you this hint: " << hint << endl;
	}
	cout << endl;
	print();
}



bool alreadyGuessed(char guess) {
	for (size_t i = 0; i < guesses.size(); i++){
		if (guesses.at(i) == guess)
			return true;
	}
	return false;
}


void checkGuess(char guess) {
	bool successfulGuess = false;
	if (guess == ' ') {
		cout << "Invalid guess." << endl;
	}
	else if (alreadyGuessed(guess)) {
		cout << "You already entered this letter." << endl;
	}
	else {
		guesses.push_back(guess);
		for (size_t i = 0; i < word.size(); i++) {
			if (guess == word.at(i)) {
				successfulGuess = true;
				foundLetters.at(i) = guess;
				numberOfLetters--;
			}
		}
		if (!successfulGuess) {
			hangman++;
			misses.push_back(guess);
			cout << "The letter " << guess << " is not in the puzzle." << endl;
		}
		else {
			cout << "\nGood guess! \n" << endl;
		}
	}
}


void guess(){
	char guess;
	if (guesses.empty()) cout << name << ", please enter a guess: ";
	else cout << "Enter another guess: " << endl;
	cin >> guess;
	cin.ignore();
	checkGuess(guess);
}










void printHangman() {
	int ph = lives.at(hangman);

	switch (ph)
	{
	case 1:
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "-------" << endl;
		break;

	case 2:
		cout << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "-------" << endl;
		break;

	case 3:
		cout << "     ___" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "-------" << endl;
		break;

	case 4:
		cout << "     ___" << endl;
		cout << "  |     |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "-------" << endl;
		break;

	case 5:
		cout << "     ___" << endl;
		cout << "  |     |" << endl;
		cout << "  |     0" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "-------" << endl;
		break;

	case 6:
		cout << "     ___" << endl;
		cout << "  |     |" << endl;
		cout << "  |     0" << endl;
		cout << "  |     |" << endl;
		cout << "  |     |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "-------" << endl;
		break;

	case 7:
		cout << "     ___" << endl;
		cout << "  |     |" << endl;
		cout << "  |     0" << endl;
		cout << "  |    \\|" << endl;
		cout << "  |     |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "-------" << endl;
		break;

	case 8:
		cout << "     ___" << endl;
		cout << "  |     |" << endl;
		cout << "  |     0" << endl;
		cout << "  |    \\|/" << endl;
		cout << "  |     |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "-------" << endl;
		break;

	case 9:
		cout << "     ___" << endl;
		cout << "  |     |" << endl;
		cout << "  |     0" << endl;
		cout << "  |    \\|/" << endl;
		cout << "  |     |" << endl;
		cout << "  |    /" << endl;
		cout << "  |" << endl;
		cout << "-------" << endl;
		break;

	case 10:
		cout << "     ___" << endl;
		cout << "  |     |" << endl;
		cout << "  |     0" << endl;
		cout << "  |    \\|/" << endl;
		cout << "  |     |" << endl;
		cout << "  |    / \\ " << endl;
		cout << "  |" << endl;
		cout << "-------" << endl;
		break;

	default: cout << endl;
	}
}



void printAnswer(){
	cout << "'";
	for (size_t i = 0; i < word.size(); i++) {
		cout << word.at(i);
	}
	cout << "'. \n";
}



int main() {
	intro();
	pickDifficulty();
	friendsTask();
	startGame();
	while (numberOfLetters != 0 && hangman != lives.size() - 1) {
		guess();
		printHangman();
		print();
	}
	if (numberOfLetters == 0) {
		printAnswer();
		cout << "You guessed the word!" << endl;
	}

	else { //lost
		cout << "Game over! No more lives! :(" << endl;
		printHangman();
		cout << "The answer was ";
		printAnswer();
	}

	return 0;
}