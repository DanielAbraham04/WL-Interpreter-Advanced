#include "Chs.h"

Chs::Chs(const std::string& x) : x(x) {}

void Chs::execute(std::unordered_map<std::string, std::variant<int, LinkedList*>>& data_memory, int& pc, bool& isRunning) {
    auto it = data_memory.find(x);
    if (it != data_memory.end()) {
        if (std::holds_alternative<int>(it->second)) {
            it->second = -std::get<int>(it->second);
        }
    }
    ++pc;
}