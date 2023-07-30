/*
Calculate and print the sum of the elements in an array, keeping in mind that
some of those integers may be quite large.

Function Description:
Complete the aVeryBigSum function in the editor below. It must return the sum
of all array elements.
aVeryBigSum has the following parameter(s):
- int ar[n]: an array of integers

Return:
- long: the sum of all array elements

Input Format:
The first line of the input consists of an integer .
The next line contains  space-separated integers contained in the array.

Output Format:
Return the integer sum of the elements in the array.

Constraints
1 <= n <= 10
0 <= ar[i] <= 10^10
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'aVeryBigSum' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER_ARRAY ar as parameter.
 */

long aVeryBigSum(vector<long> ar) {
  if (ar.empty()) {
    return 0;
  }
  long bigSum = 0;
  for (int i = 0; i < ar.size(); i++) {
    bigSum += ar[i];
  }
  return bigSum;
}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  string ar_count_temp;
  getline(cin, ar_count_temp);

  int ar_count = stoi(ltrim(rtrim(ar_count_temp)));

  string ar_temp_temp;
  getline(cin, ar_temp_temp);

  vector<string> ar_temp = split(rtrim(ar_temp_temp));

  vector<long> ar(ar_count);

  for (int i = 0; i < ar_count; i++)
  {
    long ar_item = stol(ar_temp[i]);

    ar[i] = ar_item;
  }

  long result = aVeryBigSum(ar);

  fout << result << "\n";

  fout.close();

  return 0;
}

string ltrim(const string &str)
{
  string s(str);

  s.erase(
      s.begin(),
      find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

  return s;
}

string rtrim(const string &str)
{
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end());

  return s;
}

vector<string> split(const string &str)
{
  vector<string> tokens;

  string::size_type start = 0;
  string::size_type end = 0;

  while ((end = str.find(" ", start)) != string::npos)
  {
    tokens.push_back(str.substr(start, end - start));

    start = end + 1;
  }

  tokens.push_back(str.substr(start));

  return tokens;
}
