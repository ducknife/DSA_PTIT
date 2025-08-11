
listJob  = []


if __name__ == "__main__":
    t = int(input())
    for i in range(0, t):
        n = int(input())
        for i in range(0, n):
            x, y, w = map(int, input().split())
            listJob.append([x, y, w])

        listJob.sort(key=lambda x : x[2], reverse=True)

        q, p = 0, 0
        used = [False] * 1005

        for i in range(0, n):
            for j in range(listJob[i][1] - 1, -1, -1):
                if used[j] == False:
                    used[j] = True
                    p += listJob[i][2]
                    q += 1
                    break
        print(q, p)
        listJob.clear()
