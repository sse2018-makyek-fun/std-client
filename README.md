# std-client

提交到测试平台的代码模板。

只能修改如下区间中的代码

```c
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
```

