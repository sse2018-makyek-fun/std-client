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

#define BULLET1_UP '1'
#define BULLET1_DOWN '2'
#define BULLET1_LEFT '3'
#define BULLET1_RIGHT '4'

#define TANK2_UP 'i'
#define TANK2_DOWN 'k'
#define TANK2_LEFT 'j'
#define TANK2_RIGHT 'l'

#define BULLET2_UP '7'
#define BULLET2_DOWN '8'
#define BULLET2_LEFT '9'
#define BULLET2_RIGHT '0'

#define EMPTY '.'
#define OBSTACLE '|'
#define GRASS '?'
#define FOOD1 'z'
#define FOOD3 'c'

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

struct Position {
  int x;
  int y;
};

int own_flag;
int board_size;
int bullet_v;
char** board;
int own_tanks_total;
struct Position* own_tank_positions;
int* commands;


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
  scanf("%d%d%d%d", &board_size, &own_flag, &own_tanks_total, &bullet_v);
  own_tank_positions = (struct Position*) malloc(sizeof(struct Position) * own_tanks_total);

  board = (char **) malloc(sizeof(char *) * board_size);
  board[0] = (char *) malloc(sizeof(char) * board_size * board_size);
  for (int i = 1; i < board_size; i++) {
    board[i] = board[i - 1] + board_size;
  }

  commands = (int *) malloc(sizeof(int) * own_tanks_total);
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
  free(own_tank_positions);
  free(board[0]);
  free(board);
  free(commands);
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
