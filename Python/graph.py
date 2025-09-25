from collections import deque, defaultdict
from abc import ABC, abstractmethod

class SearchStrategy(ABC):
    def __init__(self, adj_list):
        self.adj_list = adj_list
        self.visited = [False] * len(self.adj_list)
        self.parent = defaultdict(int)

    @abstractmethod
    def search(self, start, goal):
        pass

class DFS(SearchStrategy):
    def __init__(self, adj_list):
        super().__init__(adj_list)

    def search(self, start, goal):
        stack = deque()
        stack.append(start)
        self.visited[start] = True
        self.parent[start] = -1

        while stack:
            current = stack[-1]
            if current == goal:
                break
            for x in adj_list[current]:
                if not self.visited[x]:
                    stack.append(x)
                    self.visited[x] = True
                    self.parent[x] = current
                    break
            if current == stack[-1]:
                stack.pop()
        path = deque()
        while self.parent[goal] > -1:
            path.append(goal)
            goal = self.parent[goal]
        yield start
        while path:
            yield path.pop()


class BFS(SearchStrategy):
    def __init__(self, adj_list):
        super().__init__(adj_list)

    def search(self, start, goal):
        queue = deque()
        queue.append(start)
        self.visited[start] = True
        self.parent[start] = -1

        while queue:
            current = queue.popleft()
            if current == goal:
                break
            for x in self.adj_list[current]:
                if not self.visited[x]:
                    queue.append(x)
                    self.visited[x] = True
                    self.parent[x] = current
        path = deque()
        while self.parent[goal] != -1:
            path.append(goal)
            goal = self.parent[goal]
        yield start
        while path:
            yield path.pop()



if __name__ == '__main__':
    adj_list = [
        [1, 2],  # 0 kề với 1, 2
        [0, 3, 4],  # 1 kề với 0, 3, 4
        [0, 5, 6],  # 2 kề với 0, 5, 6
        [1, 7],  # 3 kề với 1, 7
        [1, 7],  # 4 kề với 1, 7
        [2, 8],  # 5 kề với 2, 8
        [2, 8],  # 6 kề với 2, 8
        [3, 4, 9],  # 7 kề với 3, 4, 9
        [5, 6, 9],  # 8 kề với 5, 6, 9
        [7, 8]  # 9 kề với 7, 8
    ]

    search = BFS(adj_list)
    for value in search.search(1, 9):
        print(value, end=' ')
    print(' ')

    search = DFS(adj_list)
    for value in search.search(1, 9):
        print(value, end=' ')





