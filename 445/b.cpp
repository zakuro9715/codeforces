#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int mem[50], n, m;
vector<int> p[50];

int dfs(int a)
{
  int ans = 1;
  mem[a] = true;
  for(int k = 0; k < p[a].size(); k++)
  {
    if(mem[p[a][k]])
      continue;
    ans = max(ans, dfs(p[a][k]) * 2);
  }
  mem[a] = false;
  return ans;
}

int main()
{
  cin >> n >> m;
  for(int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    a--; b--;
    p[a].push_back(b);
    p[b].push_back(a);
  }
  int ans = 1;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < 50; j++)
      mem[j] = false;
    ans = max(ans, dfs(i));
  }
  cout << ans << endl;
}
