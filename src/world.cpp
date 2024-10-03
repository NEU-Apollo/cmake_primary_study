#include <cstdio>
#include <fmt/format.h>
#include "hello.h"

void world() {
  printf("World\n");
  fmt::print("World {}\n",123);
}