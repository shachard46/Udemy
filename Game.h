#ifndef _INC_GAME
#define _INC_GAME
#include <stdlib.h> 
#include <string>

#include "Matrix.h"

using namespace std;

class Game 
{
private:
	string m_status;
	int m_rand_num;
	int m_size;
	Matrix* matrix;
	char** m_status_matrix;

public:
	void status();
	
	void add_to_status_matrix(int row, int col);
	
	void board_build();
	
	Game(int size);

	void change(int row, int col);
	
	void erase();

	void paint();
	~Game();
	
};
#endif // !_INC_GAME
