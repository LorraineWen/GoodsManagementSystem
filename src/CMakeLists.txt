# 设置编译类型为Debug
set(CMAKE_BUILD_TYPE Debug)
# 添加调试信息
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
#生成可执行文件
add_executable(server main.cpp)

#添加模块
add_subdirectory(model)
add_subdirectory(tool)
add_subdirectory(controller)
#链接库
target_link_libraries(server  controllerlib)

