#ifndef MP4_HLT_H
#define MP4_HLT_H
#include "Instruction.h"

class Hlt : public Instruction {
public:
    virtual void execute(std::unordered_map<std::string, std::variant<int, LinkedList*>>& data_memory, int& pc, bool& isRunning) override;
};

#endif //MP4_HLT_H
