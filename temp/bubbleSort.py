def bubleSort(arr):

    for i in range(len(arr)):
        for j in range(0, len(arr) - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j + 1], arr[j] = arr[j], arr[j + 1]


arr = [4, 5, 2, 1]
bubleSort(arr)
print(arr)
