#include <iostream>

using namespace std;



char cipher[10000];


bool sameString(int i1, int j1, int i2) {
  for (; i1 < j1; i1++, i2++) {
    if (cipher[i1] != cipher[i2]) {
      return false;
    }
    // i2++;
  }
  return true;
}


void printSubstring(int i, int j) {
  for (; i < j; i++) {
    cout << cipher[i];
  }
  cout << "\n";
}


void searchForSubstring(int i, int j, int len) {
  int numberOfSubstrings = 0;
  for (int i0 = 0; i0 < len; i0++) {
    if (sameString(i, j, i0)) {
      numberOfSubstrings++;
    }
  }
  if (numberOfSubstrings >= 2 && (j - i) > 2) {
    printSubstring(i, j);
    cout << "\n";
  }
}


int main(int argc, char const *argv[]) {
  if (argc < 2 or argc > 3) {
    printf("Bad number of arguments\n");
    return -1;
  }

  FILE *fd = fopen(argv[1], "r");
  int len = -1;
  char mark = '0';
  while ((mark = getc(fd)) != EOF) {
    len++;
    cipher[len] = mark;
  }

  for (int i = 0; i < len; i++) {
    for (int j = i + 2; j < len; j++) {
      searchForSubstring(i, j, len);
    }
  }

  // printf("%c\n", cipher[224]);
  // searchForSubstring(221, 224, len);

  return 0;
}
