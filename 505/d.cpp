#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;

int N, M;
set<int> out[100001];
set<int> in[100001];
queue<int> q;
int main()
{
  cin >> N >> M;
  for(int i = 0; i < M; i++)
  {
    int a, b;
    cin >> a >> b;
    out[a].insert(b);
    in[b].insert(a);
  }

  for(int i = 0; i < N; i++)
    if(in[i].size() == 1)
      q.push(i);
  while(!q.empty())
  {
    int n = q.front(); q.pop();
    if(in[n].size() != 1)
      continue;
    // nへのエッジは1つのみ
    int st = *in[n].begin();
    for(const auto& v: out[st])
    {
      if(n == v)
        continue;
      out[n].insert(v);
      if(!in[v].erase(st))
      {
        cout << "Abort" << endl;
        return 1;
      }
      if(in[v].size() == 1)
        q.push(v);
    }
  }
  int ans = 0;
  for(int i = 0; i < N; i++)
    ans += in[i].size();
  cout << ans + 1 << endl;
}
