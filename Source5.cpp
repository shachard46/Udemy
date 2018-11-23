#include <iostream>
#include <stdlib.h>  
#include <string>
#include <sstream>

using namespace std;

string derivative(string expression);
string decrease(string expression);
/*
int main() {
	cout << decrease(derivative("x^2 + x^2 - 2x - 9x"));
		return 0;
}
*/
string derivative(string expression) {
	string derivative_result = "";
	for (int i = 0; i < expression.length(); i++) {
		if (expression[i] == 'x') {
			if (expression[i + 1] == '^') {
				derivative_result += expression[i + 2];
				derivative_result += 'x';
			}
			else {
				derivative_result += expression[i - 1];
			}
		}
		else if (expression[i] == '+' or expression[i] == '-') {
			derivative_result += expression[i];
		}
	}
	return derivative_result;
}

string decrease(string expression) {
	int xsum = 0;
	int numsum = 0;
	string strx = "";
	string strnum = "";
	string total = "";
	for (int h = 0; h < expression.length(); h++) {
		if (expression[h] == 'x') {
			if (h >= 2) {
				if (expression[h - 2] == '+') {
					xsum += 2;
				}
				else {
					xsum -= 2;
				}
			}
			else if (h == 1) {
				xsum += 2;
			}
			else {
				xsum -= 2;
			}

		}
		else if(expression[h + 1] != 'x' && expression[h] != '+'&& expression[h] != '-'){
			if (h >= 1) {
				if (expression[h - 1] == '+') {
					numsum += ((int)expression[h] - 48);
				}
				else {
					numsum -= ((int)expression[h] - 48);
				}
			}
			else{
				numsum += ((int)expression[h] - 48);
			}

		}
	}
	ostringstream convert;
	ostringstream convert1;
	convert1 << numsum;
	convert << xsum;
	if (xsum != 0) {
		strx = convert.str() + 'x';
	}
	if (numsum > 0) {
		strnum = '+' + convert1.str();
	}
	else if (numsum < 0) {
		strnum = convert1.str();
	}

	total = strx + strnum;
	return total;
}

