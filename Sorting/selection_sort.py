def selection(array,size):
    for i in range(size):
        min=i
        
        for j in range(i+1,size):
            if(array[min]>array[j]):
                min=j
        (array[min],array[i])=(array[i],array[min])
        
    return array

arr=[14,7,54,34,45,67,12,30,60,97,2]
n=len(arr)
A=selection(arr,n)
print(A)
#O(n*n):wrost
#Unstable