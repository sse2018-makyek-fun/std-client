#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// board information
#define BOARD_SIZE 8
#define EMPTY 0
#define BLACK 1
#define WHITE 2

// bool
typedef int BOOL;
#define TRUE 1
#define FALSE 0

// option
typedef int OPTION;
#define UP_LEFT 0
#define UP_RIGHT 1
#define DOWN_LEFT 2
#define DOWN_RIGHT 3
#define JUMP_UL 4
#define JUMP_UR 5
#define JUMP_DL 6
#define JUMP_DR 7

#define MAX_BYTE 10000
#define TO_STRING(x) "%" #x "[^\n]"
#define LINE_FORMAT(l) TO_STRING(l)

#define START "START"
#define PLACE "PLACE"
#define TURN "TURN"
#define END "END"

struct Command
{
    int x;
    int y;
    OPTION option;
};

char board[BOARD_SIZE][BOARD_SIZE] = {0};
int me_flag;
int other_flag;

const int DIR[8][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}, {-2, -2}, {-2, 2}, {2, -2}, {2, 2}};

void debug(const char *str)
{
    printf("DEBUG %s\n", str);
    fflush(stdout);
}

void printBoard()
{
    char visual_board[BOARD_SIZE][BOARD_SIZE] = {0};
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == EMPTY)
            {
                visual_board[i][j] = '.';
            }
            else if (board[i][j] == BLACK)
            {
                visual_board[i][j] = 'O';
            }
            else if (board[i][j] == WHITE)
            {
                visual_board[i][j] = 'X';
            }
        }
        printf("%s\n", visual_board[i]);
    }
}

BOOL isInBound(int x, int y)
{
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int min (int a, int b)
{
    return a < b ? a : b;
}

/**
 * YOUR CODE BEGIN
 * 你的代码开始
 */

/**
 * You can define your own struct and variable here
 * 你可以在这里定义你自己的结构体和变量
 */

/**
 * 你可以在这里初始化你的AI
 */
void initAI(int me)
{
}

struct Command findValidPos(const char board[BOARD_SIZE][BOARD_SIZE], int flag)
{
    struct Command command = {0, 0, 0};
    for (int k = 0; k < 8; k++)
    {
        const int *delta = DIR[k];
        for (int x = 0; x < BOARD_SIZE; x++)
        {
            for (int y = 0; y < BOARD_SIZE; y++)
            {
                if (board[x][y] != flag)
                {
                    continue;
                }
                int new_x = x + delta[0];
                int new_y = y + delta[1];
                if (isInBound(new_x, new_y) && board[new_x][new_y] == EMPTY)
                {
                    command.x = x;
                    command.y = y;
                    command.option = k;
                    return command;
                }
            }
        }
    }
    return command;
}

/**
 * 轮到你落子。
 * 棋盘上0表示空白，1表示黑棋，2表示白旗
 * me表示你所代表的棋子(1或2)
 * 你需要返回一个结构体Command，在x属性和y属性填上你想要移动的棋子的位置，option填上你想要移动的方向。
 */
struct Command aiTurn(const char board[BOARD_SIZE][BOARD_SIZE], int me)
{
    /*
     * TODO：在这里写下你的AI。
     * 这里有一个示例AI，它只会寻找第一个可下的位置进行落子。
     */
    struct Command preferedPos = findValidPos(board, me);

    return preferedPos;
}

void place(int x0, int y0, int x1, int y1, int cur_flag)
{
    int x_mid, y_mid;
    board[x0][y0] = EMPTY;
    board[x1][y1] = cur_flag;
    x_mid = (x0 + y0) / 2;
    y_mid = (y0 + y1) / 2; 
    if (x_mid != min(x0, x1)) {
        board[x_mid][y_mid] = 0;
    }
}

//.X.X.X.X
//X.X.X.X.
//.X.X.X.X
//........
//........
//O.O.O.O.
//.O.O.O.O
//O.O.O.O.
void start(int flag)
{
    memset(board, 0, sizeof(board));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 8; j += 2)
        {
            board[i][j + (i + 1) % 2] = WHITE;
        }
    }
    for (int i = 5; i < 8; i++)
    {
        for (int j = 0; j < 8; j += 2)
        {
            board[i][j + (i + 1) % 2] = BLACK;
        }
    }

    initAI(flag);
}

// void turn()
// {
//     // AI
//     struct Command command = aiTurn((const char(*)[BOARD_SIZE])board, me_flag);
//     place(command.x, command.y, command.option, me_flag);
//     printf("%d %d %d\n", command.x, command.y, command.option);
//     fflush(stdout);
// }

void end(int x)
{
}

/**
 * 你的代码结束
 */

void loop()
{
    //  freopen("../input", "r", stdin);
    char tag[10] = {0};
    char buffer[MAX_BYTE + 1] = {0};
    int x0, y0, x1, y1, step;
    OPTION option;
    while (TRUE)
    {
        memset(tag, 0, sizeof(tag));
        memset(buffer, 0, sizeof(buffer));
        scanf("%s", tag);
        if (strcmp(tag, START) == 0)
        {
            scanf("%d", &me_flag);
            other_flag = 3 - me_flag;
            start(me_flag);
            printf("OK\n");
            fflush(stdout);
        }
        else if (strcmp(tag, PLACE) == 0)
        {
            scanf("%d", &step);
            scanf("%d,%d", &x0, &y0);
            for (int i = 1; i < step; i++)
            {
                scanf("%d,%d", &x1, &y1);
                place(x0, y0, x1, y1, other_flag);
                x0 = x1;
                y0 = y1;
            }
        }
        // else if (strcmp(tag, TURN)  == 0)
        // {
        //     turn();
        // }
        // else if (strcmp(tag, END) == 0)
        // {
        //     scanf("%d", &x);
        //     end(x);
        // }
        //    printBoard();
    }
}

int main(int argc, char *argv[])
{
    loop();
    return 0;
}
