#Detect a Cycle in a Graph

Given a directed graph, how can we check if the graph contains a cycle or not? The function should return
true if the graph contains at least one cycle, else return false. 

##Dept First Traversel
Detecting cycles is an application for DFS. When we see a back edge (edge which point from a node to one of its ancestors),
we know there is a cycle in the graph.