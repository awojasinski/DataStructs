include_directories("${PROJECT_SOURCE_DIR}/inc")

file(GLOB sources "${PROJECT_SOURCE_DIR}/src/*.c")
list(REMOVE_ITEM sources "${PROJECT_SOURCE_DIR}/src/main.c")

file(GLOB tests "${PROJECT_SOURCE_DIR}/test/*.cpp")
list(REMOVE_ITEM tests "${PROJECT_SOURCE_DIR}/test/main.cpp")

SET(CMAKE_CXX_FLAGS "-coverage -fprofile-arcs -ftest-coverage")
SET(CMAKE_C_FLAGS "-coverage -fprofile-arcs -ftest-coverage")
SET(CMAKE_EXE_LINKER_FLAGS    "-coverage -lgcov")

foreach(file ${tests})
  set(name)
  get_filename_component(name ${file} NAME_WE)
  add_executable("${name}_tests"
    ${sources}
    ${file}
    "${PROJECT_SOURCE_DIR}/test/main.cpp")
  target_link_libraries("${name}_tests" gtest_main)
  add_test(NAME ${name} COMMAND "${name}_tests")
endforeach()
