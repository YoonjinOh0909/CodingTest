def solution(n, stages):
    from collections import Counter
    stages = sorted(stages)
    stage_cnt = Counter(stages)
    sorted_stage = sorted(stage_cnt.items(), key=lambda pair:pair[0])

    total_cnt = len(stages)
    until_now_cnt = 0
    grade_dict = dict()

    for stage, cnt in sorted_stage:
        grade_dict[stage] = cnt / (total_cnt - until_now_cnt)
        until_now_cnt += cnt
    sorted_by_grade = [ k for k,v in sorted(grade_dict.items(), key= lambda x : (-x[1], x[0])) if k <= n]

    stage_all_list = set([x+1 for x in range(n)])
    sorted_by_grade.extend(sorted(list(stage_all_list - set(sorted_by_grade))))
    
    return sorted_by_grade