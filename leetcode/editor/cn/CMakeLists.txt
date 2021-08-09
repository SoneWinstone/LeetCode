cmake_minimum_required(VERSION 3.20)

project(LEETCODE)

message(status "START CMAKE ... Project Directory: ${PROJECT_SOURCE_DIR}")

#工程配置相关，需要根据实际情况进行调整
include_directories(${CMAKE_SOURCE_DIR}/include) #添加引用的头文件目录，这里是相对目录的形式
link_directories(${CMAKE_SOURCE_DIR}/library) #添加引用的库文件目录，这里是相对目录的形式
#add_subdirectory(${CMAKE_SOURCE_DIR}/util) #当需要构建大型工程，各个子目录都有对应的CMakeList时，使用该条语法
#aux_source_directories(${CMAKE_SOURCE_DIR}/src DIR_SRC) #添加需要编译源文件到DIR_SRC变量

#生成可执行文件
add_executable(LEETCODE 3_longest-substring-without-repeating-characters.cpp)  #设置生成的可执行文件名字，并且把可执行文件和编译源文件关联
#target_link_library(LEETCODE lib1,lib2,lib3) #上面只是link了库文件所在的目录，那么这里就是把具体的库和可执行文件相关联

##生成库文件
#add_library(demo SHARED ${DIR_SRC}) #这里生成库文件有两种形式，一种是STATIC 静态库，一种是SHARED 共享库，如果需要跨硬件运行，一般是生成共享库
#target_link_library(demo lib1,lib2,lib3)
