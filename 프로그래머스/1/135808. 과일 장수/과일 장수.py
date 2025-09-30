def solution(k, m, score):
    answer = 0
    score_sort = sorted(score)
    for i in range(len(score)-m, -1, -1 * m):
        answer = answer +score_sort[i] * m

        
    return answer