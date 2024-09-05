if(WIN32)
    cmake_minimum_required(VERSION 3.28)
elseif(UNIX)
    cmake_minimum_required(VERSION 3.22)
else()
    cmake_minimum_required(VERSION 3.10)
endif()

project(croplat)


if(APPLE)
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED True)
endif()


if(APPLE)
elseif(UNIX)
    find_package(X11 REQUIRED)

    message(STATUS "X11_FOUND = ${X11_FOUND}")
    message(STATUS "X11_INCLUDE_DIR = ${X11_INCLUDE_DIR}")
    message(STATUS "X11_LIBRARIES = ${X11_LIBRARIES}")

    include_directories(${X11_INCLUDE_DIR})

    link_directories(${X11_LIBRARIES})
endif()


set(SOURCE_FILES
   ${SOURCE_FILES}
   ${CMAKE_CURRENT_SOURCE_DIR}/devDuckCmd.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/MainNetwork.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/mainProcess.cpp
)


if(WIN32)
    add_definitions( -D_UNICODE -DUNICODE )
endif()


add_executable(croplat ${SOURCE_FILES})


target_link_libraries(croplat ${X11_LIBRARIES})


if(APPLE)
    # macOS specific frameworks
    find_library(CORE_FOUNDATION_FRAMEWORK CoreFoundation)
    find_library(CARBON_FRAMEWORK Carbon)

    # Check if the frameworks were found and link them
    if(NOT CORE_FOUNDATION_FRAMEWORK)
        message(FATAL_ERROR "CoreFoundation framework not found")
    endif()

    if(NOT CARBON_FRAMEWORK)
        message(FATAL_ERROR "Carbon framework not found")
    endif()

    # Link the frameworks to the target
    target_link_libraries(croplat "${CORE_FOUNDATION_FRAMEWORK}")
    target_link_libraries(croplat "${CARBON_FRAMEWORK}")
endif()


###############################################################################
## defines ####################################################################
###############################################################################


# Check compiler flags
message(STATUS "### Check Compiler Flags ####")
if(MSVC)
    message(STATUS "MSVC Detected")
else()
    message(STATUS "MSVC Not Detected")
endif()

# Check operating system 
if(WIN32)
    if(CMAKE_SIZEOF_VOID_P EQUAL 4)
        message(STATUS "Configuring for 32-bit Windows")
    elseif(CMAKE_SIZEOF_VOID_P EQUAL 8)
        message(STATUS "Configuring for 64-bit Windows")
    else()
        message(WARNING "Unknown architecture")
    endif()
elseif(APPLE)
    message(STATUS "Configuring for macOS")
elseif(UNIX AND NOT APPLE)
    message(STATUS "Configuring for Linux")
else()
    message(STATUS "Unknown architecture")
endif()
