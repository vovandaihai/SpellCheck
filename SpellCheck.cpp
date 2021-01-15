#include "SpellCheck.h"

using namespace std;

SpellCheck::SpellCheck(){
//cout << "contructor!" << endl;
dictionary.clear();
}

SpellCheck::~SpellCheck()
{
 //  cout << "destructor!" << endl;
}

void SpellCheck::read_dictionary(string file_name){
ifstream is(file_name);
string s;
while (is >> s)
{
 dictionary.insert(s);
}

 is.close();
}

bool SpellCheck::is_valid(string word)
{
    auto pos = dictionary.find(word);
    if (pos != dictionary.end())
       return true;
    return false;
}

void SpellCheck::process_file (string text_file)
{
  ifstream is(text_file);
  string s;
  
  while (getline(is,s))
  {
    int head = 0;
    bool new_word = true;
    for (int i = 0; i <= s.length(); i++)
    {
      string sub;
      if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\0')
	  {
        if (new_word == false)
		{ 
          sub = s.substr(head,i-head); 
          depunctuate(&sub);
          cout << sub;
          new_word = true;
          cout << s[i];
        }
        else
          cout << s[i]; 
      }
      else 
      {
        if (new_word == true) 
        {
          head = i;
          new_word = false;
        }
      }
    }
    cout << endl;
  }
}

bool is_white_space(char c)
{
  if (c == ' ' || c == '\t' == '\n')
    return true;
  else
    return false;
}

bool final_punctuation (string word)
{
  return word[word.length()-1] == '.' || word[word.length()-1] =='?' || \
word[word.length()-1] == ':' || word[word.length()-1] =='!' || \
word[word.length()-1] == ',';
}

void SpellCheck::depunctuate (string *str)
{
string s = *str;
string org = s; // to store orignal string 
string tail = s; // to store the last char which is "." "," "?"...

 if (s.length() == 1)
 if (s[0] == 'I' || s[0] >='0' && s[0] <='9')
    return;

 if (s[0] >= 'A' && s[0] <='Z')
    s[0] += 32;

 while (final_punctuation(s))
 {
   s = s.substr(0,s.length()-1);
 }

tail = tail.substr(s.length(),tail.length() - s.length()); 
org = org.substr(0,s.length());

 if (!is_valid(s)) 
 {
   ostringstream stringStream;
   stringStream << "*" << org << "*";
   org = stringStream.str();
 }

ostringstream stringStream;
stringStream << org << tail;

*str = stringStream.str();
}

