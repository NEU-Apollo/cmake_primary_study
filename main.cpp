#include "hello.h"
#include <fmt/format.h>

int main() {
    hello();
    fmt::print("Hello, World!\n");
    fmt::print("Hello, World! {}\n", 42);
}