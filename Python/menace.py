from collections import Counter
import random


class Board:

    # constructor for initializing the board
    def __init__(self):
        self.board = [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ']

    # function to display the board systematically
    def __str__(self):
        return("\n 0 | 1 | 2     %s | %s | %s\n"
               "---+---+---   ---+---+---\n"
               " 3 | 4 | 5     %s | %s | %s\n"
               "---+---+---   ---+---+---\n"
               " 6 | 7 | 8     %s | %s | %s" % (self.board[0], self.board[1], self.board[2],
                                                self.board[3], self.board[4], self.board[5],
                                                self.board[6], self.board[7], self.board[8]))

    
    # given the index position from (0-8), check whether this move is valid or not
    def check_valid_moves(self, move):
        try:
            move = int(move)
        except ValueError:
            return False
        if 0 <= move <= 8 and self.board[move] == ' ':
            return True
        return False


    # all the conditions of winning the game
    def winning_configurations(self):
        return ((self.board[0] != ' ' and
                 ((self.board[0] == self.board[1] == self.board[2]) or
                  (self.board[0] == self.board[3] == self.board[6]) or
                  (self.board[0] == self.board[4] == self.board[8])))
                or (self.board[4] != ' ' and
                    ((self.board[1] == self.board[4] == self.board[7]) or
                    (self.board[3] == self.board[4] == self.board[5]) or
                    (self.board[2] == self.board[4] == self.board[6])))
                or (self.board[8] != ' ' and
                    ((self.board[2] == self.board[5] == self.board[8]) or
                    (self.board[6] == self.board[7] == self.board[8]))))

    
    # to get the draw condition when all the 9 blocks are filled, ie:non-empty
    def draw_configurations(self):
        return all((x != ' ' for x in self.board))

    # plays a move on the board given the player's marker and the index
    def play_the_move(self, position, marker):
        self.board[position] = marker


    # joining all the positions of the board to form a state 
    def board_string(self):
        return ''.join(self.board)



# All the utilites of machine as a player
class MenacePlayer:

    def __init__(self):
        
        # the key represents the state and the value represents the different beads present in that state
        self.MatchBoxes = {}        # empty dictionary of MatchBoxes to store the beads in the mathboxes in a particular state
        
        # initializing the statistics of game played by machine
        self.win_count = 0
        self.draw_count = 0
        self.lose_count = 0

    # initialising the list of all the moves played by menace
    def start_the_game(self):
        self.movesPlayed = []

    
    # function which deals with finding a random move based on the number of beads present in the match box of the current state
    def getMove(self, board):

        board = board.board_string()
        
        # if the current board is not present in the dictionary then create a new entry of this board and fill different beads according to the empty states present on the board
        if board not in self.MatchBoxes:
            new_beads = [pos for pos, mark in enumerate(board) if mark == ' ']

            # Early boards start with more beads
            self.MatchBoxes[board] = new_beads * ((len(new_beads) + 2) // 2)
            # print(self.MatchBoxes.keys())
            

        beads = self.MatchBoxes[board]
        if len(beads):

            # randomly choose a bead from the corresponding state array
            bead = random.choice(beads)
            self.movesPlayed.append((board, bead))
            # print("bead choosen = ",bead)
            # print(self.movesPlayed)
        else:
            bead = -1
        # print()
        return bead

    # if the machine wins, it will backtrack all the states it had been and add 3 more beads of the corresponding action taken in that state. 
    def winGame(self): 
        for (board, bead) in self.movesPlayed:
            self.MatchBoxes[board].extend([bead, bead, bead])
        self.win_count += 1

    # if game is drawn, it will backtrack all the states it had been and add 1 more bead of the corresponding action taken in that state. 
    def drawGame(self):
        for (board, bead) in self.movesPlayed:
            self.MatchBoxes[board].append(bead)
        self.draw_count += 1

    # if machine looses, it will backtrack all the states it had been and remove 1 bead of the corresponding action taken in that state. 
    def loseGame(self):
        for (board, bead) in self.movesPlayed:
            matchbox = self.MatchBoxes[board]
            del matchbox[matchbox.index(bead)]
        self.lose_count += 1


    #to count the number of states stored
    def length(self):
        return (len(self.MatchBoxes))



# all utilities of human as a player
class HumanPlayer:
    def __init__(self):
        pass

    def start_the_game(self):
        print("Get ready!")

    def getMove(self, board):
        while True:
            move = input('Make a move: ')
            if board.check_valid_moves(move):
                break
            print("Not a valid move")
        return int(move)

    def winGame(self):
        print("You won!")

    def drawGame(self):
        print("It's a draw.")

    def loseGame(self):
        print("You lose.")

    def print_probability(self, board):
        pass


# function to play a game
def playGame(first, second, silent=False):
    
    # initializing the game of both players
    first.start_the_game()
    second.start_the_game()
    board = Board()

    # silent is baiscally used ot track if the game played by the human or not, if human present, silent=False, else ture
    if not silent:
        print("\n\nStarting a new game!")
        print(board)

    while True:
        
        move = first.getMove(board)

        # illegal move
        if move == -1:
            if not silent:
                print("Player resigns")
            first.loseGame()
            second.winGame()
            break

        # player 1 moves
        board.play_the_move(move, 'X')

        if not silent:
            print(board)

        if board.winning_configurations():
            first.winGame()
            second.loseGame()
            break

        if board.draw_configurations():
            first.drawGame()
            second.drawGame()
            break

        move = second.getMove(board)
        
        if move == -1:
            if not silent:
                print("Player resigns")
            second.loseGame()
            first.winGame()
            break

        # player 2 moves
        board.play_the_move(move, 'O')

        if not silent:
            print(board)

        if board.winning_configurations():
            second.winGame()
            first.loseGame()
            break


if __name__ == '__main__':
    machine1 = MenacePlayer()
    machine2 = MenacePlayer()
    human = HumanPlayer()


    # first we kind of a train the machine by playing with another machine
    for i in range(10000):
        playGame(machine1, machine2, silent=True)


    print("number of states of machine 1 = ",machine1.length())
    print("number of states of machine 2 = ",machine2.length())

    # play game between trained machine and human
    playGame(human, machine2)
