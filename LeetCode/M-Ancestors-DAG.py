import sys
from pathlib import Path


def __setup():
    if Path("_input.txt").exists():
        sys.stdin = open("_input.txt", "r")


def solution(n: int, edges: list[list[int]]) -> list[list[int]]:
    result: list[list[int]] = [[] for _ in range(n)]
    for edge in edges:
        result[edge[1]].append(edge[0])

    visited: list[bool] = [False] * n

    def visit(node: int) -> set[int]:
        visited[node] = True
        res: set[int] = set(result[node])

        for child in result[node]:
            if not visited[child]:
                res = res.union(visit(child))
                continue
            res = res.union(result[child])
        result[node] = list(res)
        return res

    for node in range(n):
        if not visited[node]:
            _ = visit(node)
        result[node].sort()

    return result


def main():
    __setup()

    t = int(input())
    for _ in range(t):
        n = int(input())
        items = int(input())
        edges: list[list[int]] = []
        for _ in range(items):
            pair = list(map(int, input().split()))
            edges.append(pair)
        _ = solution(n, edges)


if __name__ == "__main__":
    main()
