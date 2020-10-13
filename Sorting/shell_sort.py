def shell_sort(arr,n):
    gap=n//2
    while gap>0:
        for i in range(gap,n):
            temp=arr[i]
            j=i
            while(j>=gap and temp<arr[j-gap]):
                arr[j]=arr[j-gap]
                j-=gap
            arr[j]=temp
        gap=gap//2
        
arr=[20,30,10,40,60,50,80,90,70]
len=len(arr)
shell_sort(arr,len)
print(arr)

            


