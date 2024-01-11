#include "Add.h"
#include <iostream>

Add::Add(const std::string& x, const std::string& y) : x(x), y(y) {}

void Add::execute(std::unordered_map<std::string, std::variant<int, LinkedList*>>& data_memory, int& pc, bool& isRunning) {
    auto var1 = data_memory.find(x);

    if (var1 != data_memory.end() && std::holds_alternative<int>(var1->second)) {
        int valueToAdd = 0;
        auto var2 = data_memory.find(y);
        if (var2 != data_memory.end() && std::holds_alternative<int>(var2->second)) {
            valueToAdd = std::get<int>(var2->second);
        } else {
                valueToAdd = std::stoi(y);
        }
        var1->second = std::get<int>(var1->second) + valueToAdd;
    }

    ++pc;
}

