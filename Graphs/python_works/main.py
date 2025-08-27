from graph import Graph, Node

node_1 = Node("One")
node_2 = Node("Three")
node_3 = Node("Five")
node_4 = Node("Seven")
node_5 = Node("Nine")
node_6 = Node("Eleven")
node_7 = Node("Thirteen")
node_8 = Node("Fifteen")

root_graph = Graph()
root_graph.add_node(node_1)
root_graph.add_node(node_2)
root_graph.add_node(node_3)
root_graph.add_node(node_4)
root_graph.add_node(node_5)
root_graph.add_node(node_6)
root_graph.add_node(node_7)
root_graph.add_node(node_8)

root_graph.add_edge(node_1, node_2, 1)
root_graph.add_edge(node_2, node_3, 1)
root_graph.add_edge(node_3, node_4, 1)
root_graph.add_edge(node_4, node_5, 1)
root_graph.add_edge(node_5, node_6, 1)
# root_graph.add_edge(node_6, node_6, 1)

root_graph.bfs()
