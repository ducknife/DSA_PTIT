adj = [[] for _ in range(0, 1005)]

visited = [False] * 1005

def dfs(u):
    visited[u] = True
    print(u, end=' ')
    for v in adj[u]:
        if not visited[v]: 
            dfs(v)

if __name__ == "__main__":
    t = int(input())
    for i in range(0, t):
        n, m, u = map(int, input().split())
        for j in range(0, m):
            x, y = map(int, input().split())
            adj[x].append(y)
            adj[y].append(x)
        dfs(u)
        for j in range(1, n + 1):
            adj[j].clear() 
            visited[j] = False
        print()
    
     