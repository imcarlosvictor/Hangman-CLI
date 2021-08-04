#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#include <vector>

using namespace std;


string random_word(string []);
void validate_answer(string, char, vector<int>&, int&);
void validate_answer(string, string, int&, bool&);

int main()
{
  // ############# GAME SETTINGS #############
  string word_list[] = {"hello", "world", "bye"};
  string word;
  vector<int> valid_guesses;
  int lifeline = 5;
  int user_choice = 0; // 1. Letter or 2.Word
  char answer_letter; 
  string answer_word;
  bool win = false;

  // ############# CHOOSE RANDOM WORD #############
  word = random_word(word_list);

  do {
    // ############# GAME LOGIC #############
    if (win){
      cout << "\n\nThanks for playing!\n\n";
      break;
    }
    
    // TODO: 1. Print correct guesses on display
    // Display random word on screen
    cout << word << endl;
    for (int i=0; i<word.length(); ++i) {
      bool print_guess;
      for (int j=0; j<valid_guesses.size(); ++j) {
        // Print letters that were guessed correctly
        if (i == valid_guesses[j]) {
          cout << word[i];
        }
      }
    }
    cout << endl;

    // Prompt user to make a guess
    cout << "Options:\n1. Letter\n2. Word\nChoose input type: ";
    cin >> user_choice;

    switch (user_choice) {
      case 1:
        // Validate character
        cout << "Enter a letter: ";
        cin >> answer_letter;
        validate_answer(word, answer_letter, valid_guesses, lifeline);
        break;
      case 2:
        // Validate word
        cout << "Enter word: ";
        cin >> answer_word;
        validate_answer(word, answer_word, lifeline, win);
        break;
      default:
        cout << "Choose either option." << endl;
        break;
    }
  } while (lifeline > 0);

  return 0;
}

string random_word(string word_list[])
{
  // Generate a random number
  srand(time(NULL));
  int random_num = rand() % 3;
  // Choose random word
  string word = word_list[random_num];
  return word;
}

void validate_answer(string random_word, char answer, vector<int> &guesses,  int& lifeline)
{
  // Validate character
  bool valid = false;
  for (int i=0; i<random_word.length(); ++i) {
    if (random_word[i] == answer) {
      guesses.push_back(i);  // Return index of letter
      valid = true;
      break;
    }
  }

  // Result after validation
  // TODO: Match result
  // TODO: Wrong guess
  if (valid) {
    cout << "\nCorrect\n";
  } else {
    lifeline -= 1;
    cout << "\n#############";
    cout << "\nWrong guess";
    cout << "\nRemaining chances: " << lifeline;
    cout << "\n#############\n\n";
  }
}

void validate_answer(string random_word, string answer, int& lifeline, bool& win)
{
  // Validate word
  bool valid = true;
  for (int i=0; i<random_word.length(); ++i) {
    if (random_word[i] != answer[i]) {
      valid = false;
      break;
    }
  }

  // Result after validation
  // TODO: Match Result
  // TODO: Wrong guess
  if (valid) {
    win= true;
    cout << "\n*****************";
    cout << "\n**** Winner! ****";
    cout << "\n*****************";
  } else {
    lifeline -= 1;
    cout << "\n#############";
    cout << "\nWrong guess";
    cout << "\nRemaining chances: " << lifeline;
    cout << "\n#############\n\n";
  }
}
