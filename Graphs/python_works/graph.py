from typing import Any, TypeAlias

NodeType: TypeAlias = "Node"


class Edge:
    __slots__: tuple[str, ...] = ("_weight", "_dest_node")

    def __init__(self, weight: int, dest_node: NodeType):
        self._weight: int = weight
        self._dest_node: NodeType = dest_node

    @property
    def weight(self):
        return self._weight

    @property
    def dest_node(self) -> NodeType:
        return self._dest_node


class Node:
    __slots__: tuple[str, ...] = ("_name", "_edge_list")

    def __init__(self, name: str):
        self._name: str = name
        self._edge_list: list[Edge] = list()

    @property
    def name(self) -> str:
        return self._name

    @property
    def edges(self) -> list[Edge]:
        return self._edge_list


class Graph:
    __slots__: tuple[str, ...] = ("_nodes",)

    def __init__(self):
        self._nodes: list[Node] = list()

    def add_edge(self, n1: Node, n2: Node, weight: int) -> None:
        if n1 == n2:
            raise ValueError("We cannot connect a node to itself")
        n1.edges.append(Edge(weight, n2))
        n2.edges.append(Edge(weight, n1))

    def add_node(self, n: Node):
        return self._nodes.append(n)

    def print(self):
        for n in self._nodes:
            print(f"Node {n.name}")
            for e in n.edges:
                print(f"Destination Node {e.dest_node.name} of Weight {e.weight}")
            print()

    def bfs(self, starting_node: Node | None = None):
        visited_nodes: list[Node] = list()
        if starting_node is None:
            starting_node = self._nodes[0]

        for node in self._nodes:
            if node not in visited_nodes:
                visited_nodes.append(node)
            for edge in node.edges:
                if edge.dest_node in visited_nodes:
                    continue
                visited_nodes.append(edge.dest_node)
                print("\t->", end="")
                print(edge.dest_node.name, end="")


class AdjacencyListGraph(Graph):
    def __init__(self):
        self._nodes = dict[Any, list[Any]]
        super().__init__()
