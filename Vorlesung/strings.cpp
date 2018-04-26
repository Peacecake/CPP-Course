#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

/**
 *  Für UTF-8 encodeing: ICU Bibliothek von IBM (http://site.icu-project.org/)
 */

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