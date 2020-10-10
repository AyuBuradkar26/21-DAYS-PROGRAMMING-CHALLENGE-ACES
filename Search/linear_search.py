
Arr=[10,20,40,30,50,60,80]
Key=int(input())

Found=False
i=0

while(i<len(Arr)):
    if(Arr[i]==Key):
        Found=True
        break
    else:
        i+=1 
if(Found==True):
    print("Position: ",i)
else:
    print("not found")


#O(n)
#2N+1 comparisons

      