#include <iostream>
#include <stdlib.h>  
#include <time.h>  

using namespace std;

void guess_comp_num();


int counter = 1;
int my_guess = 0;
int rand_num = 0;
int prev_num = 0;
/*

int main() {
	guess_comp_num();
	return 0;
}
*/
int randNum() {
	srand(time(NULL));
	rand_num = rand() % 100 + 1;
	return rand_num;
}

int getTheUserNumber() {
	cout << "Enter a number between 1 to 100..." << endl;
	cin >> my_guess;
	return my_guess;
}

void guess_comp_num() {
	
	getTheUserNumber();
	int random_number = randNum();

	while (my_guess != rand_num) {
		
		if (my_guess > 0 and my_guess <= 100) {
			if (my_guess > random_number) {
				cout << "Enter a smaller number" << endl;
				prev_num = my_guess;
				cin >> my_guess;
				if (prev_num < my_guess) {
					cout << "if you are running this program you suppose to be smart...." << endl;
				}
			}
			else {
				cout << "Enter a bigger number" << endl;
				prev_num = my_guess;
				cin >> my_guess;
				if (prev_num > my_guess) {
					cout << "if you are running this program you suppose to be smart...." << endl;
				}
			}

		}
		else {
			cout << "number between 1 - 100...." << endl;
		}
		counter++;
	}
	cout << "congratulations!!! this is the right number! ";
	cout << "you guess the number in " << counter << " guesses";
}
