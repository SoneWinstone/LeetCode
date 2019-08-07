#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int x;
  cin >> x;
  if (x < 0)
  {
    return false;
  }
  string s = to_string(x);
  bool ret = true;
  for (int i = 0; i < s.length() / 2; ++i)
  {
    if (s[i] != s[s.length() - 1 - i])
    {
      ret = false;
    }
  }
  cout << ret << endl;
  return 0;
}
