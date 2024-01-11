#include <fstream>
#include <sstream>
#include <iostream>
#include <memory>
#include <regex>
#include "Invoker.h"
#include "VarInt.h"
#include "VarList.h"
#include "Chs.h"
#include "Add.h"
#include "Ifs.h"
#include "Gotos.h"
#include "Hlt.h"
#include "Copy.h"
#include "Combine.h"
#include "Get.h"
#include "Set.h"

std::regex varint_pattern("VARINT (\\w+) (-?\\d+|\\w+)");
std::regex varlist_pattern("VARLIST (\\w+)(?: (\\w+(?:\\s*,\\s*\\w+)*))?");
std::regex combine_pattern("COMBINE (\\w+) (\\w+)");
std::regex get_pattern("GET (\\w+) (\\d+|\\w+) (\\w+)");
std::regex add_pattern("ADD (\\w+) (-?\\d+|\\w+)");
std::regex set_pattern("SET (-?\\d+|\\w+) (\\d+) (\\w+)");
std::regex copy_pattern("COPY (\\w+) (\\w+)");
std::regex chs_pattern("CHS (\\w+)");
std::regex if_pattern("IF (\\w+) (\\d+)");
std::regex goto_pattern("GOTO (\\d+)");

Invoker::Invoker() : pc(0),isRunning(true) {}

void Invoker::loadInstructions(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    std::smatch matches;

    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string instructionType;
        iss >> instructionType;

        if (std::regex_match(line, matches, varint_pattern)) {
            std::string varName = matches[1];
            std::string value = matches[2];
            std::variant<int, std::string> index;
            try {
                int indexInt = std::stoi(value);
                index = indexInt;
            } catch (const std::invalid_argument&) {
                index = value;
            }
            instructions.push_back(std::make_unique<VarInt>(varName, index));
        } else if (std::regex_match(line, matches, varlist_pattern)) {
            std::string varName = matches[1];
            std::string elementsStr = matches[2];

            std::vector<std::variant<int, std::string>> elements;
            std::stringstream ss(elementsStr);
            std::string item;
            while (getline(ss, item, ',')) {
                if (!item.empty()) {
                    std::istringstream elementStream(item);
                    int intValue;
                    if (elementStream >> intValue) {
                        elements.push_back(intValue);
                    } else {
                        elements.push_back(item);
                    }
                }
            }
            instructions.push_back(std::make_unique<VarList>(varName, elements));
        } else if (std::regex_match(line, matches, chs_pattern)) {
            std::string varName = matches[1];
            instructions.push_back(std::make_unique<Chs>(varName));
        } else if (std::regex_match(line, matches, add_pattern)) {
            std::string x = matches[1];
            std::string y = matches[2];
            instructions.push_back(std::make_unique<Add>(x,y));
        } else if (std::regex_match(line, matches, if_pattern)) {
            std::string varName = matches[1];
            int value = std::stoi(matches[2]);
            instructions.push_back(std::make_unique<Ifs>(varName, value));
        } else if (std::regex_match(line, matches, goto_pattern)) {
            int value = std::stoi(matches[1]);
            instructions.push_back(std::make_unique<Gotos>(value));
        } else if (std::regex_match(line, matches, copy_pattern)) {
            std::string x = matches[1];
            std::string y = matches[2];
            instructions.push_back(std::make_unique<Copy>(y,x));
        } else if (std::regex_match(line, matches, combine_pattern)) {
            std::string x = matches[1];
            std::string y = matches[2];
            instructions.push_back(std::make_unique<Combine>(x,y));
        } else if (std::regex_match(line, matches, get_pattern)) {
            std::string x = matches[1];
            std::string y = matches[2];
            std::string z = matches[3];
            std::variant<int, std::string> index;
            try {
                int indexInt = std::stoi(y);
                index = indexInt;
            } catch (const std::invalid_argument&) {
                index = y;
            }
            instructions.push_back(std::make_unique<Get>(x, index, z));
        } else if (std::regex_match(line, matches, set_pattern)) {
            std::string x = matches[1];
            int y = std::stoi(matches[2]);
            std::string z = matches[3];
            std::variant<int, std::string> index;
            try {
                int indexInt = std::stoi(x);
                index = indexInt;
            } catch (const std::invalid_argument&) {
                index = x;
            }
            instructions.push_back(std::make_unique<Set>(index,y,z));
        }
        else if (instructionType == "HLT") {
            instructions.push_back(std::make_unique<Hlt>());
        }
        else {
            std::cout << "Unknown instruction " << instructionType << std::endl;
        }
    }
}

bool Invoker::executeSingle() {
    if (!isRunning)
        return false;
    if (pc < instructions.size()) {
        instructions[pc]->execute(data_memory, pc, isRunning);
        if (!isRunning)
            return false;
    }
    if (pc < instructions.size())
        return true;
    else
        return false;
}

void Invoker::executeAll() {
    bool running = true;
    while (running) {
        running=executeSingle();
    }
}

void Invoker::run() {
    char command;
    bool running=true;
    while (running) {
        std::cout << "Enter command (o, a, q): ";
        std::cin >> command;
        if (command == 'o') {
            running = executeSingle();
            printDataMemoryAndPC();
        } else if (command == 'a') {
            executeAll();
            printDataMemoryAndPC();
            running = false;
        } else if (command == 'q') {
            break;
        }
    }
}

void Invoker::printDataMemoryAndPC() {
    std::cout << "Data Memory: \n";
    for (const auto& pair : data_memory) {
        std::cout << pair.first << ": ";
        if (std::holds_alternative<int>(pair.second)) {
            std::cout << std::get<int>(pair.second);
        } else {
            LinkedList* list = std::get<LinkedList*>(pair.second);
            if (list != nullptr) {
                list->print();
            } else {
                std::cout << "null";
            }
        }
        std::cout << "\n";
    }
    std::cout << "Program Counter: " << pc << "\n\n";
}