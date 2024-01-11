cmake_minimum_required(VERSION 3.26)
project(mp4)

set(CMAKE_CXX_STANDARD 17)

add_executable(mp4 main.cpp
        Instruction.h
        Instruction.cpp
        Node.h
        Node.cpp
        LinkedList.h
        LinkedList.cpp
        VarInt.h
        VarInt.cpp
        VarList.h
        VarList.cpp
        Invoker.h
        Invoker.cpp
        Chs.h
        Chs.cpp
        Add.h
        Add.cpp
        Ifs.h
        Ifs.cpp
        Gotos.h
        Gotos.cpp
        Hlt.h
        Hlt.cpp
        Copy.cpp
        Copy.h
        Combine.h
        Combine.cpp
        Get.h
        Get.cpp
        Set.h
        Set.cpp
)
