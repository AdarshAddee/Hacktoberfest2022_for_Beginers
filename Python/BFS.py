import queue

# Syntax pada python untuk pembuatan graf menggunakan adjacency list
# graph = {
#     'A' : ['B','C'],
#     'B' : ['D','E'],
#     'C' : ['F'],
#     'D' : [],
#     'E' : ['F'],
#     'F' : ['H'],
#     'G' : ['H'],
#     'H' : ['G']
# }
# graph = {
#     'A' : ['B','F','E'],
#     'B' : ['G'],
#     'C' : ['D'],
#     'D' : ['H'],
#     'E' : ['F'],
#     'F' : ['B'],
#     'G' : ['C','H'],
#     'H' : ['D']
# }
graph = {
    'A' : ['B'],
    'B' : ['F','G'],
    'C' : ['D'],
    'D' : ['H'],
    'E' : ['F'],
    'F' : ['E'],
    'G' : ['C'],
    'H' : ['D']
}

# Buat Array untuk menyimpan node yang dikunjungi dan menyimpan antrian.
visited = [] # List to keep track of visited nodes.
queue = [] #Initialize a queue
# Buat fungsi BFS dengan menggunakan queue.
def bfs(visited, graph, node, goal):
    visited.append(node)
    queue.append(node)

    while queue:
        s = queue.pop(0)
        print(s, end = " ")
        if(s != goal):
            for neighbour in graph[s]:
                if neighbour not in visited:
                    visited.append(neighbour)
                    queue.append(neighbour)
        else:
            print("Selesai")
            break
# Tambahkan kode pemanggilan fugsi BFS.
print("Hasil penulusuran graf menggunakan BFS:")
bfs(visited, graph,'A','D')