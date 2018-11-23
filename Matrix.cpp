#include <iostream>
#include <stdlib.h>    
#include <time.h>    
#include "Matrix.h"
#include <Windows.h>

using namespace std;

Matrix::Matrix(int size)
{
	m_size = size;
	m_matrix = new char*[size + 1];
	for (int i = 0; i < size; ++i)
	{
		m_matrix[i] = new char[size + 1];
	}
}

void Matrix::revive(int row, int col)
{
	m_matrix[row][col] = '#';
}

void Matrix::kill(int row, int col)
{
	m_matrix[row][col] = ' ';
}
bool Matrix::is_alive(int row, int col)
{
	if (m_matrix[row][col] == '#')
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Matrix::friends_count(int row, int col)
{
	int friends_count = 0;
	if (row != 0 || row != m_size || col != 0 || col != m_size) {
		
		if (is_alive(row - 1, col - 1))
		{
			friends_count++;
		}

		if (is_alive(row, col - 1))
		{
			friends_count++;
		}

		if (is_alive(row - 1, col))
		{
			friends_count++;
		}

		if (is_alive(row + 1, col - 1))
		{
			friends_count++;
		}

		if (is_alive(row - 1, col + 1))
		{
			friends_count++;
		}

		if (is_alive(row + 1, col))
		{
			friends_count++;
		}

		if (is_alive(row, col + 1))
		{
			friends_count++;
		}

		if (is_alive(row + 1, col + 1))
		{
			friends_count++;
		}
	}

 	return friends_count;
}

char Matrix::get_matrix(int row, int col) {
	return m_matrix[row][col];
}


























































































































/*if (row == 0 && col == 0)
		{
			if (is_alive(row + 1, col))
			{
				friends_count++;
			}
			
			if (is_alive(row, col + 1))
			{
				friends_count++;

			}			
			
			if (is_alive(row + 1, col + 1))
			{
				friends_count++;

			}
		}
		
		else if (row == m_size - 1 && col == m_size - 1)
		{
			if (is_alive(row - 1, col - 1))
			{
				friends_count++;
			}

			if (is_alive(row, col - 1))
			{
				friends_count++;
			}

			if (is_alive(row - 1, col))
			{
				friends_count++;
			}
		}
	
		else if (col == 0 && row == m_size - 1)
		{
			if (is_alive(row - 1, col + 1))
			{
				friends_count++;
			}

			if (is_alive(row, col + 1))
			{
				friends_count++;

			}

			if (is_alive(row - 1, col))
			{
				friends_count++;

			}
		}
	
		else if (col == m_size - 1 && row == 0)
		{
			if (is_alive(row + 1, col - 1))
			{
				friends_count++;
			}

			if (is_alive(row, col - 1))
			{
				friends_count++;
			}

			if (is_alive(row + 1, col))
			{
				friends_count++;
			}
		}

		else if (col == 0)
		{
			if (is_alive(row + 1, col))
			{
				friends_count++;
			}
			
			if (is_alive(row, col + 1))
			{
				friends_count++;
			}
			
			if (is_alive(row + 1, col + 1))
			{
				friends_count++;
			}
			
			if (is_alive(row - 1, col))
			{
				friends_count++;
			}
			
			if (is_alive(row - 1, col + 1))
			{
				friends_count++;
			}
		}
		
		else if (row == 0)
		{
			if (is_alive(row + 1, col))
			{
				friends_count++;
			}
			
			if (is_alive(row, col + 1))
			{
				friends_count++;
			}
			
			if (is_alive(row + 1, col + 1))
			{
				friends_count++;
			}
			
			if (is_alive(row, col - 1))
			{
				friends_count++;
			}
			
			if (is_alive(row + 1, col - 1))
			{
				friends_count++;
			}
		}
		
		else if (row == m_size - 1)
		{
			if (is_alive(row - 1, col - 1))
			{
				friends_count++;
			}
			
			if (is_alive(row, col - 1))
			{
				friends_count++;
			}
			
			if (is_alive(row - 1, col))
			{
				friends_count++;
			}
			
			if (is_alive(row - 1, col + 1))
			{
				friends_count++;
			}
			
			if (is_alive(row, col + 1))
			{
				friends_count++;
			}
		}
		
		else if (col == m_size - 1)
		{
			if (is_alive(row - 1, col - 1))
			{
				friends_count++;
			}
		
			if (is_alive(row, col - 1))
			{
				friends_count++;
			}
			
			if (is_alive(row - 1, col))
			{
				friends_count++;
			}
			
			if (is_alive(row + 1, col - 1))
			{
				friends_count++;
			}
			
			if (is_alive(row + 1, col))
			{
				friends_count++;
			}
		}
	
		else {*/