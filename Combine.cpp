#include "Combine.h"
#include "LinkedList.h"

Combine::Combine(const std::string& list1, const std::string& list2)
        : list1(list1), list2(list2) {}

void Combine::execute(std::unordered_map<std::string, std::variant<int, LinkedList*>>& data_memory, int& pc, bool& isRunning) {
    auto it1 = data_memory.find(list1);
    auto it2 = data_memory.find(list2);

    if (it1 != data_memory.end() && it2 != data_memory.end() &&
        std::holds_alternative<LinkedList*>(it1->second) &&
        std::holds_alternative<LinkedList*>(it2->second)) {

        LinkedList* list1Ptr = std::get<LinkedList*>(it1->second);
        LinkedList* list2Ptr = std::get<LinkedList*>(it2->second);

        if (list1Ptr != nullptr && list2Ptr != nullptr) {
            list2Ptr->appendList(*list1Ptr, *list2Ptr);
        }
    }
    ++pc;
}
