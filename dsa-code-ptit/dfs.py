
visited = [False] * 1005
adj = [[] for i in range(0, 1005)]
par = [0] * 1005

def dfs(u):
    visited[u] = True
    for v in adj[u]:
        if visited[v] == False:
            par[v] = u
            dfs(v)
            
            
if __name__ == '__main__':
    n, u, v = map(int, input().split())
    a = [[] for i in range(0, n)]
    for i in range(0, n):
        a[i] = list(map(int, input().split()))
    dfs(u)
    if visited[v] == False:
        print(0)
    else:
        path = []
        while v != par[u]:
            path.append(v)
            v = par[v]
        path.append(u)
        while len(path) > 0:
            path.pop()
        