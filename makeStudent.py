import random
import string

#2만개 뽑고 2500으로 나눔,0~2499 16년
years=random.sample(range(20000),20000)

number=[]
for i in range(8):
    number.append(random.sample((range(10000)),2500))
studentnum=[]

for i in years:
    year=i//2500
    studentnum.append((year+2016)*10000+number[year].pop())

#중복확인
def check_duplication(list):
    if len(list)==len(set(list)):
        return False
    else:
        return True
    
if(check_duplication(studentnum)): print("값이 중복되었습니다.")
else: print("중복되지 않았습니다.")





def generate_string(length):
    upper=string.ascii_uppercase
    name=''.join(random.choice(upper)for _ in range(length))
    return name

lines=[]
for i in range(20000):
    name=generate_string(8)
    address=generate_string(100)
    lines.append(str(studentnum[i])+' '+name+' '+address)



with open('numbers.txt', 'w') as f:
    for line in lines:
        f.write(line + '\n')

