class Solution:
    def findRedundantConnection(self, edges: list[list[int]]) -> list[int]:
        max_nodes = len(edges)
        visited: list[int] = list()
        redundant_edges: list[int] = edges[0]
        for edge in edges:
            if edge[0] in visited and edge[1] in visited:
                redundant_edges = edge
                continue
            if edge[0] not in visited:
                visited.append(edge[0])
            if edge[1] not in visited:
                visited.append(edge[1])
            print(redundant_edges)
        return redundant_edges
