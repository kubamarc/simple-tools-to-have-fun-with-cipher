#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

int litery[1000];
int zastapiona[10000];
char szyfr[10000];
char poprzednia[10000];

void indeks(int dlugosc) {
  for (int l = 1; l < dlugosc; l++) {

    float wynik = 0;
    float dl = 0;
    int literki[30];
    for (int m = 0; m < 30; m++) {
      literki[m] = 0;
    }
    for (int m = 1; m < l; m++) {
      int n = m;
      while (n < dlugosc) {
        literki[szyfr[n] - 'A']++;
        dl += 1.0;
        n += l;
      }
      for (int x = 0; x < 30; x++) {
        wynik += literki[x] * (literki[x] - 1);
      }
      wynik = wynik / (dl * (dl - 1));
    }
    if (wynik > 0.060) {
      printf("%d %f\n", l, wynik);
    }
  }
}

void pokaz_litery(int dlugosc, int l) {
  char lit = ' ';
  while (lit == ' ' || lit == '\n') {
    printf("Wybierz literę do pokaazania\n");
    lit = getchar();
  }
  for (int i = 0; i < dlugosc; i++) {
    if (szyfr[i] != ' ' && szyfr[i] != '\n') {
      if (i % l == 0) {
        printf("\n");
      }
      if (szyfr[i] - 'A' == lit - 'a') {
        printf(GRN "%c", szyfr[i]);
      } else if (zastapiona[i] == 0) {
        printf(RED "%c", szyfr[i]);
      } else {
        printf(BLU "%c", szyfr[i]);
      }
      printf(RESET);
    } else {
      if (i % l == 0) {
        printf("\n");
      }
    }
  }
  printf("\n\n");
}

void wypisz_tekst(int dlugosc, int l) {
  for (int i = 0; i < dlugosc; i++) {
    if (szyfr[i] != ' ' && szyfr[i] != '\n') {
      if (i % l == 0) {
        printf("\n");
      }
      if (zastapiona[i] == 0) {
        printf(RED "%c", szyfr[i]);
      } else {
        printf(BLU "%c", szyfr[i]);
      }
      printf(RESET);
    } else {
      if (i % l == 0) {
        printf("\n");
      }
    }
  }
  printf("\n\n");
}

int main(int argc, char const *argv[]) {
  if (argc < 2) {
    printf("Brak szyfrogramu\n");
    return 0;
  }

  for (int i = 0; i < 30; i++) {
    litery[i] = 0;
    zastapiona[i] = 0;
  }

  FILE *fd = fopen(argv[1], "r");
  int dlugosc = -1;
  char znak = '0';
  while ((znak = getc(fd)) != EOF) {
    dlugosc++;
    szyfr[dlugosc] = znak;
    litery[znak - 'A']++;
  }

  int k = 0;
  int l = dlugosc + 1;
  while (1) {
    if (znak != ' ' && znak != '\n' && znak != 'p') {
      wypisz_tekst(dlugosc, l);
    }

    znak = getchar();

    if (znak == 'l') {
      scanf("%d", &l);
    }

    if (znak == 'i') {
      indeks(dlugosc);
    }

    if (znak == 'p') {
      pokaz_litery(dlugosc, l);
    }

  }

  fclose(fd);


}
