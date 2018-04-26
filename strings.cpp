#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  string s;
  string s1("hans");

  cout << s << endl;
  cout << s1 << endl;

  reverse(s1.begin(), s1.end());
  cout << s1 << endl;

  return 0;
}