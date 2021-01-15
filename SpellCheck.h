#ifndef SPELLCHECK_H
#define SPELLCHECK_H
#include <iostream>
#include <bits/stdc++.h>
#include <unordered_set>
#include <fstream>
#include <string>
using namespace std;

class SpellCheck {
public:
unordered_set<string> dictionary;

SpellCheck();

~SpellCheck();

/*@read_dictionary 
* file_name: path to dictionary file
*/
void read_dictionary(string file_name); 

/*@is_valid
* word: check word is spelled correctly or not 
* return: True if correct
*         False otherwise 
*/
bool is_valid(string word);

/*@process_file
* text_file: file input to check
*/
void process_file (string text_file);

/* @depunctuate
*  change first character of input lowercase, removing final punctuation mark if there is one
*  str: input string
*/
void depunctuate (string *str);
}; //class Spell check

/* @is_white_space
*  check charactor is space, tab, newline or not
*  word: word to check
*  return: True if yes
*          False otherwise
*/
bool is_white_space (char c);

/* @final_punctuation
*  check if final character is a punctuation mark
*  word: word to check
*  return: True if yes
*          False otherwise
*/
bool final_punctuation (string word);
#endif
