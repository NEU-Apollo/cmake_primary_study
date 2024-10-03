#include "hello.h"
#include <fmt/format.h>

int main() {
    hello();
    world();
    fmt::print("Hello, World!\n");
    fmt::print("Hello, World! {}\n", 42);
    fmt::print("Hello, World! {}\n", MY_DEFINE_IN_CMAKE);
    fmt::print("My system name is {}\n", MY_SYSTEM_NAME);
    fmt::print("My compiler name is {}\n", MY_COMPILER_ID);
}