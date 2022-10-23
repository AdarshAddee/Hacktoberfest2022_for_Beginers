# Github username: Ernesto385291
# Aim: Gauss-Jordan method
# Date: 22-10-2022

# start coding

from typing import List

def readMatrix() -> List[List[float]]:
    matrix = []
    with open("matrix.txt") as f:
        for line in f:
            matrix.append([float(x) for x in line.split()])
    return matrix

def printMatrix(matrix: List[List[float]]) -> None:
    for row in matrix:
        print(row)

def gaussJordan(matrix: List[List[float]]) -> List[List[float]]:
    currentRow = 0
    print("\nProcedimiento:\n")
    for i in range(len(matrix)):
        pivot = matrix[i][i]

        # Dividimos la currentRow por el pivote
        matrix[currentRow] = [x / pivot for x in matrix[i]]
        print(f'E{currentRow+1} = E{currentRow+1} / {pivot} {[x / pivot for x in matrix[i]]} \n')

        #Restamos la matrix[currentRow] a todas las demas filas menos a si misma y multiplicamos por el pivote de cada fila
        for j in range(len(matrix)):
            if j != currentRow:
                currentValue = matrix[j][i]
                matrix[j] = [matrix[j][k] - matrix[currentRow][k] * matrix[j][i] for k in range(len(matrix[j]))]
                print(f'E{j+1} = E{j+1} - E{i+1} * {currentValue} {matrix[j]} \n')

        currentRow += 1

    return matrix


def main() -> None:
    matrix = readMatrix()
    print("Matriz original:\n")
    printMatrix(matrix)

    matrix = gaussJordan(matrix)
    print("Resultado:\n")
    printMatrix(matrix)


if __name__ == "__main__":
    main()
