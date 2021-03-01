#include <iostream>
#include <vector>

using namespace std;

vector <char> koszyki[6];

int main(int argc, char const *argv[]) {
  string text;
  cin >> text;

  for (int a = 0; a < text.length(); a++) {
    koszyki[a % 6].push_back(text[a]);
  }

  for (int a = 0; a < 6; a++) {
    for (int b = 0; b < koszyki[a].size(); b++) {
      cout << koszyki[a][b];
    }
    cout << "\n\n";
  }
  return 0;
}
