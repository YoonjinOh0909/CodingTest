def solution(number):
    from itertools import combinations

    results = list(combinations(number, 3))

    return len([x for x in results if sum(x) == 0])