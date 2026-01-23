#include <bits/stdc++.h>
using namespace std;
int row, col;
bool dfs(int r, int c, int idx, const vector<vector<char>> &board, const string &word, vector<vector<bool>> &visited)
{
    if (idx == (int)word.size())
        return true;
    if (r < 0 || r >= row || c < 0 || c > col || board[r][c] != word[idx] || visited[r][c])
        return false;
    visited[r][c] = true;
    bool found = (dfs(r + 1, c, idx + 1, board, word, visited) ||
                  dfs(r - 1, c, idx + 1, board, word, visited) ||
                  dfs(r, c + 1, idx + 1, board, word, visited) ||
                  dfs(r, c - 1, idx + 1, board, word, visited));
    visited[r][c] = false;
    return found;
}

bool exist(vector<vector<char>> &board, string &word)
{
    row = board.size();
    col = board[0].size();
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (dfs(i, j, 0, board, word, visited))
                return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> board = {{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}};
    string word = "sfl";
    cout << exist(board, word);
}