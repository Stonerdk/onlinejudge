#-*- coding:utf-8 -*-
u = []
u.append([1,2,3,4,5])
u.append([2,3,4,5,1])
u.append([3,4,5,1,2])
u.append([4,5,1,2,3])
u.append([5,1,2,3,4])
u.append([4,3,1,2,5])
u.append([3,5,2,1,4])
u.append([2,1,4,5,3])

p = []
p.append(['김관호', '김대호', '최예지', '김나현', '원지윤'])
p.append(['송동기', '박재완', '제태호', '남수헌', '심채현'])
p.append(['한승목', '이종민', '윤장원', '이혜구', '심민섭'])
p.append(['정혜인', '이승아', '윤명지', '기민정', '이정우'])
p.append(['김채현', '박중우', '서동희', '황주원', '고태영'])

for i, t in enumerate(p):
    print('##')
    for s in u:
        l = list(map(lambda x : t[x-1], s))
        print('->'.join(l))



