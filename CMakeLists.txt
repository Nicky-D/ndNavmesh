cmake_minimum_required(VERSION 3.21.0)

set( CMAKE_PROJECT_NAME ndNavmesh )
set( CMAKE_CXX_STANDARD 14 )
project(ndNavmesh CXX C)

set( ND_LIBDIR "lib/release")

if( MSVC )
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_SCL_SECURE_NO_WARNINGS=1" )
  set(CMAKE_CXX_FLAGS_RELWITHDEBINFO  "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -D_SECURE_STL=0" )
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -D_SECURE_STL=0 -D_HAS_ITERATOR_DEBUGGING=0 -D_SECURE_SCL=0" )
  add_definitions( "/Oy-" )
endif( MSVC )

file (GLOB SOURCE_FILES ndPathinglib.cpp ndPhysicsextensions.cpp)
file (GLOB INCLUDE_FILES ndPathinglib.h ndPhysicsextensions.h)

add_library(ndNavmesh STATIC ${SOURCE_FILES} ${INCLUDE_FILES} )

install( TARGETS ndNavmesh DESTINATION ${ND_LIBDIR} )
install( FILES ${INCLUDE_FILES} DESTINATION include/ )
