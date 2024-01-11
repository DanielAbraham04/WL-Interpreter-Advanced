#include "VarList.h"
#include <sstream>
#include <iostream>

VarList::VarList(const std::string& varName, const std::vector<std::variant<int, std::string>>& els)
        : variableName(varName), elements(els) {}

void VarList::execute(std::unordered_map<std::string, std::variant<int, LinkedList*>>& data_memory, int& pc, bool& isRunning) {
    LinkedList* list = new LinkedList();

    for (const auto& el : elements) {
        if (std::holds_alternative<int>(el)) {
            list->append(std::get<int>(el));
        } else {
            const std::string& varName = std::get<std::string>(el);
            if (data_memory.find(varName) != data_memory.end()) {
                std::variant<int, LinkedList*>& var = data_memory[varName];
                if (std::holds_alternative<int>(var)) {
                    list->append(std::get<int>(var));
                } else if (std::holds_alternative<LinkedList*>(var)) {
                    // Shallow copy: append the pointer to the existing list
                    list->append(std::get<LinkedList*>(var));
                }
            }
        }
    }

    auto& existingEntry = data_memory[variableName];
//    if (std::holds_alternative<LinkedList*>(existingEntry)) {
//        // If there's an existing list, we don't delete it since we are doing shallow copies
//    }
    existingEntry = list;
    ++pc;
}

