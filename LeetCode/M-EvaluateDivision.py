import sys
from pathlib import Path


def __setup():
    if Path("_input.txt").exists():
        sys.stdin = open("_input.txt", "r")


def calcEquation(
    equations: list[list[str]], values: list[float], queries: list[list[str]]
) -> list[float]:
    INF: float = float("inf")
    vars: set[str] = set(var for items in equations for var in items)
    lvars: list[str] = list(vars)
    results: list[float] = []
    dist: dict[str, dict[str, float]] = {}

    for i in lvars:
        dist[i] = {}
        for j in lvars:
            dist[i][j] = 1 if i == j else INF

    for index, equation in enumerate(equations):
        dist[equation[0]][equation[1]] = values[index]
        dist[equation[1]][equation[0]] = 1 / values[index]

    # Floyd Warshall
    for k in lvars:
        for i in lvars:
            for j in lvars:
                if i != j and dist[i][k] != INF and dist[k][j] != INF:
                    dist[i][j] = min(dist[i][j], dist[i][k] * dist[k][j])

    for query in queries:
        if (
            query[0] not in vars
            or query[1] not in vars
            or dist[query[0]][query[1]] == INF
        ):
            results.append(-1)
            continue
        results.append(dist[query[0]][query[1]])

    return results


def main():
    __setup()

    t = int(input())
    for _ in range(t):
        pass

    equations: list[list[str]] = [
        ["b", "a"],
        ["c", "b"],
        ["d", "c"],
        ["e", "d"],
        ["f", "e"],
        ["g", "f"],
        ["h", "g"],
        ["i", "h"],
        ["j", "i"],
        ["k", "j"],
        ["k", "l"],
        ["l", "m"],
        ["m", "n"],
        ["n", "o"],
        ["o", "p"],
        ["p", "q"],
        ["q", "r"],
        ["r", "s"],
        ["s", "t"],
        ["t", "u"],
    ]
    values: list[float] = [
        1e-05,
        1e-05,
        1e-05,
        1e-05,
        1e-05,
        1e-05,
        1e-05,
        1e-05,
        1e-05,
        1e-05,
        1e-05,
        1e-05,
        1e-05,
        1e-05,
        1e-05,
        1e-05,
        1e-05,
        1e-05,
        1e-05,
        1e-05,
    ]
    queries: list[list[str]] = [["a", "u"]]
    _ = calcEquation(equations, values, queries)


if __name__ == "__main__":
    main()
