import sys
from pathlib import Path


def __setup():
    if Path("_input.txt").exists():
        sys.stdin = open("_input.txt", "r")

def addBinary(a:str, b: str) -> str:
    c = 0;
    res: str = ""
    lenA, lenB = len(a), len(b)
    m: int = max(lenA, lenB)

    while m > 0:
        digitA, digitB = 0, 0
        if lenA != 0:
            digitA = int(a[lenA - 1])
            lenA -= 1
        if lenB != 0:
            digitB = int(b[lenB - 1])
            lenB -= 1
        add: int = digitA + digitB + c

        if add <= 1:
            c = 0
            res = str(add) + res
        elif add >= 2:
            c = 1
            res = str(add - 2) + res
        m -= 1

    if c == 1:
        res = '1' + res

    return res


def main():
    __setup()

    t = int(input())
    for _ in range(t):
        pass
    print(addBinary("11", "1"))


if __name__ == "__main__":
    main()
