def solution(n, lost, reserve):
    answer = 0
    # lost, reserve sort 진행.
    # pop 해서 현재, 직전, 직후 값을 확인
    # 현재 있으면 넘어감. 사용 list 만들어서 추가
    # 직전 있으면 넘어감. 사용 list 만들어서 추가
    # 직후 있으면 도난 당한 애 중에 있으면 사용 못 함.
        # 못 듣는애 리스트로 작성
    # 결국 현재 직전 직후 모두 없으면 못 듣는애 리스트.
     
    lost = sorted(lost, reverse = True)
    
    no_cloth = list()
    used_reserve = list()
    
    while len(lost) > 0:
        student = lost.pop() # reverse 로 했으니 가장 작은 학생
        # 자기가 더 가져온게 있는지 확인
        if (student in reserve) and (student not in used_reserve): 
            used_reserve.append(student)
            continue
        if ((student-1) in reserve) and ((student-1) not in used_reserve): 
            used_reserve.append(student-1)
            continue
        if ((student+1) in reserve) and ((student+1) not in used_reserve): 
            # 직후 있는 것은 확인.
            # 하지만 직후 학생도 없는가도 확인.
            if (student + 1) not in lost:
                used_reserve.append(student+1)
                continue
        
        # 위에 모두 해당 안되면 이 친구는 수업 못 듣는다.
        no_cloth.append(student)
    answer = n - len(no_cloth)
    return answer