#!/usr/bin/python3

def main():
    tekst = input()
    print()
    x = 0;
    for i in range(len(tekst)):
        if x == 6:
            print()
            x = 0
        x += 1
        print(tekst[i], end = "")

if __name__ == '__main__':
    main()
