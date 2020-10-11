A=[8,3,5,9,1,4,0,2,7,6]

#Method1:
i=A[0]
S=[i]
for i in range(1,len(A)):
    k=0
    while(k<len(S)):
        if(A[i]<S[k]):
            S.insert(k,A[i])
            break
        k+=1
    else:
        S.append(A[i])
print(S)

#Method2:
for i in range(1,len(A)):
    k=A[i]
    j=i-1
    while j>=0 and k<A[j]:
        A[j+1]=A[j]
        j-=1
    A[j+1]=k

print(A)

#O(n^2)-wrost
#O(n)-best
#Stable


        
    
        