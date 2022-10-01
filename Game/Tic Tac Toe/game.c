#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* 
 * THE GAME OF CROSS AND ZEROES.
 *
 * @author: Diptonil Roy (Bruce Wayne)
 * No other parties are directly or indirectly associated with the project. Any counterclaim to the said affirmation holds no basis.
 * 
 * @version: 69.420
 * The only feature is that it works.
 * 
 * @platform dependency: Windows (cannot clear off terminal in MAC or Linux)
 * 
 * @IDE: Visual Studio Code (output is properly formatted in VSC)
 * 
 * @rights: Wayne Enterprises
 * Any license for acquisition must be acquired from Wayne Enterprises. Please contact Artemis or Black Widow for the same.
 * Artemis is partying on the Moon.
 * Black Widow is on an alliance quest in a jungle full of Pandas.
 * 
 * 
 * FOR REFERENCE:
 * PURPLE: printf("\033[0;35m");
 * YELLOW: printf("\033[0;33m");
 * WHITE: printf("\033[0;37m");
 * 
 */

// Function declarations
void close();
void score_save();
void credits();
void main_menu();
void start();
void leaderboard();
void space_removal();

void space_removal(char *s)
// This function accepts a String and modifies it by removing all the whitespace characters.
{
    int len = strlen(s), compensation = 0, l;
    char str[25];

    // Appending non-whitespace characters to a new string.
    for (l = 0; l < len; l++)
    {
        if (s[l] == ' ')
        {
            compensation++;
            continue;
        }
        else
            str[l - compensation] = s[l];
    }

    // Closing off the string with a null literal.
    str[l - compensation] = '\0';

    // Copying the new value to the old one, thus making a change.
    strcpy(s, str);
    compensation = 0;
}

void score_save(char *n1, char *n2, int p1, int p2)
// This function accepts the names of the players and their scores and saves it in a file, sorting the same in a descending order.
{
    int c = 0;
    char ch[25];

    // Clears off the terminal.
    system("cls");

    // Opening up files and appending the scores before closing them.
    FILE *file1, *file2;
    file1 = fopen("leaderboards_name.txt", "a+");
    file2 = fopen("leaderboards_points.txt", "a+");
    fprintf(file1, "%s\n", n1);
    fprintf(file1, "%s\n", n2);
    fprintf(file2, "%d\n", p1);
    fprintf(file2, "%d\n", p2);
    fclose(file1);
    fclose(file2);

    // Opening up files and storing its contents in an array.
    file1 = fopen("leaderboards_name.txt", "r");
    file2 = fopen("leaderboards_points.txt", "r");
    while (fgets(ch, sizeof ch, file2) != NULL)
        c++;
    freopen("leaderboards_points.txt", "r", file2);
    int points[c];
    int x = 0;
    while (!feof(file2))
    {
        fscanf(file2, "%d", &points[x]);
        x++;
    }
    freopen("leaderboards_name.txt", "r", file1);
    char names[c][25];
    x = 0;
    int temp = 0;
    char stemp[25];
    while (!feof(file1))
    {
        fscanf(file1, " %s", &names[x]);
        x++;
    }

    // Sorting the two stored arrays in descending order.
    for (int l = 0; l < c - 1; l++)
    {
        for (int i = 0; i < c - 1 - l; i++)
        {
            if (points[i] < points[i + 1])
            {
                temp = points[i];
                points[i] = points[i + 1];
                points[i + 1] = temp;
                strcpy(stemp, names[i]);
                strcpy(names[i], names[i + 1]);
                strcpy(names[i + 1], stemp);
            }
        }
    }

    // Rewriting the files.
    freopen("leaderboards_name.txt", "w", file1);
    freopen("leaderboards_points.txt", "w", file2);
    for (int l = 0; l < c; l++)
    {
        fprintf(file1, "%s\n", names[l]);
        fprintf(file2, "%d\n", points[l]);
    }
    fclose(file1);
    fclose(file2);
    printf("\t\t\t\t\t Scores succesfully saved.\n\n");
}

void loop(char p1[], char p2[], char fp1, char fp2, int *points, char *winner)
// This function is the main game loop, accepting player names and their counters.
{
    int counter = 0, score = 0;
    char board[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int r, c;
    bool p1win = false, p2win = false, tied = false;
    for (int l = 1;; l++)
    {
        printf("\n\n");

        // Clearing off the screen.
        system("cls");

        // Displaying the game grid.
        printf("\t\t\t\t\t %c   \xB2\xB2\xB2   %c   \xB2\xB2\xB2   %c\n", board[0][0], board[0][1], board[0][2]);
        printf("\t\t\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        printf("\t\t\t\t\t %c   \xB2\xB2\xB2   %c   \xB2\xB2\xB2   %c\n", board[1][0], board[1][1], board[1][2]);
        printf("\t\t\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        printf("\t\t\t\t\t %c   \xB2\xB2\xB2   %c   \xB2\xB2\xB2   %c\n", board[2][0], board[2][1], board[2][2]);

        // Input row and column number.
        if (l % 2 == 0)
            printf("\n\n\t\t\t\t %s's TURN. ENTER ROW AND COLUMN SUCCESSIVELY.\n\n", p2);
        else
            printf("\n\n\t\t\t\t %s's TURN. ENTER ROW AND COLUMN SUCCESSIVELY.\n\n", p1);
        printf("\t\t\t\t\t  ");
        scanf("%d %d", &r, &c);

        // Condition for exiting game as stated as a rule.
        if (r == 0 || c == 0)
        {
            close();
        }

        // Invalid characters won't be accepted.
        if (r > 3 || c > 3)
        {
            l--;
            continue;
        }

        // Spaces already chosen aren't allowed to get refilled.
        if (board[r - 1][c - 1] == ' ')
        {
            if (l % 2 == 0)
                board[r - 1][c - 1] = fp2;
            else
                board[r - 1][c - 1] = fp1;
        }
        else
        {
            l--;
            continue;
        }

        // Game logic.
        if (board[0][0] == fp1 && board[0][1] == fp1 && board[0][2] == fp1)
            p1win = true;
        if (board[1][0] == fp1 && board[1][1] == fp1 && board[1][2] == fp1)
            p1win = true;
        if (board[2][0] == fp1 && board[2][1] == fp1 && board[2][2] == fp1)
            p1win = true;
        if (board[0][0] == fp2 && board[0][1] == fp2 && board[0][2] == fp2)
            p2win = true;
        if (board[1][0] == fp2 && board[1][1] == fp2 && board[1][2] == fp2)
            p2win = true;
        if (board[2][0] == fp2 && board[2][1] == fp2 && board[2][2] == fp2)
            p2win = true;
        if (board[0][0] == fp1 && board[1][0] == fp1 && board[2][0] == fp1)
            p1win = true;
        if (board[0][1] == fp1 && board[1][1] == fp1 && board[2][1] == fp1)
            p1win = true;
        if (board[0][2] == fp1 && board[1][2] == fp1 && board[2][2] == fp1)
            p1win = true;
        if (board[0][0] == fp2 && board[1][0] == fp2 && board[2][0] == fp2)
            p2win = true;
        if (board[0][1] == fp2 && board[1][1] == fp2 && board[2][1] == fp2)
            p2win = true;
        if (board[0][2] == fp2 && board[1][2] == fp2 && board[2][2] == fp2)
            p2win = true;
        if (board[0][0] == fp2 && board[1][1] == fp2 && board[2][2] == fp2)
            p2win = true;
        if (board[0][0] == fp1 && board[1][1] == fp1 && board[2][2] == fp1)
            p1win = true;
        if (board[0][2] == fp2 && board[1][1] == fp2 && board[2][0] == fp2)
            p2win = true;
        if (board[0][2] == fp1 && board[1][1] == fp1 && board[2][0] == fp1)
            p1win = true;

        // Condition for player victory.
        if (p1win == true || p2win == true)
        {
            score = 100 - 5 * l;
            break;
        }

        // Checking for draws.
        for (int x = 0; x < 3; x++)
            for (int y = 0; y < 3; y++)
                if (board[x][y] != ' ')
                    counter++;

        // Condition for draws.
        if (counter == 9)
        {
            tied = true;
            break;
        }
        counter = 0;
    }

    // Clearing off screen
    system("cls");

    // Displaying resultant grid.
    printf("\n\n");
    printf("\t\t\t\t\t  %c  \xB2\xB2\xB2   %c   \xB2\xB2\xB2  %c\n", board[0][0], board[0][1], board[0][2]);
    printf("\t\t\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\t\t\t\t\t  %c  \xB2\xB2\xB2   %c   \xB2\xB2\xB2  %c\n", board[1][0], board[1][1], board[1][2]);
    printf("\t\t\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\t\t\t\t\t  %c  \xB2\xB2\xB2   %c   \xB2\xB2\xB2  %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n\n");

    // Setting up the score and the winner.
    *points = score;
    if (p1win)
        *winner = '1';
    if (p2win)
        *winner = '2';
    if (tied)
        *winner = '0';
}

void start()
// This function starts up the game and is responsible for saving the results.
{
    int points, points1 = 0, points2 = 0;
    char winner;
    system("cls");
    char name1[25], name2[25], player1 = ' ', player2 = ' ';
    int ch;

    // Displaying rules and accepting player details.
    printf("\t\t\t RULES: The lesser the moves, higher is the winner's score. Enter 0 anytime to exit the game while playing.\n\n");
    printf("\t\t\t\t ENTER NAME OF PLAYER ONE: ");
    scanf(" %[^\n]", name1);
    printf("\n\n");
    printf("\t\t\t\t ENTER NAME OF PLAYER TWO: ");
    scanf(" %[^\n]", name2);
    printf("\n\n");
    printf("\t\t\t\t PLAYER ONE (%s), ENTER 1 TO CHOOSE '*', 2 TO CHOOSE 'O'.\n\n", name1);
    printf("\t\t\t\t\t\t  ");
    scanf("%d", &ch);
    getchar();
    switch (ch)
    {
    case 1:
        player1 = '*';
        player2 = 'O';
        break;
    case 2:
        player1 = 'O';
        player2 = '*';
        break;
    default:
        printf("\t\t\t\t\t  Invalid Choice. Restart the game.");
        exit(0);
    }

    // Main game loop.
    bool play = true;
    while (play)
    {
        loop(name1, name2, player1, player2, &points, &winner);
        if (winner == '0')
            printf("\t\t\t\t\t It was a draw. No points awarded to either of the parties.\n\n");
        if (winner == '1')
        {
            printf("\t\t\t\t\t Winner is %s with %d points.\n\n", name1, points);
            points1 += points;
        }
        if (winner == '2')
        {
            printf("\t\t\t\t\t Winner is %s with %d points.\n\n", name2, points);
            points2 += points;
        }
        printf("\t\t\t\t\t %s has %d points while %s has %d points.\n\n", name1, points1, name2, points2);
        printf("\t\t\t\t\t Enter 1 to play again and 2 to stop playing.\n");
        printf("\t\t\t\t\t\t  ");
        printf("\033[0;35m");
        scanf("%d", &ch);
        printf("\033[0;33m");
        switch (ch)
        {
        case 1:
            play = true;
            break;
        case 2:
            play = false;
            break;
        default:
            printf("\t\t\t\t\t  Invalid Choice. Terminating gameplay.\n\n");
            play = false;
        }
    }

    // Saving of scores.
    printf("\t\t\t Enter 1 to save the scores, 2 to go back to the main menu, 3 to exit.\n\n");
    printf("\t\t\t\t\t\t  ");
    printf("\033[0;35m");
    scanf("%d", &ch);
    printf("\033[0;33m");
    switch (ch)
    {
    case 1:
        space_removal(name1);
        space_removal(name2);
        score_save(name1, name2, points1, points2);
        break;
    case 2:
        main_menu();
        break;
    case 3:
        close();
        break;
    default:
        printf("\n\n");
        printf("\t\t\t\t  Invalid Choice. Program terminating...\n\n");
        exit(0);
        break;
    }
    printf("\n\n");

    // Endgame menu.
    printf("\t\t\t\t Enter 1 to go to the main menu, 2 to exit.\n\n");
    printf("\t\t\t\t\t\t  ");
    printf("\033[0;35m");
    scanf("%d", &ch);
    printf("\033[0;33m");
    switch (ch)
    {
    case 1:
        main_menu();
        break;
    case 2:
        close();
        break;
    default:
        printf("\n\n");
        printf("\t\t\t\t  Invalid Choice. Program terminating...\n\n");
        exit(0);
        break;
    }
}

void leaderboard()
// This function displays the top 5 (if sufficient data values exist) high scores with the player name.
{
    int c = 0;
    char ch[25];
    system("cls");
    printf("\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 LEADERBOARD \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n");
    printf("\t\t\t\t Counting down few of the best performances of all time.");
    printf("\n");
    for (int l = 1; l <= 115; l++)
        printf("\xB1");
    printf("\n");

    // Opening up files to extract data from there.
    FILE *file1 = fopen("leaderboards_name.txt", "r");
    FILE *file2 = fopen("leaderboards_points.txt", "r");

    if (!file1 || !file2)
    {
        printf("\n\n No records exist (scores have either not been saved or the save files have been deleted). Enter 1 to go to the main menu or 2 to exit the game.\n");
        printf("\t\t\t\t\t\t  ");
        int c;
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            main_menu();
            break;
        case 2:
            close();
            break;
        default:
            printf("\n\n");
            printf("\t\t\t\t  Invalid Choice. Program terminating...\n\n");
            exit(0);
        }
    }

    // Counting number of data elements
    while (fgets(ch, sizeof ch, file2) != NULL)
        c++;
    freopen("leaderboards_points.txt", "r", file2);
    if (c > 5)
        c = 5;

    // Extracting data.
    char points[c][25];
    int x = 0;
    while (!feof(file2))
    {
        fscanf(file2, " %s", &points[x]);
        x++;
    }
    char names[c][25];
    x = 0;
    while (!feof(file1))
    {
        fscanf(file1, " %s", &names[x]);
        x++;
    }
    fclose(file1);
    fclose(file2);

    // Displaying data.
    for (int l = 0; l < c; l++)
    {
        printf("\xB1\xB1\xB1\t\t\t\t %s \t\t\t %s \t\t\t\t\t\t\xB1\xB1\xB1\n", names[l], points[l]);
    }
    for (int l = 1; l <= 115; l++)
        printf("\xB1");

    // Endgame menu.
    printf("\n\n");
    printf("\t\t\t\t Enter 1 to go to the main menu, 2 to exit.\n\n");
    printf("\t\t\t\t\t\t  ");
    int choice;
    printf("\033[0;35m");
    scanf("%d", &choice);
    printf("\033[0;33m");
    switch (choice)
    {
    case 1:
        main_menu();
        break;
    case 2:
        close();
        break;
    default:
        printf("\n\n");
        printf("\t\t\t\t  Invalid Choice. Program terminating...\n\n");
        exit(0);
    }
}

void credits()
// This function credits the real makers of the game and tell us about the whereabout of the fake members of the group.
{
    int choice;
    system("cls");
    printf("\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 CREDITS \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n");
    printf("\n");
    for (int l = 1; l <= 114; l++)
        printf("\xB1");
    printf("\n");
    printf("\xB1\xB1   This piece of enigma was fashioned by the silent guardian, watchful protector, the dark knight - Batman.\t\xB1\xB1\n");
    printf("\xB1\xB1     Special thanks to nobody else. Artemis was on vacation. Black Widow was dreaming about Chris Evans.\t\xB1\xB1\n");
    printf("\xB1\xB1     Hence, kindly transfer all the credits of the inactive group members to Batman (the maker) himself.\t\xB1\xB1\n");
    printf("\xB1\xB1   Do not pay heed to any contrary claims to the above statements. All rights reserved by Wayne Enterprises.\t\xB1\xB1\n");
    for (int l = 1; l <= 114; l++)
        printf("\xB1");
    printf("\n\n");

    // Endgame menu.
    printf("\t\t\t\t Enter 1 to go to the main menu, 2 to exit.\n\n");
    printf("\t\t\t\t\t\t  ");
    printf("\033[0;35m");
    scanf("%d", &choice);
    printf("\033[0;33m");
    switch (choice)
    {
    case 1:
        main_menu();
        break;
    case 2:
        close();
        break;
    default:
        printf("\n\n");
        printf("\t\t\t\t  Invalid Choice. Program terminating...\n\n");
        exit(0);
    }
}

void close()
// This function safely exits the game.
{
    system("cls");
    exit(0);
}

void main_menu()
// This function is responsible for the main menu of the game.
{
    int choice;

    // Clearing off the screen
    system("cls");
    printf("\n");
    printf("\033[0;33m");

    // Menu.
    printf("\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 TIC-TAC-TOE \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n");
    printf("\n");
    for (int l = 1; l <= 120; l++)
        printf("\xB1");
    printf("\n");
    for (int l = 1; l <= 32; l++)
        printf("\xB1");
    printf("\t\t\t\t\t\t\t");
    for (int l = 1; l <= 32; l++)
        printf("\xB1");
    printf("\n");
    for (int l = 1; l <= 32; l++)
        printf("\xB1");
    printf("\t\t    1. START GAME\t\t\t");
    for (int l = 1; l <= 32; l++)
        printf("\xB1");
    printf("\n");
    for (int l = 1; l <= 32; l++)
        printf("\xB1");
    printf("\t\t    2. LEADERBOARD\t\t\t");
    for (int l = 1; l <= 32; l++)
        printf("\xB1");
    printf("\n");
    for (int l = 1; l <= 32; l++)
        printf("\xB1");
    printf("\t\t    3. CREDITS\t\t\t\t");
    for (int l = 1; l <= 32; l++)
        printf("\xB1");
    printf("\n");
    for (int l = 1; l <= 32; l++)
        printf("\xB1");
    printf("\t\t    4. EXIT\t\t\t\t");
    for (int l = 1; l <= 32; l++)
        printf("\xB1");
    printf("\n");
    for (int l = 1; l <= 32; l++)
        printf("\xB1");
    printf("\t\t\t\t\t\t\t");
    for (int l = 1; l <= 32; l++)
        printf("\xB1");
    printf("\n");
    for (int l = 1; l <= 120; l++)
        printf("\xB1");
    printf("\n\n");

    // Input choice.
    printf("\t\t\t\t\t\t  Enter Your Choice...\n\n");
    printf("\t\t\t\t\t\t\t");
    printf("\033[0;35m");
    scanf("%d", &choice);
    printf("\033[0;33m");
    switch (choice)
    {
    case 1:
        start();
        break;
    case 2:
        leaderboard();
        break;
    case 3:
        credits();
        break;
    case 4:
        close();
        break;
    default:
        printf("\n\n");
        printf("\t\t\t\t\t  Invalid Choice. Program terminating...\n\n");
        exit(0);
    }
}

void main()
// The main function.
{
    main_menu();
    printf("\033[0;37m");
}