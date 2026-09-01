class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        from collections import deque, defaultdict

        graph = defaultdict(list)
        in_degree = [0] * numCourses

        for course, pre in prerequisites:
            graph[pre].append(course)
            in_degree[course] += 1

        queue = deque([i for i in range(numCourses) if in_degree[i] == 0])
        processed = 0

        while queue:
            course = queue.popleft()
            processed += 1
            for next_course in graph[course]:
                in_degree[next_course] -= 1
                if in_degree[next_course] == 0:
                    queue.append(next_course)

        return processed == numCourses