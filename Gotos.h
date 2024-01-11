#ifndef MP4_GOTOS_H
#define MP4_GOTOS_H

#include "Instruction.h"

class Gotos : public Instruction {
private:
    int value;

public:
    Gotos(int val);
    virtual void execute(std::unordered_map<std::string, std::variant<int, LinkedList*>>& data_memory, int& pc, bool& isRunning) override;
};

#endif //MP4_GOTOS_H
