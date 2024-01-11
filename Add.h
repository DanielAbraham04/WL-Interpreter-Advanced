#ifndef MP4_ADD_H
#define MP4_ADD_H

#include "Instruction.h"

class Add : public Instruction {
private:
    std::string x;
    std::string y;

public:
    Add(const std::string& x, const std::string& y);
    virtual void execute(std::unordered_map<std::string, std::variant<int, LinkedList*>>& data_memory, int& pc, bool& isRunning) override;
};

#endif //MP4_ADD_H
