#include<iostream>
#include<vector>
using namespace std;

struct S{
  int begin, end;
  S(int b, int e)
  {
    begin = b;
    end = e;
  }
};

int A[100000], N, ans;
vector<S> mem;

int main()
{
  cin >> N;
  for(int i = 0; i < N; i++)
    cin >> A[i];
  int st = 0;
  for(int i = 1; i < N; i++)
  {
    if(!(A[i] > A[i - 1]))
    {
      mem.push_back(S(st, i));
      ans = max(ans, i - st + 1);
      st = i;
    }
  }
  mem.push_back(S(st, N));
  ans = max(ans, N - st + 1);
  
  for(int i = 1; i < mem.size(); i++)
  {
    if(mem[i].end - mem[i].begin < 2 ||
       A[mem[i].begin + 1] - A[mem[i - 1].end - 1] < 2)
      continue;
    ans = max(ans, mem[i].end - mem[i - 1].begin);
  }
  cout << min(ans, N) << endl;
}
