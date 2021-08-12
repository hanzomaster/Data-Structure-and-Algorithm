#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

bool isValidSudoku(std::vector<std::vector<char>> &board) {
	std::unordered_set<std::string> seen;
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j) {
			char current_val = board[i][j];
			if (current_val != '.') {
				if (!seen.insert(std::to_string(current_val) + " in row " + std::to_string(i)).second ||
				    !seen.insert(std::to_string(current_val) + " in column " + std::to_string(j)).second ||
				    !seen.insert(std::to_string(current_val) + " in sub box " + std::to_string(i / 3) + '-' + std::to_string(j / 3)).second)
					return false;
			}
		}
	return true;
}

int main() {
	std::vector<std::vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
	                                        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
	                                        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
	                                        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
	                                        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
	                                        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
	                                        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
	                                        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
	                                        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
	if (isValidSudoku(board))
		std::cout << "True";
	else
		std::cout << "False";
}
