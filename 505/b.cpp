#include<vector>
#include<iostream>
#include<queue>
using namespace std;

vector<int> nodes[100][100];

int N, M;

bool bfs(int a, int b, int c)
{
  queue<int> q;
  q.push(a);
  bool done[100];
  fill(done, done + 100, false);
  while(!q.empty())
  {
    int x = q.front(); q.pop();
    if(x == b)
      return true;
    for(const auto& n: nodes[x][c])
    {
      if(done[n])
        continue;
      done[n] = true;
      q.push(n);
    }
  }
  return false;
}

int main()
{
  cin >> N >> M;
  for(int i = 0; i < M; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--; c--;
    nodes[a][c].push_back(b);
    nodes[b][c].push_back(a);
  }

  int Q;
  cin >> Q;
  for(int i = 0; i < Q; i++)
  {
    int a, b, n = 0;
    cin >> a >> b;
    a--; b--;
    for(int c = 0; c < M; c++)
      if(bfs(a, b, c))
        n++;
    cout << n << endl;
  }
}
