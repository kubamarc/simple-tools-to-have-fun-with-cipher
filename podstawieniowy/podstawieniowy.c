#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

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

void zastap(int dlugosc) {
  printf("wpisz litery\n");
  char zastap0 = ' ', zastap1 = ' ';
  while (zastap0 == ' ' || zastap0 == '\n') {
    printf("Wpisz zastępowaną literę\n");
    zastap0 = getchar();
  }

  while (zastap1 == ' ' || zastap1 == '\n') {
    printf("Wpisz literę zastępczą\n");
    zastap1 = getchar();
  }

  printf("%c %c\n", zastap0, zastap1);
  for (int a = 0; a < dlugosc; a++) {
    if (zastapiona[a] == 0) {
      poprzednia[a] = szyfr[a];
      //printf("%d, %d\n", litery[a] - 'A', zastap0 - 'a');
      if ((szyfr[a] - 'A') == zastap0 - 'a') {
        szyfr[a] = zastap1;
        zastapiona[a] = 1;
      }
    }
  }
}


void pokaz_litery(int dlugosc) {
  char lit = ' ';
  while (lit == ' ' || lit == '\n') {
    printf("Wybierz literę do pokaazania\n");
    lit = getchar();
  }
  for (int i = 0; i < dlugosc; i++) {
    if (szyfr[i] - 'A' == lit - 'a') {
      printf(GRN "%c", szyfr[i]);
    } else if (zastapiona[i] == 0) {
      printf(RED "%c", szyfr[i]);
    } else {
      printf(BLU "%c", szyfr[i]);
    }
    printf(RESET);
  }
  printf("\n\n");
}

void wypisz_tekst(int dlugosc) {
  for (int i = 0; i < dlugosc; i++) {
    if (zastapiona[i] == 0) {
      printf(RED "%c", szyfr[i]);
    } else {
      printf(BLU "%c", szyfr[i]);
    }
    printf(RESET);
  }
  printf("\n\n");
}

void stosunek(int dlugosc, char liczona) {
  while (liczona == ' ' || liczona == '\n') {
    printf("Wpisz literę do sprawdzania frekwencji\n");
    liczona = getchar();
  }


  for (int i = 0; i < 26; i++) {
    litery[i] = 0;
  }

  for (int i = 0; i < dlugosc; i++) {
    int k = szyfr[i] - 'A';
    //printf("zast = %d, miejsce = %d, litera[%c] = %d\n", zastapiona[i], k, szyfr[i], litery[k]);
    // printf ("zast = %d, i = %d, szyfr[i] = %c, %c %d %d\n", zastapiona[i], i, szyfr[i], szyfr[i]-'a', szyfr[i], szyfr[i]-'A');
    if (zastapiona[i] == 0 && k >= 0) {
      litery[k] += 1;
    }
  }

  float licznik = litery[liczona - 'a'];
  float mianownik = dlugosc;
  float wynik = licznik / mianownik;
  printf("litery %c jest %d czyli %f%\n", liczona, litery[liczona-'a'], 100 * wynik);
}

void najczesciej_wystepujace(int dlugosc) {
  for (int i = 0; i < 26; i++) {
    litery[i] = 0;
  }

  for (int i = 0; i < dlugosc; i++) {
    int k = szyfr[i] - 'A';
    //printf("zast = %d, miejsce = %d, litera[%c] = %d\n", zastapiona[i], k, szyfr[i], litery[k]);
    // printf ("zast = %d, i = %d, szyfr[i] = %c, %c %d %d\n", zastapiona[i], i, szyfr[i], szyfr[i]-'a', szyfr[i], szyfr[i]-'A');
    if (zastapiona[i] == 0 && k >= 0) {
      litery[k] += 1;
    }
  }

  int max = 0;
  char litera = '0';
  for (int i = 0; i < 26; i++) {
    if (max < litery[i]) {
      max = litery[i];
      litera = i + 'a';
    }
  }
  printf("Najczęściej występuje litera %c, %d razy\n", litera, max);
  stosunek(dlugosc, litera);

}

void cofnij_zmiane(int dlugosc) {
  char cofana = ' ';
  while(cofana == ' ' || cofana == '\n') {
    printf("Wpisz literę do cofnięcia\n");
    cofana = getchar();
  }

  for (int i = 0; i < dlugosc; i++) {
    if (zastapiona[i] == 1 && szyfr[i] == cofana) {
      szyfr[i] = poprzednia[i];
      zastapiona[i] = 0;
    }
  }
}


void pomoc() {
  char znak;

  printf("Aby zobaczyć najczęściej występującą niezastąpioną literę wpisz .\n");
  printf("Aby zastąpić literę, wpisz \',\' a następnie zastępowaną literę i zastępczą\n");
  printf("Aby zakończyć, wpisz !\n");
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
  }


  fclose(fd);

  int k = 0;
  while (1) {
    if (znak != ' ' && znak != '\n' && znak != 'p') {
      wypisz_tekst(dlugosc);
    }

    znak = getchar();
    if (znak == '?') {
      pomoc();
    }
    if (znak == '!') {
      return 0;
    }
    if (znak == '.') {
      najczesciej_wystepujace(dlugosc);
    }
    if (znak == ',') {
      zastap(dlugosc);
    }
    if (znak == 'b') {
      cofnij_zmiane(dlugosc);
    }
    if (znak == 'p') {
      pokaz_litery(dlugosc);
    }
    if (znak == 'i') {
      stosunek(dlugosc, ' ');
    }
  }
  return 0;
}
