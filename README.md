# std-client

提交到测试平台的代码模板。

你可以只修改如下区间中的代码

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
void initAI(int me)
{
}

/**
 * 轮到你落子。
 * 棋盘上0表示空白，1表示黑棋，2表示白旗
 * me表示你所代表的棋子(1或2)
 * 你需要返回一个结构体Command，其中numStep是你要移动的棋子经过的格子数（含起点、终点），
 * x、y分别是该棋子依次经过的每个格子的横、纵坐标
 */
struct Command aiTurn(const char board[BOARD_SIZE][BOARD_SIZE], int me)
{
    /*
     * TODO：在这里写下你的AI。
     */
    struct Command command = {
        .x = {0},
        .y = {0},
        .numStep = 0};
    return command;
}

/**
 * 你的代码结束
 */
```

### 规则

- 规则详见[项目相关](https://github.com/sse2018-makyek-fun/about)