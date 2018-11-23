#include <iostream>
#include <stdlib.h>  
#include <string>
#include <sstream>

using namespace std;

int rectangle(int width, int length) {
	for (int i = 0; i < width; i++) {
		for (int h = 0; h < length; h++) {
			if (i == 0 or i == width - 1) {
				cout << "#";
			}
			else if (h == 0 or h == length - 1) {
				cout << "#";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
/*
int main() {
	rectangle(6, 7);
	return 0;
}
*/
