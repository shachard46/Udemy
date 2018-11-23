#include <iostream>
#include <stdlib.h>  
#include <string>
#include <sstream>

using namespace std;

int tenToFiften [6] = { 10, 11, 12, 13, 14, 15 };
string aToF[6] = { "A", "B", "C", "D", "E", "F" };

int decimalToHexadecimal(int decimal_num);
/*
int main() {
	decimalToHexadecimal(1614151312);
		return 0;
}
*/
int numLength(int decimal_num) {
	string decimal_num_str = "" + decimal_num;
	int num_length = decimal_num_str.length();
	return num_length;
}
void reverse(string str)
{
	for (int i = str.length() - 1; i >= 0; i--)
		cout << str[i];
}
int decimalToHexadecimal(int decimal_num) {
	string sum = "";
	int	devide = decimal_num;
	int sheerit = 0;
	int sec_devide = 0;
	string str_sheerit = "";
	while(devide > 0) {
		sec_devide = devide / 16;
		sheerit = devide % 16;
		devide = sec_devide;
		if (sheerit > 9 and sheerit < 16) {
			for (int h = 0; h < 6; h++) {
				if (tenToFiften[h] == sheerit) {
					str_sheerit = aToF[h];
					sum.append(str_sheerit);
				}
			}
		}
		else{
			ostringstream convert; 
			convert << sheerit;
			str_sheerit = convert.str();
			sum.append(str_sheerit);
			
		}
		
	}
		reverse(sum);
	return 0;
}
