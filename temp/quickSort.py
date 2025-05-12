def partition(arr, l, r, pivot):
    while l <= r:
        while arr[l] < pivot:
            l += 1
        while arr[r] > pivot:
            r -= 1

        if l <= r:
            arr[l], arr[r] = arr[r], arr[l]
            l += 1
            r -= 1
    return l


def quickSort(arr, l, r):
    if l >= r:
        return

    mid = (l + r) // 2
    pivot = arr[mid]

    i = partition(arr, l, r, pivot)

    quickSort(arr, l, i - 1)
    quickSort(arr, i, r)


arr = [4, 5, 2, 1]

quickSort(arr, 0, len(arr) - 1)

print(arr)
