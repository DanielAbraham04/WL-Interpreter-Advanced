#ifndef MP4_INSTRUCTION_H
#define MP4_INSTRUCTION_H

#include <unordered_map>
#include <string>
#include <variant>
#include "LinkedList.h"

class Instruction {
public:
    virtual ~Instruction() {}
    virtual void execute(std::unordered_map<std::string, std::variant<int, LinkedList*>>& data_memory, int& pc, bool& isRunning) = 0;
};

#endif //MP4_INSTRUCTION_H
