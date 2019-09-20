add_subdirectory(./lib/googletest-master)
set(gtest_SOURCE_DIR, ./lib/googletest-master/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp TestChat.cpp TestMessage.cpp)
add_executable(runLaboratorio_di_Programmazione ${TEST_SOURCE_FILES})
target_link_libraries(runLaboratorio_di_Programmazione gtest gtest_main core)