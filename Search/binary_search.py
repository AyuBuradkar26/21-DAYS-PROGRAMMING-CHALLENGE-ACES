A=[10,34,56,78,24,58,37,48,40,50,60,90]
Arr=sorted(A)
print(Arr)
l=len(Arr)
key=int(input())
def BS(Arr,s,e,key):
    if(s<=e):
        mid=s+(e-s)//2
        if(Arr[mid]==key):
            return mid
        else:
            if(Arr[mid]>key):
                return BS(Arr,s,mid-1,key)
            else:
                return BS(Arr,mid+1,e,key)
    else:
        return -1

result=BS(Arr,0,l-1,key)


if(result==-1):
    print("not found")
else:
    print("found at index: %d" %result)

            
#O(log{2}n)
# better than linear
#use for sorted arrays