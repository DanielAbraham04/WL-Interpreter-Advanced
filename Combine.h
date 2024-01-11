#ifndef MP4_COMBINE_H
#define MP4_COMBINE_H

#include "Instruction.h"

class LinkedList; // Forward declaration

class Combine : public Instruction {
private:
    std::string list1;
    std::string list2;

public:
    Combine(const std::string& list1, const std::string& list2);
    virtual void execute(std::unordered_map<std::string, std::variant<int, LinkedList*>>& data_memory, int& pc, bool& isRunning) override;
};

#endif //MP4_COMBINE_H
