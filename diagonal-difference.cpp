/*
Given a square matrix, calculate the absolute difference between the sum of its
diagonals.
For example, the square matrix  is shown below:
1 2 3
4 5 6
9 8 9

The left-to-right diagonal = 15. The right to left diagonal = 17.
Their absolute difference is 2.

Function description:
Complete the diagonalDifference function in the editor below.
diagonalDifference takes the following parameter:
- int arr[n][m]: an array of integers

Return:
- int: the absolute diagonal difference

Input Format:
The first line contains a single integer, n, the number of rows and columns in
the square matrix arr.
Each of the next n lines describes a row, arr[i], and consists of n 
space-separated integers arr[i][j].

Constraints:
-100 <= arr[i][j] <= 100

Output Format:
Return the absolute difference between the sums of the matrix's two diagonals
as a single integer.
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'diagonalDifference' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

// First input creates square matrix (num of rows = num of columns)  
int diagonalDifference(vector<vector<int>> arr) {
  int sumLeft = 0, sumRight = 0; 
  for (int i = 0; i < arr.size(); i++) {
    sumLeft += arr[i][i]; // sum of [0][0], [1][1], [2][2]
    sumRight += arr[i][arr.size() - i - 1]; // sum of [0][2] [1][1] [2][0]  
  }
  return abs(sumLeft - sumRight);
}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  string n_temp;
  getline(cin, n_temp);

  int n = stoi(ltrim(rtrim(n_temp)));

  vector<vector<int>> arr(n); 

  for (int i = 0; i < n; i++) {
    arr[i].resize(n);

    string arr_row_temp_temp;
    getline(cin, arr_row_temp_temp);

    vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

    for (int j = 0; j < n; j++) {
      int arr_row_item = stoi(arr_row_temp[j]);

      arr[i][j] = arr_row_item;
    }
  }

  int result = diagonalDifference(arr);

  fout << result << "\n";

  fout.close();

  return 0;
}

string ltrim(const string &str) {
  string s(str);

  s.erase(
    s.begin(),
    find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
  );

  return s;
}

string rtrim(const string &str) {
  string s(str);

  s.erase(
    find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
    s.end()
  );

  return s;
}

vector<string> split(const string &str) {
  vector<string> tokens;

  string::size_type start = 0;
  string::size_type end = 0;

  while ((end = str.find(" ", start)) != string::npos) {
    tokens.push_back(str.substr(start, end - start));

    start = end + 1;
  }

  tokens.push_back(str.substr(start));

  return tokens;
}

