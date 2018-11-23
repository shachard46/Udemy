#include <iostream>
#include <vector>
#include <string>


enum State {
	operand,
	m_operator,
	squerex
};

using namespace std;
vector<string> operands;
vector<char> operators;
vector<int> mekadem;

string analysis(string express) {
	int calcMecadem = 0;
	int stop = 0;
	int wait = 0;
	State m_state = State::operand;
	
	for (int i = 0; i < express.length(); i++)
	{
		switch (m_state) {
		case operand:
			if (express[i] != 'x') {
				mekadem.push_back((int)express[i] - 48);
				if (express[i] == '+' || express[i] == '-') {
					mekadem.clear();
					break;
				}
			}
			else {
				for (int h = 0; h < mekadem.size(); h++) {
					calcMecadem += (int)(pow(10, (mekadem.size() - 1 - h)) * mekadem[h]);
				}
				if (express[i + 1] == '^') {
					m_state = State::squerex;
					stop = 0;
					break;
				}
				else {
					string operand = to_string(calcMecadem) + "x";
					operands.push_back(operand);
					mekadem.clear();
					calcMecadem = 0;
					m_state = State::m_operator;
				}
			}
			break;

		case m_operator:
			operators.push_back(express[i]);

			m_state = State::operand;
			break;

		case squerex:
			while (stop == 0) {
				string operand = to_string(calcMecadem * 2) + "xd";
				operands.push_back(operand);
				mekadem.clear();
				calcMecadem = 0;
				wait = i;
				stop++;
			}
			if (i == wait + 1) {
				m_state = State::m_operator;
			}
			break;
		}
	}
	string total = "";
	int mekadem_pow = 0;
	int mekadem_num = 0;
	for (int i = 0; i < operands.size(); i++) {
		operands[i] = operands[i].substr(0, operands[i].length() - 1);
		size_t found = std::count(operands[i].begin(), operands[i].end(), 'x');
		if (found == 1) {
			int add_to_mekadem = stoi(operands[i].substr(0, operands[i].length() - 1));
			if (i == 0) {
				mekadem_pow += add_to_mekadem;
			}
			else if (operators[i - 1] == '+') {
				mekadem_pow += add_to_mekadem;
			}
			else {
				mekadem_pow -= add_to_mekadem;
			}
		}
		else {
			int add_to_mekadem = stoi(operands[i]);
			if (i == 0) {
				mekadem_num += add_to_mekadem;
			}
			else if (operators[i-1] == '+') {
				mekadem_num += add_to_mekadem;
			}
			else {
				mekadem_num -= add_to_mekadem;
			}
		}
	}
	string pow_str = to_string(mekadem_pow);
	string num_str = to_string(mekadem_num);
	if (mekadem_pow != 0) {
		total += pow_str + 'x';
	}
	if (mekadem_num > 0) {
		total += '+' + num_str;
	}
	else if (mekadem_num < 0) {
		total += num_str;
	}

	return total;
}

/*
int main() {
	cout << analysis("18x^2-17000x-1+7x-45x^2+2+2x+9x+6+5-5-8-9");

	return 0;
}
*/

