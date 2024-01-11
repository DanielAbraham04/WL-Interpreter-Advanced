#include "VarInt.h"

VarInt::VarInt(const std::string& x, const std::variant<int, std::string>& val) : x(x), value(val) {}

void VarInt::execute(std::unordered_map<std::string, std::variant<int, LinkedList*>>& data_memory, int& pc, bool& isRunning) {
    if (std::holds_alternative<int>(value)) {
        data_memory[x] = std::get<int>(value);
    } else {
        std::string varName = std::get<std::string>(value);
        auto varIt = data_memory.find(varName);
        if (varIt != data_memory.end() && std::holds_alternative<int>(varIt->second)) {
            data_memory[x] = std::get<int>(varIt->second);
        }
    }
    ++pc;
}
