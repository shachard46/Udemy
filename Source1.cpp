#include <iostream>
#include <stdlib.h>  
#include <time.h>  

using namespace std;

int rhombus(int diagonal1, int diagonal2);



int rhombusSide(int diagonal1, int diagonal2) {
	int pitagoras = (diagonal1 * diagonal1 + diagonal2 * diagonal2) / 4;
	int rhombus_side = (int)sqrt(pitagoras);
	return rhombus_side;
}
int rhombus(int diagonal1, int diagonal2) {
	int space = 0;
	int rhombus_side = rhombusSide(diagonal1, diagonal2);
	for (int c_width = 0; c_width < rhombus_side; c_width++) {
		for (int c_length = 0; c_length < rhombus_side * 2 - 1; c_length++) {
			if (c_width == rhombus_side - 1 and c_length >= space) {
				std::cout << "# ";
			}
			else if(c_width == 0 and c_length <= rhombus_side + space - 1){
				std::cout << "# ";
			}
			else if (c_length == space or c_length == rhombus_side + space ) {
				std::cout << "#";
			}
			else if(c_length > space){
				std::cout << "  ";
			}
			else {
				std::cout << " ";
			}
		}
		space++;
		std::cout << "" << endl;
	}
	return 0;
}
