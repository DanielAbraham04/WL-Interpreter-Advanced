#include "Set.h"
#include "LinkedList.h"
#include <stdexcept>

Set::Set(const std::variant<int, std::string>& x, int index, const std::string& listName)
        : x(x), index(index), listName(listName) {}

void Set::execute(std::unordered_map<std::string, std::variant<int, LinkedList*>>& data_memory, int& pc, bool& isRunning) {
    auto listIt = data_memory.find(listName);

    if (listIt != data_memory.end() && std::holds_alternative<LinkedList*>(listIt->second)) {
        LinkedList* list = std::get<LinkedList*>(listIt->second);

        std::variant<int, LinkedList*> valueToSet;
        if (std::holds_alternative<int>(x)) {
            valueToSet = std::get<int>(x);
        } else if (std::holds_alternative<std::string>(x)) {
            std::string varName = std::get<std::string>(x);
            auto varIt = data_memory.find(varName);
            if (varIt != data_memory.end()) {
                valueToSet = varIt->second;
            }
        }
        if (list != nullptr) {
            list->setElementAt(index, valueToSet);
        }
    }
    ++pc;
}
