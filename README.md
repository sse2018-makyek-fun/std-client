# std-client

提交到测试平台的代码模板。

只能修改如下区间中的代码

```c
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
void initAI(int me) {

}

struct Command findValidPos(const char board[BOARD_SIZE][BOARD_SIZE], int flag) {
  struct Command command = {0, 0, 0};
  for (int k = 0; k < 4; k++) {
    const int* delta = DIR[k];
    for (int x = 0; x < BOARD_SIZE; x++) {
      for (int y = 0; y < BOARD_SIZE; y++) {
        if (board[x][y] != flag) {
          continue;
        }
        int new_x = x + delta[0];
        int new_y = y + delta[1];
        if (is_in_bound(new_x, new_y) && board[new_x][new_y] == EMPTY) {
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
struct Command aiTurn(const char board[BOARD_SIZE][BOARD_SIZE], int me) {
  /*
   * TODO：在这里写下你的AI。
   * 这里有一个示例AI，它只会寻找第一个可下的位置进行落子。
   */
  struct Command preferedPos = findValidPos(board, me);

  return preferedPos;
}

/**
 * 你的代码结束
 */
```

### 规则

- 初始化：棋盘为8 * 8，黑白两方的棋子各16个，各占据上下的第一行和第三行。
- 每回合：
  - 黑棋先行
  - 如果走完这一步，造成夹或者挑，把对应的敌方棋子变为我方棋子。