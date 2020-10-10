Arr=[10,23,45,67,89,24,68,59,39,36,20]
n=len(Arr)
K=int(input())
def SL(Arr,n,K):
    L,Arr[n-1]=Arr[n-1],K
    i=0
    while(Arr[i]!=K):
        i+=1
    Arr[n-1]=L
    if(i<n-1) or (Arr[i]==K):
        return i
    else:
        return False

I=SL(Arr,n,K)
if(I):
    print("Position=",I)
else:
    print("Not found")

#O(n)
#N+2 comparisons