def solution(ingredient):
    answer = 0
    cur = list()
    correct_set = [1,2,3,1]
    answer = 0
    for val in ingredient:
        cur.append(val)
        if len(cur) < 4: # 4보다 작으면 어차피 만들 수 없음
            continue
        if val == 1: # 빵이라면
            is_set = True
            for idx, cur_ing in enumerate(cur[-4:]):
                # print(idx, cur_ing)
                if cur_ing != correct_set[idx]:
                    is_set = False
            if is_set == True:
                del cur[-4:]
                answer = answer + 1
    return answer