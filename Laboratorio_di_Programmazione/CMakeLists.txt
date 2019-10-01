cmake_minimum_required(VERSION 3.14)
project(Laboratorio_di_Programmazione)

set(CMAKE_CXX_STANDARD 14)

add_executable(Laboratorio_di_Programmazione main.cpp Chat.cpp Chat.h IconBadgeMonitor.cpp IconBadgeMonitor.h Message.h MessageNotifier.cpp MessageNotifier.h Observer.h Schedule.h Subject.h User.h)



add_subdirectory(test)

set(SOURCE_FILES ./test/runAllTests.cpp test/TestChat.cpp test/TestMessage.cpp test/TestUser.cpp Chat.cpp IconBadgeMonitor.cpp MessageNotifier.cpp)
add_executable(lab main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(lab core)