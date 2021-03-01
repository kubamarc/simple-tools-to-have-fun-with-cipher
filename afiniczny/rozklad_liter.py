#!/usr/bin/python3



def main():
    tekst = input()
    print()
    x = 0
    ile_liter = {}
    # for i in range(len(tekst)):
    for c in tekst:
        x += 1
        ile_liter[c] = ile_liter.get(c, 0) + 1

    for c, v in sorted(ile_liter.items(), key = lambda x: x[1]):
        # print(c, ile_liter[c], (ile_liter[c] / x) * 100, "%")
        print(c, v, (v / x) * 100, "%")

if __name__ == '__main__':
    main()
