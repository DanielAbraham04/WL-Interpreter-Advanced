#ifndef MP4_SET_H
#define MP4_SET_H

#include "Instruction.h"
#include <string>
#include <unordered_map>
#include <variant>

class LinkedList; // Forward declaration

class Set : public Instruction {
private:
    std::variant<int, std::string> x;
    int index;
    std::string listName;

public:
    Set(const std::variant<int, std::string>& x, int index, const std::string& listName);
    virtual void execute(std::unordered_map<std::string, std::variant<int, LinkedList*>>& data_memory, int& pc, bool& isRunning) override;
};

#endif //MP4_SET_H
