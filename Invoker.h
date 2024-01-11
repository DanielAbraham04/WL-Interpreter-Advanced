#ifndef MP4_INVOKER_H
#define MP4_INVOKER_H

#include "Instruction.h"
#include <vector>
#include <memory>

class Invoker {
private:
    std::vector<std::unique_ptr<Instruction>> instructions;
    std::unordered_map<std::string, std::variant<int, LinkedList*>> data_memory;
    int pc;
    bool isRunning;
    void printDataMemoryAndPC();

public:
    Invoker();
    void loadInstructions(const std::string& filename);
    bool executeSingle();
    void executeAll();
    void run();
};

#endif //MP4_INVOKER_H
