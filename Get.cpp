#include "Get.h"
#include "LinkedList.h"
#include <stdexcept>
#include <variant>
#include <iostream>

Get::Get(const std::string& x, const std::variant<int, std::string>& index, const std::string& listName)
        : x(x), index(index), listName(listName) {}

void Get::execute(std::unordered_map<std::string, std::variant<int, LinkedList*>>& data_memory, int& pc, bool& isRunning) {
    auto listIt = data_memory.find(listName);

    if (listIt != data_memory.end() && std::holds_alternative<LinkedList*>(listIt->second)) {
        LinkedList* list = std::get<LinkedList*>(listIt->second);

        int realIndex = 0;
        if (std::holds_alternative<int>(index)) {
            realIndex = std::get<int>(index);
        } else {
            std::string indexVar = std::get<std::string>(index);
            auto indexIt = data_memory.find(indexVar);
            if (indexIt != data_memory.end() && std::holds_alternative<int>(indexIt->second)) {
                realIndex = std::get<int>(indexIt->second);
            }
        }
        //std::cout << "real index : " << realIndex << std::endl;
        if (list != nullptr) {
            std::variant<int, LinkedList*> element = list->getElementAt(realIndex);
            data_memory[x] = element;
        }
    }
    ++pc;
}
