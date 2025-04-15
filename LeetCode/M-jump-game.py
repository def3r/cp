import sys
from pathlib import Path


def __setup():
    if Path("_input.txt").exists():
        sys.stdin = open("_input.txt", "r")


def canJump(nums: list[int]) -> bool:
    if len(nums) == 1:
        return True
    if not 0 in nums:
        return True

    maxIndex: int = 0
    for index, num in enumerate(nums):
        if num == 0 and maxIndex <= index:
            if index == len(nums) - 1:
                return True
            return False
        maxIndex = max(maxIndex, index + num)

    return True


def main():
    __setup()

    t = int(input())
    for _ in range(t):
        items = list(map(int, input().split()))
        print(canJump(items))
        pass


if __name__ == "__main__":
    main()
