def quick_sort(Arr,S,E):
    if(S<E):
            pi=partition(Arr,S,E)
            quick_sort(Arr,S,pi-1)
            quick_sort(Arr,pi+1,E)

def partition(Arr,S,E):

    p=Arr[E]
    i=S-1
    for j in range(S,E,1):
        if(Arr[j]<p):
            i+=1
            Arr[i],Arr[j]=Arr[j],Arr[i]
    Arr[i+1],Arr[E]=Arr[E],Arr[i+1]
    return i+1    

arr=[10,80,30,90,40,50,70]
L=len(arr)
quick_sort(arr,0,L-1)
print(arr)
