def quicksort(arr, left, right):
    if left < right:
        partpos = partition(arr, left, right)
        quicksort(arr, left, partpos - 1)
        quicksort(arr, partpos + 1, right)


def partition(arr, left, right):
    i = left
    j = right - 1
    pivot = arr[right]
    while i < j:
        while i < right and arr[i] < pivot:
            i += 1
        while j > left and arr[j] >= pivot:
            j -= 1
        if i < j:
            arr[i], arr[j] = arr[j], arr[i]
    if arr[i] > pivot:
        arr[i], arr[right] = arr[right], arr[i]
    return i

test = [22, 11, 55, 88, 44, 66, 33, 77, 99]
quicksort(test, 0, len(test) - 1)
print(test)
