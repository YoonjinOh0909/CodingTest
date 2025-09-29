def solution(number, limit, power):
    answer = 0
    all_divisions = [[] for _ in range(number)] # 각 개수만큼으로 약수를 넣을 수 있는 list를 만든다.

    for i in range(1, number+1): # 1 ~ number까지
        for j in range(i, number+1, i): # i부터 i씩 커지는 애들은 i를 약수로 가질 것이다.
            all_divisions[j-1].append(i)

    # n = 1 일 때 N / 1
    # n = 2 일 때 N -1 / 2
    # n = 3 일 때 N -2 / 3
    # n = n 일 때 N - (N-1) / n

    # 따라서 N * (1 + 1/2 + 1/3 + ... + 1/n)이 된다.
    # 뒤 수식은 조화 급수로 logN이 된다. 

    sum_val = [len(i) for i in all_divisions]
    answer = [j if j <= limit else power for j in sum_val]

    return sum(answer)