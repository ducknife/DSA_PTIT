
listJob = []

if __name__ == "__main__":
    t = int(input())
    for i in range(0, t):
        n = int(input())
        a, b = list(map(int, input().split())), list(map(int, input().split()))
        for i in range (0, n):
            listJob.append([a[i], b[i]]);
        listJob.sort(key=lambda x : x[1])
        res = 1
        TimeFinished = listJob[0][1]
        for i in range(1, n):
            if listJob[i][0] >= TimeFinished:
                TimeFinished = listJob[i][1]
                res += 1
            else:
                continue
        print(res)
        listJob.clear()