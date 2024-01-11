#ifndef MP4_VARINT_H
#define MP4_VARINT_H

#include "Instruction.h"

class VarInt : public Instruction {
private:
    std::string x;
    std::variant<int, std::string> value;

public:
    VarInt(const std::string& x, const std::variant<int, std::string>& val);
    virtual void execute(std::unordered_map<std::string, std::variant<int, LinkedList*>>& data_memory, int& pc, bool& isRunning) override;
};

#endif //MP4_VARINT_H
