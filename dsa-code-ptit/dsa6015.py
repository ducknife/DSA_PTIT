def merge(a, left, mid, right):
    LList = a[left:mid+1]
    RList = a[mid+1:right+1]
    i, j, k = 0, 0, left
    while i < len(LList) and j < len(RList):
        if LList[i] <= RList[j]:
            a[k] = LList[i]
            k += 1
            i += 1
        else:
            a[k] = RList[j]
            j += 1
            k += 1
    while i < len(LList):
        a[k] = LList[i]
        k += 1
        i += 1
    while j < len(RList):
        a[k] = RList[j]
        k += 1
        j += 1

def merge_sort(a, left, right):
    if (left >= right): 
        return
    mid = (left + right) // 2
    merge_sort(a, left, mid)
    merge_sort(a, mid + 1, right)
    merge(a, left, mid, right)

if __name__ == "__main__":
    t = int(input())
    for i in range(0, t):
        n = int(input())
        a = list(map(int, input().split()))
        merge_sort(a, 0, n - 1)
        for i in a:
            print(i, end=' ')
        print()
