cmake_minimum_required(VERSION 3.4)
project(Library)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    include/GameLogic.h
    include/Player.h
    include/Ship.h
    include/Funnel.h
    include/Human.h
    include/HumanInterface.h
    include/Point.h
    include/CheckValidity.h
    include/Computer.h
    include/ComputerStrategy.h
    include/RandomStrategy.h
    include/GreedyStrategy.h
    include/OneFunnel.h
    include/TwoFunnel.h
    include/ThreeFunnel.h
    include/Grid.h
    include/Field.h
    include/CImg.h
    include/Display.h

    src/GameLogic.cpp
    src/Player.cpp
    src/Ship.cpp
    src/Human.cpp
    src/HumanInterface.cpp
    src/CheckValidity.cpp
    src/Computer.cpp
    src/ComputerStrategy.cpp
    src/RandomStrategy.cpp
    src/GreedyStrategy.cpp
    src/Point.cpp
    src/OneFunnel.cpp
    src/TwoFunnel.cpp
    src/ThreeFunnel.cpp
    src/Grid.cpp
    src/Field.cpp
    src/Funnel.cpp
    src/Display.cpp

)

add_library(Library ${SOURCE_FILES})

#add 'include' directory with header files from 'Library' project to paths
target_include_directories(Library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

#Unit Tests section

# Check if generating Visual Studio 14 2015 project
if(MSVC)
    if(NOT BOOST_ROOT)
        set(BOOST_ROOT "C:/local/boost_1_68_0")
    endif()
    set(Boost_INCLUDE_DIR "${BOOST_ROOT}")
    set(Boost_LIBRARY_DIR "${BOOST_ROOT}/stage/lib")
    set(Boost_USE_STATIC_LIBS ON)
    set(Boost_USE_MULTITHREADED ON)

    if(NOT EXISTS ${Boost_LIBRARY_DIR})
        message(WARNING "Boost library requires manual installation in Windows")
        message("1) Browse: https://sourceforge.net/projects/boost/files/boost-binaries/1.60.0/")
        message("2) Download: boost_1_60_0-msvc-14.0-32.exe")
        message("3) Install into default directory: C:\\local")
        message("")
        message(FATAL_ERROR "Boost libraries not found at ${Boost_LIBRARY_DIR}")
    endif()

    find_package(Boost COMPONENTS unit_test_framework REQUIRED)

    include_directories(${Boost_INCLUDE_DIR})
    link_directories(${Boost_LIBRARY_DIR})

else()
    find_package(Boost COMPONENTS unit_test_framework REQUIRED)
endif()

set(SOURCE_TEST_FILES
        test/master.cpp
	test/FieldTest.cpp
	test/GridTest.cpp

	test/OneFunnelTest.cpp
	test/TwoFunnelTest.cpp
	test/ThreeFunnelTest.cpp

	test/GameLogicTest.cpp
        )

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

add_executable (Test ${SOURCE_TEST_FILES})

target_link_libraries (Test
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

enable_testing()
add_test(LibraryTest Test)