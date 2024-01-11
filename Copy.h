#ifndef MP4_COPY_H
#define MP4_COPY_H
#include "Instruction.h"

class Copy : public Instruction {
private:
    std::string source;
    std::string destination;

public:
    Copy(const std::string& source, const std::string& destination);
    virtual void execute(std::unordered_map<std::string, std::variant<int, LinkedList*>>& data_memory, int& pc, bool& isRunning) override;
};
#endif //MP4_COPY_H
