#include<iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;

queue<int> q;
vector<pair<int, int>> edges;
int vertices[100000][2], N;
int main()
{
  cin >> N;
  for(int i = 0; i < N; i++)
  {
    int d, s;
    cin >> d >> s;
    if(d == 1)
      q.push(i);
    vertices[i][0] = d;
    vertices[i][1] = s;
  }

  while(!q.empty())
  {
    int i = q.front(); q.pop();
    int to = vertices[i][1];

    if(!vertices[i][0])
      continue;

    edges.push_back(make_pair(i, to));

    vertices[to][0]--;
    vertices[to][1] ^= i;

    if(vertices[to][0] == 1)
      q.push(to);
  }
  cout << edges.size() << endl;
  for(auto e: edges)
    cout << e.first << " " << e.second << endl;
}
