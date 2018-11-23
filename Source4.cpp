#include <iostream>
#include <stdlib.h>  
#include <string>
#include <sstream>

using namespace std;

string encode(string text);
/*
int main() {
	cout << encode("DONKEY");
	return 0;
}
*/
string morse[36] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
	"..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
	"...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---",
	"...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"
};

char alphabet[36] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
	'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y',
	'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'
};

string encode(string text) {
	string encoded_word = "";
	for (int i = 0; i < 6; i++) {
		for (int h = 0; h < 36; h++) {
			if (text[i] == alphabet[h]) {
				encoded_word += morse[h] + " ";
			}
		}
	}
	return encoded_word;
}

