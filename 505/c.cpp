#include<iostream>
using namespace std;

int dp[30001][1000], N, D, gem[30001];

int dfs(int a, int b)
{
  if(dp[a][b] != -1)
  {
    dp[a][b] = 1;
    return dp[a][b];
  }
  int res = 0;
  for(int i = -1; i <= 1; i++)
  {
    int v = D + b + i;
    if(v > 0 && a + v < 30001)
      res = max(res, dfs(a + v, b + i));
  }
  return dp[a][b] = res + gem[a];
}

int main()
{                 
  cin >> N >> D;
  for(int i = 0; i < N; i++)
  {
    int a;
    cin >> a;
    gem[a]++;
  }
  fill((int*)dp, (int*)dp + 30001 * 1000, -1);
  cout << dfs(D, 0) << endl;
}
