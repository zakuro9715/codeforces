#include<iostream>
#include<string>
using namespace std;

int main()
{
  string s;
  int n;
  cin >> s;
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    string t;
    int l, r;
    cin >> l >> r;
    t = s.substr(l - 1, r - l + 1);
    int st = 0, ans = 0;
    for(int j = 0; j < t.length(); j++)
    {
      if(t[j] == '(')
        st++;
      else if(t[j] == ')')
      {
        if(st > 0)
        {
          ans += 2;
          st--;
        }
      }
    }
    cout << ans << endl;
  }
}
