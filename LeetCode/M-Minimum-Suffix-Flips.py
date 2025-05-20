import sys
from pathlib import Path


def __setup():
    if Path("_input.txt").exists():
        sys.stdin = open("_input.txt", "r")


def main():
    __setup()

    t: str = input()
    current: str = "0"
    flips: int = 0

    for c in t:
        if c != current:
            flips += 1
            current = c
    print(flips)

if __name__ == "__main__":
    main()
