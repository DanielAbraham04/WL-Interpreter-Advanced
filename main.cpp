#include "Invoker.h"

int main() {
    Invoker invoker;
    invoker.loadInstructions("/Users/danielabraham/CLionProjects/mp4/input.wl");
    invoker.run();
    return 0;
}
