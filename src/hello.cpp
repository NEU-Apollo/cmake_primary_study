#include <cstdio>
#include <fmt/format.h>
#include "hello.h"

void hello()
{
  printf("Hello\n");
  fmt::print("World {}\n", 456);
}

