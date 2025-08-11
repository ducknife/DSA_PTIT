
freq = [0] * (10**6 + 1)


if __name__ == "__main__":
    t = int(input())
    for _ in range(0, t):
        n = int(input())
        a = list(map(int, input().split()))
        for i in a:
            freq[i] += 1
        a.sort(key=lambda x : -freq[x])
        if freq[a[0]] > n // 2:
            print(a[0])
        else:
            print("NO")
        for i in range(0, 10**6):
            freq[i] = 0
