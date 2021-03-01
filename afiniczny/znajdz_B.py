#!/usr/bin/python3

def b(a):
    l = 'E'
    e = n(l)
    c = 2
    x = (c - (e * a)) % 26
    return x


def n(x):
    return ord(x) - ord('A')

def inv(x):
    for a in range(1, 26):
        if (a * x) % 26 == 1:
            return a
    return None

def F(x, A, B):
    # return chr(((A * n(x) + B) % 26) + ord('A'))
    A_inv = inv(A)
    if A_inv is not None:
        return chr((((n(x) - B) * inv(A)) % 26) + ord('A'))
    return "!"

def subst_all(a, b):
    text = "KQEREJEBCPPCJCRKIEACUZBKRVPKRBCIBQCARBJCVFCUPKRIOFKPACUZQEPBKRXPEIIEABDKPBCPFCDCCAFIEABDKPBCPFEQPKAZBKRHAIBKAPCCIBURCCDKDCCJCIDFUIXPAFFERBICZDFKABICBBENEFCUPJCVKABPCYDCCDPKBCOCPERKIVKSCPICBRKIJPKABI"
    # text = "IHHWVCSWFRCP"
    return ''.join([F(c, a, b) for c in text])


def main():
    for a in range(1, 26):
        print(a, b(a))
        B = b(a)
        print(subst_all(a, B))


if __name__ == '__main__':
    main()
