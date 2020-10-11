def merge_sort(Ar):
    if(len(Ar)>1):
        mid=len(Ar)//2
        L=Ar[:mid]
        R=Ar[mid:]
        merge_sort(L)
        merge_sort(R)

        i=j=k=0
        while(i<len(L) and j<len(R)):
            if(L[i]<R[j]):
                Ar[k]=L[i]
                i+=1
            else:
                Ar[k]=R[j]
                j+=1
            k+=1

        while(i<len(L)):
            Ar[k]=L[i]
            i+=1
            k+=1
        while(j<len(R)):
            Ar[k]=R[j]
            j+=1
            k+=1

Arr=[4,6,2,3,1,8,0,9,7,5]
merge_sort(Arr)
print(Arr)



