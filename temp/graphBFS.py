from collections import deque

N = 0
visited = []
distance = []


def showGraph(graph):
    for i in graph:
        for j in i:
            print(j, end=" ")
        print()


def inputGraph():
    global N, visited, distance

    N, e = map(int, input().split())
    N += 1

    # graph = [[0] * (N+1) for _ in range(N+1)]
    graph = [[] for _ in range(N)]
    visited = [False] * N
    distance = [0] * N

    for _ in range(e):
        a, b = map(int, input().split())

        # graph[a][b] = 1
        # graph[b][a] = 1

        graph[a].append(b)

    return graph


def bfs(start, graph):
    global visited, distance
    queue = deque()
    queue.append(start)
    visited[start] = True

    while queue:
        parent = queue.popleft()

        for child in graph[parent]:
            if visited[child]:
                return
            queue.append(child)
            visited[child] = True
            distance[child] = distance[parent] + 1


graph = inputGraph()
bfs(1, graph)

for i in distance:
    print(i)
