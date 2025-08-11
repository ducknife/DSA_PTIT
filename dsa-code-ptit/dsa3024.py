listJob = []

def solve():
    n = int(input())
    for i in range(0, n):
        job = []
        x, y = map(int, input().split())
        job.append(x)
        job.append(y)
        listJob.append(job)
    
    listJob.sort(key=lambda x : x[1])
    res = 1
    TimeEnd = listJob[0][1]
    for i in range(1, n):
        if TimeEnd <= listJob[i][0]:
            TimeEnd = listJob[i][1]
            res += 1
        else:
            continue
    print(res)
    listJob.clear()

if __name__ == "__main__":
    t = int(input())
    while t > 0:
        solve()
        t -= 1