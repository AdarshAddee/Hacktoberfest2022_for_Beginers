"""
Program : A tic tac toe game written in Python which can be played between 2 players
Github Username : @AshishKingdom
"""

class TicTacToe:
    """
    init some variables required for this class
    """
    def __init__ (self):
        self.board = [['1','2','3'],['4','5','6'],['7','8','9']]
        self.player1 = "X"
        self.player2 = "O"
        self.game_over = False
        return

    """
    draws the current board data in a good format
    """
    def draw_board(self):
        p = 0
        print("\n\n")
        for i in self.board:
            print(f"  {i[0]} | {i[1]} | {i[2]}  ")
            if p<2:
                print("-------------")
            p = p + 1
        print()
        return
    

    def set_value(self, position, t):
        for b in self.board:
            for i in range(0,3):
                if b[i]==position:
                    b[i] = t 
                    return True

        # if player enters wrong position
        print("Invalid Input! Please enter value between 1-9 only!")
        print("Enter your move again (1-9) : ")
        return False

    """
    plays the current game until the game gets tie or a player wins
    """
    def play(self):
        current_chance = 1 # 1-> player1 chance, -1 -> player 2 chance
        while self.game_status()==0:
            self.draw_board()
            if current_chance==1:
                cp = "X"
                print("Player 1, Enter your move (1-9) : ")
            else:
                cp = "O"
                print("Player 2, Enter your move (1-9) : ")
            while not self.set_value(input(), cp):
                pass
            current_chance = current_chance * -1 # switch between 1 and -1

        self.draw_board()
        s = self.game_status()
        if s==1:
            print("Player 1 Wins!!!")
        elif s==2:
            print("Player 2 Winns!!!")
        else:
            print("It's a TIE!!!")


    """
    returns 1 if player1 has won, 2 if player2 has won, 3 if the game has tie
    0 if the game is still in progress
    """
    def game_status(self):
        
        b = self.board
        for i in range(0,3): #row case
            if b[i][0]=='X' and b[i][1]=='X' and b[i][2]=='X':
                return 1
            if b[i][0]=='O' and b[i][1]=='O' and b[i][2]=='O':
                return 2

        for i in range(0,3): #column case
            if b[0][i]=='X' and b[1][i]=='X' and b[2][i]=='X':
                return 1
            if b[0][i]=='O' and b[1][i]=='O' and b[2][i]=='O':
                return 2
        #diagonal case
        if (b[0][0]=='X' and b[1][1]=='X' and b[2][2]=='X') or (b[0][2]=='X' and b[1][1]=='X' and b[2][0]=='X'):
                return 1
        if (b[0][0]=='O' and b[1][1]=='O' and b[2][2]=='O') or (b[0][2]=='O' and b[1][1]=='O' and b[2][0]=='O'):
                return 2
        #checking if their is a tie
        for i in range(0,3):
            for d in "123456789":
                if d in b[i]:
                    return 0 #one more chance is left
        return 3 # its a tie!


if __name__ == "__main__":
    game = TicTacToe()
    game.play()