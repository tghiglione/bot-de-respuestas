project(HertaTest)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/9d43b27f7a873596496a2ea70721b3f9eb82df01.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

add_executable(HertaTest
        HertaTest.cpp
)

target_link_libraries(
        HertaTest
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(HertaTest)