def solution(targets):
    targets.sort(key= lambda x : x[1], reverse= True)
    index = 0
    ans = 0
    while index < len(targets):
        start_i = targets[index][0]
        end_i = targets[index][1]
        next_i = 1
        while( index + next_i) < len(targets) :
            n_s = targets[index + next_i][0]
            n_e = targets[index + next_i][1]
            if n_e <= end_i and n_e > start_i: # 다음 폭격의 끝이 지금 폭격의 시작 초과 지금 폭격의 끝 이하라면 한번에 요격 가능.
                start_i = max(start_i, n_s)
                next_i += 1
            else : # 만약 조건에 해당하지 않는다면 한 번에 요격 불가능.
                break 
        ans += 1 # 현재까지 한 번에 요격할 수 있다
        index += next_i # 다음으로 넘어가야 한다.

    return ans