//
// Created by EDY on 2022/12/25.
//

#include <stdio.h>

#define crBegin                                                                \
  static int _cr_state = 0;                                                    \
  switch (_cr_state) {                                                         \
  case 0:
#define crReturn(x)                                                            \
  do {                                                                         \
    _cr_state = __LINE__;                                                      \
    return x;                                                                  \
  case __LINE__:;                                                              \
  } while (0)
#define crFinish }

int func1() {
  crBegin while (1) {
    printf("hello world\n");
    crReturn(0);
  }
  crFinish
}

int main() {
  func1();
  return 0;
}
