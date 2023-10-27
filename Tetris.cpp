#include <iostream>
#include <ctime>
#include <windows.h>
#include <cstdio>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>
#undef max
using namespace std;
	
int BoardL = 10;
int BoardA = 20;

int LogicBoard[21][12] = {{0}};

typedef struct Score
{
	string nome;
	int score;
} Score;

int Pieces[7][4][4] = { {{0,0,1,0},{0,0,1,0},{0,0,1,0},{0,0,1,0}} , {{0,0,0,0},{0,1,0,0},{0,1,0,0},{0,1,1,0}} 
						, {{0,0,0,0},{0,0,1,0},{0,0,1,0},{0,1,1,0}} , {{0,0,0,0},{0,1,0,0},{0,1,1,0},{0,1,0,0}}
						, {{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}} , {{0,0,0,0},{0,1,0,0},{0,1,1,0},{0,0,1,0}}
						, {{0,0,0,0},{0,0,1,0},{0,1,1,0},{0,1,0,0}} };

void CreatePiece(int** peca, int seed)
{
	int i = seed;

	for (int y = 0;y < 4;y++)
	{
		for (int x = 0;x < 4;x++)
		{
			peca[y][x] = Pieces[i][y][x];
		}
	}
}

void DrawPiece(int** peca, int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (peca[i][j] == 1) LogicBoard[y + i][x + j] = 1;
		}
	}
}

void ErasePiece(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (LogicBoard[y + i][x + j] == 1) LogicBoard[y + i][x + j] = 0;
		}
	}
}

bool DoesPieceFit(int**, int, int);
int RotatePiece(int** peca, int x, int y)
{
	int** dummy, caso;
	dummy = new int* [4];
	for (int i = 0;i < 4;i++) dummy[i] = new int[4];

	dummy[0][0] = peca[3][0];
	dummy[0][1] = peca[2][0];
	dummy[0][2] = peca[1][0];
	dummy[0][3] = peca[0][0];
	dummy[1][0] = peca[3][1];
	dummy[1][1] = peca[2][1];
	dummy[1][2] = peca[1][1];
	dummy[1][3] = peca[0][1];
	dummy[2][0] = peca[3][2];
	dummy[2][1] = peca[2][2];
	dummy[2][2] = peca[1][2];
	dummy[2][3] = peca[0][2];
	dummy[3][0] = peca[3][3];
	dummy[3][1] = peca[2][3];
	dummy[3][2] = peca[1][3];
	dummy[3][3] = peca[0][3];

	if (DoesPieceFit(dummy, x, y))
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				peca[i][j] = dummy[i][j];
			}
		}
		caso = 0;
	}
	else if (x == 8 && DoesPieceFit(dummy, x - 1, y))
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				peca[i][j] = dummy[i][j];
			}
		}
		caso = 1;
	}
	else if (x == 0 && DoesPieceFit(dummy, x + 1, y))
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				peca[i][j] = dummy[i][j];
			}
		}
		caso = 2;
	}
	else if (x == 9 && DoesPieceFit(dummy, x - 2, y))
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				peca[i][j] = dummy[i][j];
			}
		}
		caso = 3;
	}
	else if (x == -1 && DoesPieceFit(dummy, x + 2, y))
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				peca[i][j] = dummy[i][j];
			}
		}
		caso = 4;
	}
	else caso = 5;

	for (int i = 0;i < 4;i++) delete dummy[i];
	delete dummy;
	return caso;
}


bool DoesPieceFit(int** peca, int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (peca[i][j] == 1 && (LogicBoard[y + i][x + j] == 2 || LogicBoard[y + i][x + j] == 3)) return false;
		}
	}
	return true;
}


void ClearScreen()
{
	COORD cursorPosition;	
	cursorPosition.X = 0;	
	cursorPosition.Y = 0;	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

void DrawBoard()
{
	for (int y = 0;y < BoardA + 2;y++)
	{
		for (int x = 0;x < BoardL + 2;x++)
		{
			if (LogicBoard[y][x] == 3) cout << '#';
			else if (LogicBoard[y][x] == 4) cout << '=';
			else if (LogicBoard[y][x] == 1 || LogicBoard[y][x] == 2) cout << (char)254;
			else cout << ' ';
			
			cout << ((x==BoardL+1)?"\n":" ");
		}
	}
}

void DrawScoreNext(int score, int next, int lines, int level)
{
	cout << endl << "Next:" << endl;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (Pieces[next][i][j] == 1) cout << (char)254;
			else cout << " ";

			if (j == 3) cout << endl;
			else cout << " ";
		}
	}

	cout << endl << endl << "Score: " << score << endl << endl;
	cout << "Lines Cleared: " << lines << " --- Level " << level << endl;
}

int LevelSpeed(int level)
{
	if (level == 0) return 48;
	else if (level == 1) return 43;
	else if (level == 2) return 38;
	else if (level == 3) return 33;
	else if (level == 4) return 28;
	else if (level == 5) return 23;
	else if (level == 6) return 18;
	else if (level == 7) return 13;
	else if (level == 8) return 8;
	else if (level == 9) return 6;
	else if (level >= 10 && level <= 12) return 5;
	else if (level >= 13 && level <= 15) return 4;
	else if (level >= 16 && level <= 18) return 3;
	else if (level >= 19 && level <= 28) return 2;
	else return 1;
}

int AddScore(int level, int lines)
{
	switch (lines)
	{
	case 1:
		return 40 * (level + 1);
		break;
	case 2:
		return 100 * (level + 1);
		break;
	case 3:
		return 300 * (level + 1);
		break;
	case 4:
		return 1200 * (level * 1);
	}
}

int SelectLevel()
{
	int level[20] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
	int pos = 0;

	bool key[3];
	bool decision = false;
	bool keypress1 = false, keypress2 = false;
	while (!decision)
	{
		ClearScreen();

		for (int k = 0;k < 3;k++)
		{
			key[k] = (0x8000 & GetAsyncKeyState((unsigned char)("\x27\x25\x0D"[k]))) != 0;
		}

		if (key[0])
		{
			if (!keypress1 && pos < 19) pos++;
			keypress1 = true;
		}
		else keypress1 = false;

		if (key[1])
		{
			if (!keypress2 && pos > 0) pos--;
			keypress2 = true;
		}
		else keypress2 = false;

		if (key[2])
		{
			decision = true;
		}

		cout << "===Selecione uma dificuldade===" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			if (i == pos)cout << "[" << level[i] << "]";
			else cout << " " << level[i] << " ";
		}
	}

	system("cls");
	return pos;
}

void Highscore(int score)
{
	Sleep(500);
	ofstream Scoreo;
	ifstream Scorei;
	string line;
	Score scores[5];
	for (int i = 0; i < 5; i++)
	{
		scores[i].nome = "   ";
		scores[i].score = 0;
	}
	istringstream input1, input2, input3, input4, input5;
	int i = 0;
	Scorei.open("Highscore.txt");
	if (Scorei.is_open())
	{
		while (getline(Scorei, line))
		{
			switch (i)
			{
			case 0:
				input1.str(line);
				input1 >> scores[i].nome >> scores[i].score;
				break;
			case 1:
				input2.str(line);
				input2 >> scores[i].nome >> scores[i].score;
				break;
			case 2:
				input3.str(line);
				input3 >> scores[i].nome >> scores[i].score;
				break;
			case 3:
				input4.str(line);
				input4 >> scores[i].nome >> scores[i].score;
				break;
			case 4:
				input5.str(line);
				input5 >> scores[i].nome >> scores[i].score;
				break;
			}
			i++;
		}
		Scorei.close();
	}

	cout << endl << "---Highscores---" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << ". " << scores[i].nome << " - " << scores[i].score << endl;
	}

	if (score > scores[4].score)
	{
		ShowConsoleCursor(true);
		cout << endl << "Insira seu nome para salvar seu score:" << endl;
		Score novo;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> novo.nome;
		novo.score = score;

		if (novo.score >= scores[0].score)
		{
			for (int i = 4; i > 0; i--)
			{
				scores[i] = scores[i - 1];
			}
			scores[0] = novo;
		}
		if (novo.score >= scores[1].score && novo.score < scores[0].score)
		{
			for (int i = 4; i > 1; i--)
			{
				scores[i] = scores[i - 1];
			}
			scores[1] = novo;
		}
		if (novo.score >= scores[2].score && novo.score < scores[1].score)
		{
			for (int i = 4; i > 2; i--)
			{
				scores[i] = scores[i - 1];
			}
			scores[2] = novo;
		}
		if (novo.score >= scores[3].score && novo.score < scores[2].score)
		{
			for (int i = 4; i > 3; i--)
			{
				scores[i] = scores[i - 1];
			}
			scores[3] = novo;
		}
		if (novo.score >= scores[4].score && novo.score < scores[3].score)
		{
			scores[4] = novo;
		}

		system("cls");
		Sleep(500);
		cout << endl << "---Highscores---" << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << i + 1 << ". " << scores[i].nome << " - " << scores[i].score << endl;
		}

		Scoreo.open("Highscore.txt");
		for (int i = 0; i < 5; i++)
		{
			Scoreo << scores[i].nome << " " << scores[i].score << endl;
		}
	}
}

int main()
{
	srand(time(0));
	ShowConsoleCursor(false);

	for (int y = 0; y < 21; y++)
	{
		for (int x = 0; x < 12; x++)
		{
			if (x == 0 || x == 11 || y == 20) LogicBoard[y][x] = 3;
		}
	}

	int level = SelectLevel();

	int speed = LevelSpeed(level);
	int speedCounter = 0;
	bool ForceDown = false;
	int Lines = 0;
	int Score = 0;
	int linesCleared = 0;
	int framecounter = 0;
	

	bool key[4];
	bool keyhold = false;
	bool downhold = false;
	bool rhold = false;
	int rframehold = 0;
	bool lhold = false;
	int lframehold = 0;
	bool GameOver = false;

	int** pecaAtual;
	int next = rand()%7;
	pecaAtual = new int*[4];
	for (int i = 0;i < 4;i++) pecaAtual[i] = new int[4];
	int xAtual = 5;
	int yAtual = 0;
	int rotatecaso;

	CreatePiece(pecaAtual, rand()%7);
	DrawPiece(pecaAtual, xAtual, yAtual);

	while (!GameOver)
	{
		ClearScreen();

		//timing
		Sleep(1000 / 60);
		framecounter++;
		speedCounter++;
		ForceDown = (speedCounter == speed);

		//input
		for (int k = 0;k < 4;k++)
		{
			key[k] = (0x8000 & GetAsyncKeyState((unsigned char)("\x27\x25\x28\x11"[k]))) != 0;
		}

		//logic
		ErasePiece(xAtual, yAtual);
		if (key[0])
		{
			if (!rhold)
			{
				xAtual += (key[0] && DoesPieceFit(pecaAtual, xAtual + 1, yAtual)) ? 1 : 0;
				rframehold = framecounter;
			}
			else if (rhold && framecounter-rframehold > 5) xAtual += (key[0] && DoesPieceFit(pecaAtual, xAtual + 1, yAtual)) ? 1 : 0;
			rhold = true;
		}
		else rhold = false;

		if (key[1])
		{
			if (!lhold)
			{
				xAtual -= (key[1] && DoesPieceFit(pecaAtual, xAtual - 1, yAtual)) ? 1 : 0;
				lframehold = framecounter;
			}
			else if (lhold && framecounter - lframehold > 5) xAtual -= (key[1] && DoesPieceFit(pecaAtual, xAtual - 1, yAtual)) ? 1 : 0;
			lhold = true;
		}
		else lhold = false;

		if (key[2])
		{
			yAtual += (key[2] && DoesPieceFit(pecaAtual, xAtual, yAtual + 1)) ? 1 : 0;

			if (!downhold) ForceDown = true;
			downhold = true;
		}
		else downhold = false;

		if (key[3])
		{
			if (!keyhold)
			{
				rotatecaso = RotatePiece(pecaAtual, xAtual, yAtual);
				switch (rotatecaso)
				{
				case 1:
					xAtual--;
					break;
				case 2:
					xAtual++;
					break;
				case 3:
					xAtual -= 2;
					break;
				case 4:
					xAtual += 2;
					break;
				}
			}
			keyhold = true;
		}
		else keyhold = false;

		if (ForceDown)
		{
			if (DoesPieceFit(pecaAtual, xAtual, yAtual + 1))
			{
				yAtual++;
			}

			else
			{
				//locking
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						if (pecaAtual[i][j]==1) LogicBoard[yAtual + i][xAtual + j] = 2;
					}
				}

				//clear lines
				for (int y = 0; y < BoardA; y++)
				{
					bool line = true;

					for (int x = 1; x < BoardL + 1; x++)
					{
						if (LogicBoard[y][x] == 0) line = false;
					}

					if (line)						
					{
						for (int x = 1; x < BoardL + 1; x++)
						{
							LogicBoard[y][x] = 4;
						}
						Lines ++;
						linesCleared++;
						if (linesCleared % 10 == 0 && linesCleared / 10 > level)
						{
							level++;
							speed = LevelSpeed(level);
						}
					}
				}

				if (Lines>0)
				{
					DrawBoard();
					Sleep(500);
					ClearScreen();
					for (int i = 0; i < BoardA; i++)
					{
						if (LogicBoard[i][1] == 4)
						{
							for (int j = i; j > 0; j--)
							{
								for (int k = 1; k < BoardL + 1; k++)
								{
									LogicBoard[j][k] = LogicBoard[j - 1][k];
								}
							}
							for (int k = 1; k < BoardL + 1; k++)
							{
								LogicBoard[0][k] = 0;
							}
						}
					}

					Score += AddScore(level, Lines);
					Lines = 0;
				}

				//new piece
				xAtual = 5;
				yAtual = 0;

				CreatePiece(pecaAtual, next);
				next = rand() % 7;

				//gameover
				GameOver = !DoesPieceFit(pecaAtual, xAtual, yAtual);
			}

			speedCounter = 0;
		}

		DrawPiece(pecaAtual, xAtual, yAtual);
		

		//drawing
		DrawBoard();
		DrawScoreNext(Score, next, linesCleared, level);
	}
	system("cls");

	DrawBoard();

	cout << endl << endl << "Fim de jogo! Score: " << Score << endl << endl << "Pressione Enter para continuar." << endl;


	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getchar();

	system("cls");
	Highscore(Score);

	std::cout << endl << "Pressione Enter para sair.";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getchar();

	return 0;
}
