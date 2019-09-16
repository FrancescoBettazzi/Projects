cmake_minimum_required(VERSION 3.14)
project(LaboratoryExercise)

set(CMAKE_CXX_STANDARD 14)

add_executable(LaboratoryExercise main.cpp Observer.h Subject.h Message.h Chat.cpp Chat.h User.h Schedule.h MessageNotifier.cpp MessageNotifier.h IconBadgeMonitor.cpp IconBadgeMonitor.h)
add_library(core ${SOURCE_FILES} Test/runAllTests.cpp Test/testChat.cpp Test/testMessage.cpp)
target_link_libraries(LaboratoryExercise core)