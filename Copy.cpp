#include "Copy.h"
#include "LinkedList.h"
#include <stdexcept>

Copy::Copy(const std::string& source, const std::string& destination)
        : source(source), destination(destination) {}

void Copy::execute(std::unordered_map<std::string, std::variant<int, LinkedList*>>& data_memory, int& pc, bool& isRunning) {
    auto srcIt = data_memory.find(source);
    auto destIt = data_memory.find(destination);

    if (srcIt != data_memory.end() && std::holds_alternative<LinkedList*>(srcIt->second)) {
        LinkedList* srcList = std::get<LinkedList*>(srcIt->second);

        // Check if the source list is not nullptr and perform a deep copy
        if (srcList != nullptr) {
            if (destIt != data_memory.end() && std::holds_alternative<LinkedList*>(destIt->second)) {
                // Delete the existing destination list to prevent memory leaks
                delete std::get<LinkedList*>(destIt->second);
            }
            // Assign the deep copied list to the destination
            data_memory[destination] = new LinkedList(*srcList);
        } else {
            // If the source list is nullptr, set the destination list to nullptr
            if (destIt != data_memory.end() && std::holds_alternative<LinkedList*>(destIt->second)) {
                delete std::get<LinkedList*>(destIt->second);
            }
            data_memory[destination] = nullptr;
        }
    }
    ++pc;
}
