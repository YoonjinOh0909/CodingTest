def solution(participant, completion):
    # 먼저 set으로 계산을 해본다.
    set_list = list(set(participant)-set(completion))
    if len(set_list) > 0 :
        return set_list[0]
    
    # 근데 만약 동명이인이 있다면
    from collections import Counter
    p = Counter(participant)
    c = Counter(completion)
    
    for name in p:
        if p[name] != c[name]: # 숫자가 다르다면
            return name
    