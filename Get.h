#ifndef MP4_GET_H
#define MP4_GET_H
#include "Instruction.h"

class Get : public Instruction {
private:
    std::string x;
    std::string listName;
    std::variant<int, std::string> index;

public:
    Get(const std::string& x, const std::variant<int, std::string>& index, const std::string& listName);
    virtual void execute(std::unordered_map<std::string, std::variant<int, LinkedList*>>& data_memory, int& pc, bool& isRunning) override;
};
#endif //MP4_GET_H
