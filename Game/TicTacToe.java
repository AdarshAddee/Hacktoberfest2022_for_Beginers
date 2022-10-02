import java.util.*;
class TicTacToe {
	// Contains some important instructions for The Game Tic-Tac-Toe.
	public static void instructionForTicTacToe() {
		char[][] board = {{'1','|','2','|','3'},
						  {'-','+','-','+','-'},
						  {'4','|','5','|','6'},
						  {'-','+','-','+','-'},
						  {'7','|','8','|','9'}};
		System.out.print("\"Lets play Tic-Tac-Toe...\"\n\n");
		System.out.print("Please note the following instructions :-\n");
		System.out.print("1.) \'X\' represents Player I [You].\n");
		System.out.print("2.) \'O\' represents Player II [Device].\n");
		System.out.print("3.) Player I [You] will be allowed first to make your move.\n");
		System.out.print("4.) Please enter the correct placement position [1-9] when asked.\n");
		System.out.print("5.) Please note the placement positions :-\n\n");
		displayBoard(board);
		System.out.print("6.) In case you entered the wrong placement position then you will provided the chance to re-enter the placement position.\n");
		System.out.print("7.) Remember you will be provided only 4 extra chances to enter the placement position in case you entered it wrong.\n");
		System.out.print("\nThe Game starts...\n\n");
	}
	// To display the Tic-Tac-Toe board.
	public static void displayBoard(char[][] board) {
		for (int i = 0; i < board.length; i++) {
			for (int space = 1; space <= 5; space++) {
				System.out.print(" ");
			}
			for (int j = 0; j < board[i].length; j++) {
				System.out.print(board[i][j]);
			}
			System.out.print("\n");
		}
		System.out.print("\n");
	}
	// To check for the passed symbol in the first row.
	public static boolean checkFirstRow(char[][] board, char symbol) {
		int countSymbol = 0;
		for (int i = 0; i < board[0].length; i += 2) {
			if (board[0][i] == symbol)
				countSymbol++;
		}
		return (countSymbol == 3);
	}
	// To check for the passed symbol in the second row.
	public static boolean checkSecondRow(char[][] board, char symbol) {
		int countSymbol = 0;
		for (int i = 0; i < board[2].length; i += 2) {
			if (board[2][i] == symbol)
				countSymbol++;
		}
		return (countSymbol == 3);
	}
	// To check for the passed symbol in the third row.
	public static boolean checkThirdRow(char[][] board, char symbol) {
		int countSymbol = 0;
		for (int i = 0; i < board[4].length; i += 2) {
			if (board[4][i] == symbol)
				countSymbol++;
		}
		return (countSymbol == 3);
	}
	// To check for the passed symbol in the first column.
	public static boolean checkFirstColumn(char[][] board, char symbol) {
		int countSymbol = 0;
		for (int i = 0; i < board.length; i += 2) {
			if (board[i][0] == symbol)
				countSymbol++;
		}
		return (countSymbol == 3);
	}
	// To check for the passed symbol in the second column.
	public static boolean checkSecondColumn(char[][] board, char symbol) {
		int countSymbol = 0;
		for (int i = 0; i < board.length; i += 2) {
			if (board[i][2] == symbol)
				countSymbol++;
		}
		return (countSymbol == 3);
	}
	// To check for the passed symbol in the third column.
	public static boolean checkThirdColumn(char[][] board, char symbol) {
		int countSymbol = 0;
		for (int i = 0; i < board.length; i += 2) {
			if (board[i][4] == symbol)
				countSymbol++;
		}
		return (countSymbol == 3);
	}
	// To check for the passed symbol in the primary diagonal.
	public static boolean checkPrimaryDiagonal(char[][] board, char symbol) {
		int countSymbol = 0;
		for (int i = 0; i < board.length; i += 2) {
			for (int j = 0; j < board[i].length; j += 2) {
				if (board[i][j] == symbol && i == j)
					countSymbol++;
			}
		}
		return (countSymbol == 3);
	}
	// To check for the passed symbol in the secondary diagonal.
	public static boolean checkSecondaryDiagonal(char[][] board, char symbol) {
		int countSymbol = 0;
		for (int i = 0; i < board.length; i += 2) {
			for (int j = 0; j < board[i].length; j += 2) {
				if (board[i][j] == symbol && i+j == board[i].length-1)
					countSymbol++;
			}
		}
		return (countSymbol == 3);
	}
	// To place the symbol on Tic-tac-toe board.
	public static void placeSymbol(char[][] board, int placementPos, char symbol) {
		switch (placementPos) {
			case 1 : board[0][0] = symbol;
			break;
			case 2 : board[0][2] = symbol;
			break;
			case 3 : board[0][4] = symbol;
			break;
			case 4 : board[2][0] = symbol;
			break;
			case 5 : board[2][2] = symbol;
			break;
			case 6 : board[2][4] = symbol;
			break;
			case 7 : board[4][0] = symbol;
			break;
			case 8 : board[4][2] = symbol;
			break;
			case 9 : board[4][4] = symbol;
		}
	}
	// To check if the symbol placement position is empty or not.
	public static boolean isEmptyPlacementPosition(char[][] board, int placementPosition) {
		boolean result = false;
		switch(placementPosition) {
			case 1 : result = board[0][0] == ' ' ? true : false;
			break;
			case 2 : result = board[0][2] == ' ' ? true : false;
			break;
			case 3 : result = board[0][4] == ' ' ? true : false;
			break;
			case 4 : result = board[2][0] == ' ' ? true : false;
			break;
			case 5 : result = board[2][2] == ' ' ? true : false;
			break;
			case 6 : result = board[2][4] == ' ' ? true : false;
			break;
			case 7 : result = board[4][0] == ' ' ? true : false;
			break;
			case 8 : result = board[4][2] == ' ' ? true : false;
			break;
			case 9 : result = board[4][4] == ' ' ? true : false;
		}
		return result;
	}
	// To take and return player I (you) symbol placement position.
	public static int playerITurn(char[][] board) {
		Scanner input = new Scanner(System.in);
		System.out.print("Enter 1-9 placement position : ");
		int playerIPlacement = input.nextInt();
		int countInvalidChoices = 1;
		while (playerIPlacement > 9 || playerIPlacement < 1 || !isEmptyPlacementPosition(board, playerIPlacement)) {
			countInvalidChoices++;
			if (countInvalidChoices == 6)
				return -1;
			System.out.print("Please enter the correct placement position : ");
			playerIPlacement = input.nextInt();
		}
		return playerIPlacement;
	}
	// To take and return player II (device) symbol placement position.
	public static int playerIITurn(char[][] board) {
		int max = 9;
		int min = 1;
		int playerIIPlacement = (int)Math.floor(Math.random()*(max-min+1)+min);
		while (!isEmptyPlacementPosition(board, playerIIPlacement)) {
			playerIIPlacement = (int)Math.floor(Math.random()*(max-min+1)+min);
		}
		return playerIIPlacement;
	}
	// To check winner by checking for the occurence of symbol in every possible winning direction.
	public static boolean isWinner(char[][] board, char symbol) {
		boolean inFirstRow = checkFirstRow(board, symbol);
		boolean inSecondRow = checkSecondRow(board, symbol);
		boolean inThirdRow = checkThirdRow(board, symbol);
		boolean inFirstColumn = checkFirstColumn(board, symbol);
		boolean inSecondColumn = checkSecondColumn(board, symbol);
		boolean inThirdColumn = checkThirdColumn(board, symbol);
		boolean inPrimaryDiagonal = checkPrimaryDiagonal(board, symbol);
		boolean inSecondaryDiagonal = checkSecondaryDiagonal(board, symbol);
		return (inFirstRow || inSecondRow || inThirdRow || inFirstColumn || inSecondColumn || inThirdColumn || inPrimaryDiagonal || inSecondaryDiagonal);
	}
	// To check if there is any placement position left.
	public static boolean checkEmptiness(char[][] board) {
		for (int i = 0; i < board.length; i += 2) {
			for (int j = 0; j < board[i].length; j += 2) {
				if (board[i][j] == ' ')
					return true;
			}
		}
		return false;
	}
	// Game implementation starts here.
	public static void main(String[] args) {
		// Creating Tic-Tac-toe board.
		char[][] board = {{' ','|',' ','|',' '},
						  {'-','+','-','+','-'},
						  {' ','|',' ','|',' '},
						  {'-','+','-','+','-'},
						  {' ','|',' ','|',' '}};
		instructionForTicTacToe();
		displayBoard(board);
		String winner = "";
		boolean full = false;
		while (true) {
			if (!checkEmptiness(board)) {
				full = true;
				break;
			}
			int playerIPlacementPosition = playerITurn(board);
			if (playerIPlacementPosition == -1)
				break;
			placeSymbol(board, playerIPlacementPosition, 'X');
			if (isWinner(board,'X')) {
				winner = "Player I [You]";
				break;
			}
			if (!checkEmptiness(board)) {
				full = true;
				break;
			}
			int playerIIPlacementPosition = playerIITurn(board);
			placeSymbol(board, playerIIPlacementPosition, 'O');
			if (isWinner(board,'O')) {
				winner = "Player II [Device]";
				break;
			}
			if (!checkEmptiness(board)) {
				full = true;
				break;
			}
			System.out.print("\n");
			displayBoard(board);
		}
		System.out.print("\n");
		displayBoard(board);
		if (!winner.equalsIgnoreCase("")) {
			if (winner.equalsIgnoreCase("Player I [You]"))
				System.out.print("Congratulations!!! "+winner+" won the match.\n");
			else
				System.out.print("Oops!!! "+winner+" won the match.\n");
		}
		else {
			if (!full)
				System.out.print("Not interested? Game over!!!\n");
			else
				System.out.print("Match tie. Keep it up!!!\n");
		}
	}
}