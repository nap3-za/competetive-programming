#include <bits/stdc++.h> 
#include <vector>
#include <map>
#include <queue>
using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;
typedef pair<int, int> pii;


int main() {

	int rows = 5, cols = 7;
	vector<vector<pair<char, pair<bool, pair<int, int>>>>> matrix;

	for (int i=0; i<rows; i++) {
		vector<pair<char, pair<bool, pair<int, int>>>> col;
		for (int j=0; j<cols; j++) {
			col.push_back({'.', {false, {-1, -1}}});
		}
		matrix.push_back(col);
	}

	pair<char, pair<bool, pair<int, int>>> obstacle = {'#', {false, {-1, -1}}};
	matrix[0][3] = obstacle;
	matrix[1][1] = obstacle;
	matrix[1][5] = obstacle;
	matrix[2][1] = obstacle;
	matrix[3][2] = obstacle;
	matrix[3][3] = obstacle;
	matrix[4][0] = obstacle;
	matrix[4][2] = obstacle;
	matrix[4][5] = obstacle;

	pair<char, pair<bool, pair<int, int>>> target = {'E', {false, {-1, -1}}};
	pii target_cords = {4, 3};
	matrix[target_cords.first][target_cords.second] = target;
	
	queue<pii> track;

	int size = 0;
	bool found = false;

	pii start = {0,0};
	track.push(start);
	size++;

	while (size > 0 && not found) {
		pii current_block = track.front();
		int r = current_block.first;
		int c = current_block.second;

		matrix[r][c].second.first = true;

		vector<pii> possible_moves;
		possible_moves.push_back({r, c-1});
		possible_moves.push_back({r, c+1});
		possible_moves.push_back({r-1, c});
		possible_moves.push_back({r+1, c});

		for (pii move : possible_moves) {
			if ((move.first >= 0 && move.first < rows) && (move.second >= 0 && move.second < cols)) {
				pair<char, pair<bool, pair<int, int>>> block = matrix[move.first][move.second];

				if (block.first != obstacle.first && not block.second.first) {
					track.push(move);
					size++;
					matrix[move.first][move.second].second.second = current_block;

					if (block.first == target.first) {
						found = true;
						break;
					}
				}		
			}
		}

		track.pop();
		size--;
	}

	int moves = 0;
	if (found) {
		vector<pii> path;
		path.push_back(target_cords);

		pii current_block = target_cords;

		while (current_block != start) {
			pii prev_cords = matrix[current_block.first][current_block.second].second.second;
			path.push_back(prev_cords);
			current_block = prev_cords;
			moves++;
		}

		for (int i=moves-1; i>= 0; i--) printf("Go here : %d, %d\n", path[i].first, path[i].second);
		printf("\nMoves : %d \n", moves);

	}

	return 0;
}