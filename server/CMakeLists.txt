cmake_minimum_required (VERSION 3.8)

project ("server")

add_executable (server "server.cpp" "server.h" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET server PROPERTY CXX_STANDARD 20)
endif()
