A=[5,3,2,4,6,8,1,9,7]
Ar=sorted(A)
print(Ar)
n=len(Ar)
print("key= ",end="")
K=int(input())

def indexed_search(Arr,n,K):
    E=[0]*20
    I=[0]*20
    st,en,j,ind=0,0,0,0
    flg=0

    for i in range(0,n,3):
        E[ind]=Arr[i]
        I[ind]=i
        ind+=1
    
    if(K<E[0]):
        print("Not found")
        exit(0)
    else:
        for i in range(1,ind+1):
            if(K<=E[i]):
                st=I[i-1]
                en=I[i]
                flg=1
                break
    if(flg==0):
        st=I[i-1]
        en=n
    for i in range(st,en):
        if(K==Arr[i]):
            j=1
            break
    
    if(j==1):
        print("found at index: ",i)
    else:
        print("not found")

    
    
indexed_search(Ar,n,K)

