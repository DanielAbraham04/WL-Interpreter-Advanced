#ifndef MP4_IFS_H
#define MP4_IFS_H
#include "Instruction.h"

class Ifs : public Instruction {
private:
    std::string x;
    int value;

public:
    Ifs(const std::string& x, int val);
    virtual void execute(std::unordered_map<std::string, std::variant<int, LinkedList*>>& data_memory, int& pc, bool& isRunning) override;
};

#endif //MP4_IFS_H
