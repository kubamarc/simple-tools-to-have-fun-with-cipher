#include <iostream>
#include <vector>

using namespace std;


vector <string> dwuznaki;

void generuj_dwuznaki() {
  // int ktory = 0;
  // for (int i1 = 0; i1 < 26; i1++) {
  //   for(int i2 = 0; i2 < 26; i2++) {
  //     string dwuznak = "aa";
  //     char znak = 97 + i1;
  //     dwuznak[0] = znak;
  //     znak = 97 + i2;
  //     dwuznak[1] = znak;
  //     dwuznaki.push_back(dwuznak);
  //   }
  // }
  string dwuznak = "JA";
  for (int a = 0; a < 26; a++) {
    dwuznaki.push_back(dwuznak);
    dwuznak[1]++;
  }
}

char hasluj(char x, char y) {
  int lx = x - 'A';
  int ly = y - 'A';
  int lret = (lx + ly) % 26;
  char ret = lret + 'A';
  return ret;
}

void deszyfruj(string tekst, string od_has) {
  int i = 0;
  // cout << "\n" << od_has << "\n";
  while (tekst[i] >= 'A' && tekst[i] <= 'Z') {
    char litera_tekstu = hasluj(tekst[i], od_has[i % 3]);
    cout << litera_tekstu;
    i++;
  }
  cout << "\n\n";
}

string odwroc_haslo() {
  string haslo = "OHY";
  string odwrocone_haslo = "AAA";
  for (int a = 0; a < 6; a++) {
    int fir = haslo[a] - 'A';
    odwrocone_haslo[a] = ((26 - fir) % 26) + 'A';
  }

  //cout << haslo << " " << odwrocone_haslo << "\n";
  return odwrocone_haslo;
}

int main() {
  string tekst;
  cin >> tekst;

   // for (int x = 0; x < 26; x++) {
  // generuj_dwuznaki();

  for (int i = 0; i < 1/*dwuznaki.size()*/; i++) {
    string odwrocone_haslo = odwroc_haslo();
    cout << odwrocone_haslo << "\n";
    deszyfruj(tekst, odwrocone_haslo);
  }
  // cout << dwuznaki[3] << "\n";
}
