cmake_minimum_required(VERSION 3.16)

project(BinaryDB LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(absl REQUIRED)
find_package(Boost REQUIRED COMPONENTS system thread)
find_package(Protobuf REQUIRED)

include_directories(
    ${Boost_INCLUDE_DIRS}
    ${Protobuf_INCLUDE_DIRS}

)

add_executable(BinaryDB main.cpp
    server.hpp
    server.cpp
    storage.hpp
    storage.cpp
    proto/db.pb.cc
    proto/db.pb.h
)
target_link_libraries(BinaryDB
    ${Boost_LIBRARIES}
    ${Protobuf_LIBRARIES}
    absl::log_internal_check_op
    absl::strings
    absl::base
)

include(GNUInstallDirs)
install(TARGETS BinaryDB
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
