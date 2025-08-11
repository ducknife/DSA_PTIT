from functools import cmp_to_key

x = -1

def absx(a):
    return abs(x - a)

def cmp(a, b):
    if absx(a) < absx(b):
        return -1
    elif absx(a) > absx(b):
        return 1
    else:
        return 0

if __name__ == "__main__":
    t = int(input())
    for i in range(0, t):
        n, x = map(int, input().split())
        a = list(map(int, input().split()))
        a.sort(key=cmp_to_key(cmp))
        for i in a:
            print(i, end=" ")
        print()