PROJECT(main)

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
FIND_PACKAGE(Threads)
FIND_PACKAGE(X11 REQUIRED)

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c++11 -march=native")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -march=native")

INCLUDE_DIRECTORIES(${X11_INLUCDE_DIR})

ADD_EXECUTABLE(main /home/liuup/Desktop/cpp_test/main.cpp

                    /home/liuup/Desktop/cpp_test/Huffman.cpp
                    /home/liuup/Desktop/cpp_test/Huffman.h
        )

TARGET_LINK_LIBRARIES(main ${CMAKE_THREAD_LIBS_INIT})
TARGET_LINK_LIBRARIES(main ${X11_LIBRARIES})
