def solution(survey, choices):
    tp = ['R', 'T', 'C', 'F', 'J', 'M', 'A', 'N']
    tp_dict = dict()

    for t in tp:
        tp_dict[t] = 0

    for idx in range(len(survey)):
        val = choices[idx] -4
        if val != 0:
            if val < 0 :
                dict_index = survey[idx][0]
            elif val > 0 :
                dict_index = survey[idx][1]
            tp_dict[dict_index] += abs(val)

    answer = ""
    for idx in range(0,8,2):
        if tp_dict[tp[idx]] >= tp_dict[tp[idx+1]] :
            answer += tp[idx]
        else:
            answer += tp[idx+1]
    return answer