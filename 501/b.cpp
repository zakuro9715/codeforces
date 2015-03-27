#include<iostream>
#include<vector>
#include<string>
#include<utility>
using namespace std;

int N;
vector<pair<string, string>> v;
int main()
{
  cin >> N;
  for(int i = 0; i < N; i++)
  {
    string s1, s2;
    bool found = false;
    cin >> s1 >> s2;
    for(auto it = v.begin(); it != v.end(); ++it)
    {
      if(it->first == s1)
      {
        found = true;
        it->first = s2;
      }
    }
    if(!found)
    {
      v.push_back(make_pair(s2, s1));
    }
  }
  cout << v.size() << endl;
  for(auto it = v.begin(); it != v.end(); ++it)
    cout << it->second << " " << it->first << endl;  
}
