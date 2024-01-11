#include "Gotos.h"

Gotos::Gotos(int val) : value(val) {}

void Gotos::execute(std::unordered_map<std::string, std::variant<int, LinkedList*>>& data_memory, int& pc, bool& isRunning) {
    pc=value;
}
