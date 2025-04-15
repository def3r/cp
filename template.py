import sys
from pathlib import Path


def __setup():
    if Path("_input.txt").exists():
        sys.stdin = open("_input.txt", "r")


def main():
    __setup()

    t = int(input())
    for _ in range(t):
        pass


if __name__ == "__main__":
    main()
