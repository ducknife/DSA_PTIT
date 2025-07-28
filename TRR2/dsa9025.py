t = int(input())
listAdj = [[] for i in range(0, 1005)]
parent = [0] * 1005
visited = [False] * 1005
path = []

def dfs(u):
    visited[u] = True
    for v in listAdj[u]:
        if visited[v] == False:
            parent[v] = u
            dfs(v)


for i in range(0, t):
    path.clear()
    for i in range(0, 1005):
        visited[i] = False
        parent[i] = 0
        listAdj[i].clear()
    n, m, u, v = map(int, input().split())
    a = list(map(int, input().split()))
    for i in range(0, len(a) - 1):
        if i % 2 == 0:
            listAdj[a[i]].append(a[i + 1])
    dfs(u)
    if visited[v] == False: print(-1)
    else:
        while v != u:
            path.append(v)
            v = parent[v]
        path.append(u)
        while len(path) >= 1:
            print(path[len(path) - 1], end=" ")
            path.pop()
        print()
    