#include<iostream>
#include<vector>
using namespace std;

map<vector<<int>> edges;
map<int> p;
vector<int> A, B;
int n, a, b;
int main()
{
  cin >> n >> a >> b;
  
  for(int i = 0; i < n; i++)
    cin >> p[i];

  if(p.size() % 2)
  {
    cout << "NO" << endl;
  }
  vector<int> singles, many;
  for(const auto v& : p)
  {
    edges[v] = vector<int>();
    if(p.find(a - v) != p.end())
      edges[v].push_back(a - v);
    if(p.find(b - v) != p.end())
      edges[v].push_back(a - v);
    if(edges[v].size() == 1)
      singles.push_back(v);
    else if(edges[v].size() > 1)
      many.push_back(v);
    if(edges[v].size() == 0)
    {
      cout << "NO" << endl;
      return 0;
    }
  }
  
  while(singles.size())
  {
    for(const auto v& : singles)
    {
      if(A.find(v) != A.end() || B.find(v) != B.end())
        continue;
      if(p.find(a - v) != p.end())
      {
        A.push_back(v);
        A.push_back(a - v);
      }
      else
      {
        B.push_back(v);
        B.push_back(b - v);
      }
    }
  }
  if(p.size() % 2)
  {
    cout << "NO" << endl;
    return 0;
  }
  
  while(true)
  {
    v = *p.begin();

  }
}
