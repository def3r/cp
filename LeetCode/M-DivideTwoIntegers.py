import sys
from pathlib import Path

def __setup():
    if Path("_input.txt").exists():
        sys.stdin = open("_input.txt", "r")

def getSignBit(n: int) -> int:
    return ((n & (1 << n.bit_length())) >> n.bit_length())

def divide(dividend: int, divisor: int) -> int:
    q: int = 0
    sign: int = getSignBit(dividend) ^ getSignBit(divisor)
    dividend = abs(dividend)
    divisor = abs(divisor)
    dividendLen: int = dividend.bit_length()

    n: int = 0
    while dividendLen != 0 or n >= divisor:
        q = q << 1
        n = (n << 1) + ((dividend & (1 << dividendLen - 1)) >> (dividendLen - 1))
        dividendLen -= 1
        if not (n < divisor):
            n -= divisor
            q += 1
    if sign:
        q = -q
    if q > 2 ** 31 - 1:
        return 2 ** 31 - 1
    return q

def main():
    __setup()

    t = int(input())
    for _ in range(t):
        pass
    print(divide(-2**31, -1))


if __name__ == "__main__":
    main()
