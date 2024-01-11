#ifndef MP4_VARLIST_H
#define MP4_VARLIST_H

#include "Instruction.h"
#include <vector>
#include <string>

class VarList : public Instruction {
private:
    std::string variableName;
    std::vector<std::variant<int, std::string>> elements;

public:
    VarList(const std::string& varName, const std::vector<std::variant<int, std::string>>& els);
    virtual void execute(std::unordered_map<std::string, std::variant<int, LinkedList*>>& data_memory, int& pc, bool& isRunning) override;
};

#endif //MP4_VARLIST_H
