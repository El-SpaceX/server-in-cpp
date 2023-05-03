cmake_minimum_required (VERSION 3.8)

project ("Client")

add_executable (Client "Client.cpp" "Client.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Client PROPERTY CXX_STANDARD 20)
endif()
