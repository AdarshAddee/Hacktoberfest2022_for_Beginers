
from collections import defaultdict

class Graph:

	def __init__(self):

		# default dictionary to store graph
		self.graph = defaultdict(list)

	def addEdge(self,u,v):
		self.graph[u].append(v)

	def DFSUtil(self, v, visited):

		visited[v]= True
		print v,

		for i in self.graph[v]:
			if visited[i] == False:
				self.DFSUtil(i, visited)


	def dfs(self):
		V = len(self.graph) #total vertices

		# Mark all the vertices as not visited
		visited =[False]*(V)

		for i in range(V):
			if visited[i] == False:
				self.DFSUtil(i, visited)


g = Graph()
g.addEdge(0, 1)
g.addEdge(0, 2)
g.addEdge(1, 2)
g.addEdge(2, 0)
g.addEdge(2, 3)
g.addEdge(3, 3)

g.dfs()

