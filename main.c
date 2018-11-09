#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

// board
#define TANK1_UP 'w'
#define TANK1_DOWN 's'
#define TANK1_LEFT 'a'
#define TANK1_RIGHT 'd'

#define BULLET1_UP 'u'
#define BULLET1_DOWN 'k'
#define BULLET1_LEFT 'j'
#define BULLET1_RIGHT 'l'

#define TANK2_UP 'W'
#define TANK2_DOWN 'S'
#define TANK2_LEFT 'A'
#define TANK2_RIGHT 'D'

#define BULLET2_UP 'U'
#define BULLET2_DOWN 'K'
#define BULLET2_LEFT 'J'
#define BULLET2_RIGHT 'L'

#define EMPTY '.'
#define OBSTACLE '|'
#define GRASS '?'
#define FOOD1 '1'
#define FOOD9 '9'

// command
#define TURN_TO_UP  0
#define TURN_TO_DOWN 1
#define TURN_TO_LEFT 2
#define TURN_TO_RIGHT 3
#define MOVE 4
#define STOP 5
#define SHOT 6

// flags for two players
#define PLAYER_FLAG_1 1
#define PLAYER_FLAG_2 2

// OPTION
#define START "START"
#define ROUND "ROUND"
#define END "END"

// score
#define SCORE_KILL 4
#define SCORE_FOOD1 1
#define SCORE FOOD9 9

#define MAX_BOARD_SIZE 100
#define MAX_TANKS_TOTAL 10

struct Position {
  int x;
  int y;
};

int own_flag;
int board_size;
int bullet_v;
char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
int own_tanks_total;
struct Position own_tank_positions[MAX_TANKS_TOTAL];
int commands[MAX_TANKS_TOTAL];


/**
 * 你的代码开始的地方
 */

void AiStart() {

}

/**
 * 写入own_tanks_total个指令到commands中.
 */
void AiRound() {
  for (int i = 0; i < own_tanks_total; i++) {
    commands[i] = MOVE;
  }
}

void AiEnd() {

}

/**
 * 你的代码结束的地方
 */

void Start() {
  scanf("%d%d%d", &board_size, &own_flag, &bullet_v);
}

int IsOwnTank(char chr) {
  return (own_flag == PLAYER_FLAG_1 &&
          (chr == TANK1_UP || chr == TANK1_DOWN || chr == TANK1_LEFT || chr == TANK1_RIGHT)) ||
         (own_flag == PLAYER_FLAG_2 &&
          (chr == TANK2_UP || chr == TANK2_DOWN || chr == TANK2_LEFT || chr == TANK2_RIGHT));
}

void RoundStart() {
  own_tanks_total = 0;
  for (int i = 0; i < board_size; i++) {
    scanf("%s", board[i]);

    for (int j = 0; j < board_size; j++) {
      if (IsOwnTank(board[i][j])) {
        own_tanks_total++;
        own_tank_positions[i].x = i;
        own_tank_positions[i].y = j;
      }
    }
  }
}

void RoundEnd() {
  for (int i = 0; i < own_tanks_total; i++) {
    printf("%d%c", commands[i], i == own_tanks_total - 1 ? '\n' : ' ');
  }
}

void End() {
}

int main() {
  char option[10];

  while (TRUE) {
    scanf("%s", option);
    if (strstr(option, START)) {
      Start();
      printf("OK\n");
    } else if (strstr(option, ROUND)) {
      RoundStart();
      AiRound();
      RoundEnd();
    } else if (strstr(option, END)) {
      End();
      AiEnd();
    }
  }

  return 0;
}
