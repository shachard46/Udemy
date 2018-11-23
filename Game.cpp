#include <iostream>
#include <stdlib.h>    
#include <time.h>
#include "Matrix.h"
#include "Game.h"
#include "windows.h" 

using namespace std;

Game::Game(int size) {
	m_status = "stay";
	m_size = size;
	matrix = new Matrix(m_size);
	m_status_matrix = new char*[size];
	for (int i = 0; i < size - 1; ++i)
	{
		m_status_matrix[i] = new char[size];
	}
}

Game::~Game() {
	delete matrix;
}
void Game::board_build() {
		for (int row = 0; row < m_size; row++)
		{
			for (int col = 0; col < m_size; col++)
			{
				if (row == 0 || row == m_size || col == 0 || col == m_size) 
				{
					matrix->kill(row, col);
				}
				else 
				{
					m_rand_num = rand() % 2;
					if (m_rand_num == 0)
					{
						matrix->revive(row, col);
					}
					else
					{
						matrix->kill(row, col);
					}
				}

				cout << matrix->get_matrix(row, col);
			}
			cout << endl;
		}
/*		matrix->revive(8, 1 + 8);
		cout << matrix->get_matrix(8, 1 + 8);
		matrix->revive(8, 2 + 8);
		cout << matrix->get_matrix(8, 2 + 8);
		matrix->revive(8, 3 + 8);
		cout << matrix->get_matrix(8, 3 + 8);
		matrix->revive(8, 4 + 8);
		cout << matrix->get_matrix(8, 4 + 8);
		matrix->revive(8, 5 + 8);
		cout << matrix->get_matrix(8, 5 + 8);
		matrix->revive(8, 6 + 8);
		cout << matrix->get_matrix(8, 6 + 8);
		matrix->revive(8, 7 + 8);
		cout << matrix->get_matrix(8, 7 + 8);
		matrix->revive(8, 8 + 8);
		cout << matrix->get_matrix(8, 8 + 8);
		matrix->revive(8, 9 + 8);
		cout << matrix->get_matrix(8, 9 + 8);
		matrix->revive(8, 10 + 8);
		cout << matrix->get_matrix(8, 10);*/

}

void Game::status() {
	for (int row = 1; row < m_size - 1; row++)
	{
		for (int col = 1; col < m_size - 1; col++)
		{
			if (row == 0 || row == m_size || col == 0 || col == m_size) 
			{
				cout << row;
			}
			else
			{
				if (matrix->is_alive(row, col) && matrix->friends_count(row, col) <= 1) {
					m_status = "kill";
				}
				else if (!matrix->is_alive(row, col) && matrix->friends_count(row, col) == 3) {
					m_status = "revive";
				}
				else if (matrix->is_alive(row, col) && matrix->friends_count(row, col) > 3) {
					m_status = "kill";
				}
				else {
					m_status = "stay";
				}
				add_to_status_matrix(row, col);
				}
		}
	}
}
void Game::change(int row, int col) {
	if (row == 0 || row == m_size || col == 0 || col == m_size)
	{

	}
	else
	{
		if (m_status_matrix[row][col] == '#') {
			matrix->revive(row, col);
		}
		else if (m_status_matrix[row][col] == ' ')
		{
			matrix->kill(row, col);
		}
	}
}
void Game::add_to_status_matrix(int row, int col) {
	if (m_status.compare("revive") == 0) {
		m_status_matrix[row][col] = '#';
	}
	else if(m_status.compare("kill") == 0){
		m_status_matrix[row][col] = ' ';
	}
}
void Game::paint()
{
	for (int row = 1; row < m_size - 1; row++)
	{

		for (int col = 1; col < m_size - 1; col++)
		{
			if (row == 0 || row == m_size || col == 0 || col == m_size)
			{
				matrix->kill(row, col);
			}
			change(row, col);
			cout << matrix->get_matrix(row, col);
		}
		cout << endl;
	}
	Sleep(10);
	erase();
}

void Game::erase()
{
	system("cls");
}