CMAKE_MINIMUM_REQUIRED(VERSION 3.16)

set(srcfiles
    "main"
    "program"
)

set(srcfile "")
foreach(target_sourcefile IN LISTS srcfiles)
    set(srcfile ${srcfile} "${CMAKE_CURRENT_SOURCE_DIR}/src/${target_sourcefile}.c")
endforeach(target_sourcefile IN LISTS srcfiles)

project(FileCompare)
add_executable(${PROJECT_NAME} ${srcfile})
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")