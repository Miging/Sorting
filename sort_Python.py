import time
students=[]
with open('numbers.txt', 'r') as f:
    for line in f:
        num,name,address=line.split(' ')
        student=[num,name,address]
        students.append(student)

        

#학번으로 정렬
start_time=time.time()
sorted_students_bynum=sorted(students,key=lambda student:student[0])
end_time=time.time()
elapsesd_time=end_time-start_time
print(f"Python 언어의 학번 정렬 : {elapsesd_time:.3f}초")

#이름으로 정렬
start_time=time.time()
sorted_students_byname=sorted(students,key=lambda students:students[1])
end_time=time.time()
elapsesd_time=end_time-start_time
print(f"Python 언어의 이름 정렬 : {elapsesd_time:.3f}초")
