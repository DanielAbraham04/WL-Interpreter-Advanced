#include "Ifs.h"
#include <iostream>

Ifs::Ifs(const std::string& x, int val) : x(x), value(val) {}

void Ifs::execute(std::unordered_map<std::string, std::variant<int, LinkedList*>>& data_memory, int& pc, bool& isRunning) {
    //std::cout << "value:" << value << std::endl;
    if (data_memory.find(x) != data_memory.end()) {
        std::variant<int, LinkedList*>& var = data_memory[x];
        if (std::holds_alternative<int>(var) && std::get<int>(var) == 0) {
            pc = value;
        } else if (std::holds_alternative<LinkedList*>(var)) {
            LinkedList* list = std::get<LinkedList*>(var);
            if (list == nullptr || list->isEmpty()) { // Check if the list is null or empty
                pc = value; // Jump if x is an empty list
            }
            else
                ++pc;
        }
        else
            ++pc;
    }
}
