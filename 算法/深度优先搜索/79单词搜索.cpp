class Solution {
		bool flag = false;
		bool hashTable[6][6] = {false};
	public:
		void dfs(int t, int x, int y, vector<vector<char>> &board, string word) {
			if (t == word.size()) {
				flag = true;
				return;
			}
			int x_t = board.size();
			int y_t = board[0].size();
			if (x == -1 || x == x_t || y == -1 || y == y_t)
				return;
			if (!hashTable[x][y]) {
				hashTable[x][y] = true;
				if (board[x][y] == word[t]) {
					dfs(t + 1, x + 1, y, board, word);
					if (x != x_t - 1) {
						hashTable[x + 1][y] = false;
					}
					dfs(t + 1, x - 1, y, board, word);
					if (x != 0) {
						hashTable[x - 1][y] = false;
					}
					dfs(t + 1, x, y + 1, board, word);
					if (y != y_t - 1) {
						hashTable[x][y + 1] = false;
					}
					dfs(t + 1, x, y - 1, board, word);
					if (y != 0) {
						hashTable[x][y - 1] = false;
					}
				} else {
					dfs(0, x + 1, y, board, word);
					if (x != x_t - 1) {
						hashTable[x + 1][y] = false;
					}
					dfs(0, x - 1, y, board, word);
					if (x != 0) {
						hashTable[x - 1][y] = false;
					}
					dfs(0, x, y + 1, board, word);
					if (y != y_t - 1) {
						hashTable[x][y + 1] = false;
					}
					dfs(0, x, y - 1, board, word);
					if (y != 0) {
						hashTable[x][y - 1] = false;
					}
				}
			}
		}
		bool exist(vector<vector<char>> &board, string word) {
			string tmp;
			dfs(0, 0, 0, board, word);
			return flag;
		}
};