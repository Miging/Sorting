import time
import copy
#파일을 읽어서 리스트에 저장
students=[]
with open('numbers.txt', 'r') as f:
    for line in f:
        num,name,address=line.split(' ')
        student=[num,name,address]
        students.append(student)

#함수 실행시간 측정함수
def time_check(func,fName,students):
    start_time=time.time()
    func(students)
    end_time=time.time()
    elapsesd_time=end_time-start_time
    print(f"{fName} : {elapsesd_time:.3f}초")

#num으로 선택정렬
def selection_sort_num(students):
    for i in range(len(students)):
        min_idx=i
        for j in range(i+1,len(students)):
            #만약 min_idx의 학번보다 j의 학번이 작으면 min_idx를 j로 바꿔준다.
            if students[min_idx][0]>students[j][0]:
                min_idx=j
        #min_idx와 i를 바꿔준다.
        students[i],students[min_idx]=students[min_idx],students[i]

#name으로 선택정렬
def selection_sort_name(students):
    for i in range(len(students)):
        min_idx=i
        for j in range(i+1,len(students)):
            #만약 min_idx의 학번보다 j의 학번이 작으면 min_idx를 j로 바꿔준다.
            if students[min_idx][1]>students[j][1]:
                min_idx=j
        #min_idx와 i를 바꿔준다.
        students[i],students[min_idx]=students[min_idx],students[i]

#num으로 퀵정렬
def quick_sort_num(students):
    if len(students) <= 1:
        return students
    stack = []
    stack.append((students, 0, len(students) - 1))

    while stack:
        arr, low, high = stack.pop()
        pivot_index = partition_num(arr, low, high)
        if pivot_index - 1 > low:
            stack.append((arr, low, pivot_index - 1))
        if pivot_index + 1 < high:
            stack.append((arr, pivot_index + 1, high))
    return students

def partition_num(arr, low, high):
    pivot = arr[low][0]
    i = low + 1
    j = high

    while True:
        while i <= j and arr[i][0] <= pivot:
            i += 1
        while i <= j and arr[j][0] > pivot:
            j -= 1
        if i <= j:
            arr[i], arr[j] = arr[j], arr[i]
        else:
            break
    arr[low], arr[j] = arr[j], arr[low]
    return j

#name으로 퀵정렬
def quick_sort_name(students):
    if len(students) <= 1:
        return students
    stack = []
    stack.append((students, 0, len(students) - 1))

    while stack:
        arr, low, high = stack.pop()
        pivot_index = partition_name(arr, low, high)
        if pivot_index - 1 > low:
            stack.append((arr, low, pivot_index - 1))
        if pivot_index + 1 < high:
            stack.append((arr, pivot_index + 1, high))
    return students
def partition_name(arr, low, high):
    pivot = arr[low][1]
    i = low + 1
    j = high

    while True:
        while i <= j and arr[i][1] <= pivot:
            i += 1
        while i <= j and arr[j][1] > pivot:
            j -= 1
        if i <= j:
            arr[i], arr[j] = arr[j], arr[i]
        else:
            break
    arr[low], arr[j] = arr[j], arr[low]
    return j


#num으로 힙정렬
def adjust_num(students,i,size):
    while 2*i<=size:
        k=2*i
        if k<size and students[k][0]<students[k+1][0]:
            k+=1
        if students[i][0]>students[k][0]:
            break
        students[i],students[k]=students[k],students[i]
        i=k

def heap_sort_num(students):
    hsize = len(students) - 1
    for i in reversed(range(1, hsize // 2 + 1)):
        adjust_num(students, i, hsize)
    for i in range(hsize, 1, -1):
        students[1], students[i] = students[i], students[1]
        adjust_num(students, 1, i - 1)
    del students[0]
#name으로 힙정렬
def adjust_name(students,i,size):
    while 2*i<=size:
        k=2*i
        if k<size and students[k][1]<students[k+1][1]:
            k+=1
        if students[i][1]>students[k][1]:
            break
        students[i],students[k]=students[k],students[i]
        i=k
def heap_sort_name(students):
    hsize=len(students)-1
    for i in reversed(range(1,hsize//2+1)):
        adjust_name(students,i,hsize)
    for i in range(hsize):
        students[1],students[hsize]=students[hsize],students[1]
        adjust_name(students,1,hsize-1)
        hsize-=1
    del students[0]

students1=copy.deepcopy(students)
students2=copy.deepcopy(students)
students3=copy.deepcopy(students)
students4=copy.deepcopy(students)
students4.insert(0,["a","",""])
students5=copy.deepcopy(students)
students5.insert(0,["","a",""])

#잘 정렬되었는지 확인하는 함수
def check(students,what):
    for i in range(len(students)-1):
        if students[i][what]>students[i+1][what]:
            return print("잘 정렬되지 않았습니다")
    return print("잘 정렬되었습니다.")


time_check(selection_sort_num,"선택 정렬로 학번 :",students)
check(students,0)
time_check(selection_sort_name,"선택 정렬로 이름 :",students1)
check(students1,1)
time_check(quick_sort_num,"퀵 정렬로 학번 :",students2)
check(students2,0)
time_check(quick_sort_name,"퀵 정렬로 이름 :",students3)
check(students3,1)
time_check(heap_sort_num,"힙 정렬로 학번 :",students4)
check(students4,0)
time_check(heap_sort_name,"힙 정렬로 이름 :",students5)
check(students5,1)