def bubble(array,size):
    for i in range(size):
        swapped=False
        for j in range(size-i-1):
            if(array[j]>array[j+1]):
                (array[j],array[j+1])=(array[j+1],array[j])
                swapped=True
        if(swapped==False):
            break
    return array

arr=[14,7,54,34,45,67,12,30,60,97,2]
n=len(arr)
A=bubble(arr,n)
print(A)
#O(n*n):wrost , comparisons: n*(n-1)/2
#O(n):best
#Stable