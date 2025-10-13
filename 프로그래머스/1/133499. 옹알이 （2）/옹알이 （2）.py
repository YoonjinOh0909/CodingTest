def solution(babbling):
    baby = ["aya", "ye", "woo", "ma"]
    answer = 0
    for a in babbling:
        keepgoing = True
        beforeVal = ""
        i = 0
        while keepgoing:
            if i == len(a):
                # print("2")
                answer += 1
                break
            if len(a) - i < 2 :
                # print(f"i {i} a[i:] {a[i:]}")
                break

            keepgoing = False
            for wordcnt in [2,3]:
                if a[i:i+wordcnt] in baby:
                    if beforeVal == a[i:i+wordcnt]: # 직전 값과 지금 값이 같으면 답이 될 수 x
                        break
                    else : # 직전 값과 다르다면:
                        keepgoing = True
                        beforeVal = a[i:i+wordcnt]
                    i += wordcnt # 현재 index 최신화
                    break
    return answer