from functools import cmp_to_key

Fre = [0] * 100005

def cmp(a, b):
    if Fre[a] < Fre[b]:
        return 1
    elif Fre[a] > Fre[b]:
        return -1
    else:
        if a < b:
            return -1
        elif a > b:
            return 1
        else:
            return 0

if __name__ == "__main__":
    t = int(input())
    for _ in range(0, t):
        n = int(input())
        a = list(map(int, input().split()))
        for i in a:
            Fre[i] += 1
        a.sort(key=cmp_to_key(cmp))
        for i in a:
            print(i, end=" ")
        print()
        for i in range(len(Fre)):
            Fre[i] = 0
    

