#ifndef MP4_CHS_H
#define MP4_CHS_H

#include "Instruction.h"

class Chs : public Instruction {
private:
    std::string x;

public:
    Chs(const std::string& x);
    virtual void execute(std::unordered_map<std::string, std::variant<int, LinkedList*>>& data_memory, int& pc, bool& isRunning) override;
};

#endif //MP4_CHS_H
