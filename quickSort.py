def partition(arr,low,high):
    pivot = arr[high]
    j = (low-1)
    for i in range(low,high):
        if arr[i]<=pivot:
            j+=1
            arr[j],arr[i] = arr[i],arr[j]
    arr[j+1],arr[high] = arr[high],arr[j+1]
    return j+1

def quickSort(arr,low,high):
    if low<high:
        pi = partition(arr,low,high)
        print "pi = ", arr[pi]
        quickSort(arr,low,pi-1)
        quickSort(arr,pi+1,high)

arr = [10, 7, 8, 9, 1, 5]
n = len(arr)
quickSort(arr,0,n-1)
print arr
