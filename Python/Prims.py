# Github Username : pixalquarks
# Aim : Implementation of Prim's Algorithm for finding Minimum Spanning Tree for a adjacency matrix represented graph in Python
# Date : 10/4/2022

import sys
from pprint import pprint
from typing import List


class Graph:
    def __init__(self, adjacency_matrix: List[List[int]]) -> None:
        if not Graph.isSquareMatirx(adjacency_matrix):
            raise TypeError("Adjacency matrix must be square matrix")
        if len(adjacency_matrix) < 1:
            raise ValueError("Adjacency matrix is empty")

        self.__V = len(adjacency_matrix)
        self.__graph = adjacency_matrix

    @property
    def graph(self) -> List[List[int]]:
        return self.__graph

    @property
    def V(self) -> int:
        return self.__V

    @staticmethod
    def isSquareMatirx(matrix: List[List[int]]) -> bool:
        return all([len(row) == len(matrix) for row in matrix])

    def print_MST(self) -> None:
        mst = self.MST()
        print("Edge \tWeight")
        for i in range(1, self.V):
            print(mst[i], "-", i, "\t", self.graph[i][mst[i]])

    def min_key(self, key: List[int], mstSet: List[bool]) -> int:
        min = sys.maxsize
        for v in range(self.V):
            if key[v] < min and not mstSet[v]:
                min = key[v]
                min_index = v

        return min_index

    def MST(self) -> List[int]:
        key = [sys.maxsize] * self.V
        key[0] = 0
        result = [None] * self.V
        mstSet = [False] * self.V

        result[0] = -1

        for _ in range(self.V):
            u = self.min_key(key, mstSet)

            mstSet[u] = True

            for v in range(self.V):
                if self.graph[u][v] > 0 and not mstSet[v] and key[v] > self.graph[u][v]:
                    key[v] = self.graph[u][v]
                    result[v] = u

        return result


if __name__ == "__main__":
    adj_matrix = [
        [0, 2, 0, 6, 0],
        [2, 0, 3, 8, 5],
        [0, 3, 0, 0, 7],
        [6, 8, 0, 0, 9],
        [0, 5, 7, 9, 0],
    ]
    g = Graph(adj_matrix)

    pprint(g.graph)
    print(g.V)

    g.print_MST()
