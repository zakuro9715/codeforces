#include<iostream>
#include<string>
using namespace std;


int h, w, dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
string board[100];
void dfs(int x, int y, char c)
{
  board[y][x] = c == 'W' ? 'B' : 'W';
  for(int i = 0; i < 4; i++)
  {
    int tx = x + dx[i], ty = y + dy[i];
    if(tx >= 0 && tx < w && ty >= 0 && ty < h && board[ty][tx] == '.')
      dfs(tx, ty, board[y][x]);
  }
}

int main()
{
  cin >> w >> h;
  for(int y = 0; y < h; y++)
    cin >> board[y];
  for(int y = 0; y < h; y++)
    for(int x = 0; x < w; x++)
      if(board[y][x] == '.')
        dfs(x, y, 'W');
  for(int y = 0; y < h; y++)
    cout << board[y] << endl;
}
