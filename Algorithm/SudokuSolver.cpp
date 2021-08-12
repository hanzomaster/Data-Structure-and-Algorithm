#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;
bool isValidSudoku(vector<vector<char>> &board) {
	unordered_set<string> seen;
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j) {
			char current_val = board[i][j];
			if (current_val != '.') {
				if (!seen.insert(to_string(current_val) + " in row " + to_string(i)).second ||
				    !seen.insert(to_string(current_val) + " in column " + to_string(j)).second ||
				    !seen.insert(to_string(current_val) + " in sub box " + to_string(i / 3) + '-' + to_string(j / 3)).second)
					return false;
			}
		}
	return true;
}

void backtrackToNext(vector<vector<char>> &a, int i, int j) {
	int next_i, next_j;
	if (j < 8) {
		next_i = i;
		next_j = j + 1;
	} else {
		next_i = i + 1;
		next_j = 0;
	}
	backtrack(a, next_i, next_j);
}

void backtrack(vector<vector<char>> &a, int i, int j) {
	if (i >= 0 && i < 8 && j >= 0 && j <= 8) {
		if (a[i][j] == '.') {
			for (char c = '1'; c <= '9'; ++c) {
				a[i][j] == c;

				if (i == 8 && j == 8)
					if (isValidSudoku(a))
						return;
					else
						backtrackToNext(a, i, j);
			}
		} else
			backtrack(a, i, j);
	}
}

void SudokuSolver(vector<vector<char>> &a) {
}

int main() {
	vector<vector<char>> a = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
	                          {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
	                          {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
	                          {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
	                          {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
	                          {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
	                          {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
	                          {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
	                          {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
}
