def solution(food):
    
    order = list()
    for idx, val in enumerate(food):
        print(idx , val, val//2)
        order.append(str(idx) * (val//2))
    


    return ''.join(order)+'0'+''.join(reversed(order))