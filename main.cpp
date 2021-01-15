#include "SpellCheck.h"

int main() {
SpellCheck mySpell;
mySpell.read_dictionary("dictionary.txt");
mySpell.process_file("example.txt");
return 0;
}
