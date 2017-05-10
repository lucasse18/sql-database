cmake_minimum_required(VERSION 3.7.2)
project(sql_database)

include_directories(include)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -O2 -pipe")

set(HEADER_FILES
  include/core/disk_manager.h
  include/core/buffer_manager.h
  include/core/file_manager.h
  include/util/debug.h
)

set(SOURCE_FILES
  src/main.c
  src/core/buffer_manager.c)

add_executable(sql_db ${SOURCE_FILES})
