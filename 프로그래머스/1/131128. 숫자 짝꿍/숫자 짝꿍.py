def solution(x, y):
    from itertools import groupby

    x_gb = groupby(''.join(sorted(list(x))))
    y_gb = groupby(''.join(sorted(list(y))))

    x_dict = dict()
    y_dict = dict()

    for val, cnt in x_gb:
        x_dict[val] = len(list(cnt))

    for val, cnt in y_gb:
        y_dict[val] = len(list(cnt))

    ans_list = []

    for v in x_dict.keys():
        if v in y_dict.keys():
            ans_list.extend([v] * min(x_dict[v], y_dict[v]))

    answer = ''.join(sorted(ans_list,reverse=True ))
    if len(ans_list) == 0:
        answer = "-1"
    elif (answer[0] == '0' and answer[-1] == '0'):
        answer = "0"

    return answer