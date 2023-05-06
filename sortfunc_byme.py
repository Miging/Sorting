def selection_sort(n):
    nl=len(n)
    for i in range(nl-1):
        least=i
        for j in range(i+1,nl):
            if n[j]<n[least]:
                least=j
        n[i],n[least]=n[least],n[i]