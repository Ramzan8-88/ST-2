# Подключаем Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(${PROJECT_NAME}.test
  tests.cpp)  # Убираем AllTests.cpp, если он не нужен

target_link_libraries(${PROJECT_NAME}.test
  ${PROJECT_NAME} 
  GTest::gtest 
  GTest::gtest_main
  pthread)

target_include_directories(${PROJECT_NAME}.test PRIVATE
  ${${PROJECT_NAME}_SOURCE_DIR}/include)

target_compile_definitions(${PROJECT_NAME}.test 
  PRIVATE TEST_DIR="${CMAKE_CURRENT_LIST_DIR}")

# Добавляем тесты
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}.test)

install(TARGETS ${PROJECT_NAME}.test
        RUNTIME DESTINATION "${tool_dest}")