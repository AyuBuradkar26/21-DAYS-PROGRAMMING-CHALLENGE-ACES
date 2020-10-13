def heapify(arr,h,i):
    M=i
    l=2*i+1
    r=2*i+2

    if(l<h and arr[l]>arr[i]):
        M=l
    if(r<h and arr[r]>arr[M]):
        M=r

    if M!=i:
        arr[i],arr[M]=arr[M],arr[i]
        heapify(arr,h,M)

def heap_sort(arr,n):
    for i in range(n//2-1,-1,-1):
        heapify(arr,n,i)

    for i in range(n-1,0,-1):
        arr[i],arr[0]=arr[0],arr[i]
        heapify(arr,i,0)

arr=[2,1,4,5,3,7,6,9]
n=len(arr)
heap_sort(arr,n)
print(arr)

