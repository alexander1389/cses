cmake_minimum_required(VERSION 3.10)
project(CSES-Solutions CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB PROBLEM_DIRS "src/*/*")

foreach(PROBLEM_DIR ${PROBLEM_DIRS})
    get_filename_component(PROBLEM_NAME ${PROBLEM_DIR} NAME)
    get_filename_component(SECTION_NAME ${PROBLEM_DIR} DIRECTORY)
    get_filename_component(SECTION_NAME ${SECTION_NAME} NAME)

    set(EXEC_NAME "${SECTION_NAME}-${PROBLEM_NAME}")
    add_executable(${EXEC_NAME} "${PROBLEM_DIR}/solution.cpp")

    if(EXISTS "${PROBLEM_DIR}/tests/")
        add_test(NAME ${EXEC_NAME} COMMAND ${EXEC_NAME})
    endif()

endforeach()
