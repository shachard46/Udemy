#ifndef _INC_MATRIX
#define _INC_MATRIX

class Matrix
{
	private:
		int m_size;
		char** m_matrix;
	public:
		Matrix(int size);
	
		void revive(int row, int col);
	
		void kill(int row, int col);
	
		bool is_alive(int row, int col);
	
		int friends_count(int row, int col);

		char get_matrix(int row, int col);

	
};
#endif // !_INC_MATRIX
