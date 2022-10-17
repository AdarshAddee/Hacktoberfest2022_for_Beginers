board= [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]] 
def isvalid(board,row,col,c): 
    for i in range(9):
        #checking Colums 
        if board[i][col]==c: 
            return False
        #checking Rows 
        if board[row][i]==c: 
            return False
        #checking Box 
        if board[3*(row//3)+i//3][3*(col//3)+i%3]==c: 
            return False 
    return True 
def solve(board): 
    for i in range(9): 
        for j in range(9): 
            if board[i][j]=='.': 
                for c in range(1,10): 
                    if isvalid(board,i,j,str(c)): 
                        board[i][j]=str(c) 
                        if solve(board)==True: 
                            return True 
                        else: 
                            board[i][j]='.' 
                return False        
    return True 
solve(board) 
print(board)
