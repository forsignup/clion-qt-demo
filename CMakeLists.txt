cmake_minimum_required(VERSION 3.13)
project(clionQt)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

#打开Qt的MOC功能和UI文件QRC文件处理功能
#这三句非常重要,开启了这个后就可以自动进行MOC编译,以及将.ui和.qrc 文件编译为C
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

#这句是设置查找Qt库的路径
set(CMAKE_PREFIX_PATH D:/Qt/Qt5.8.0/5.8/mingw53_32)

#查找依赖库
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Quick REQUIRED)

#将.ui文件添加到这里
set(UI_FILES)

#将rc文件添加到这里
set(RC_FILES)

#将qrc文件添加到这里
set(QRC_FILES)

#代码文件
set(SOURCE_FILES main.cpp)

AUX_SOURCE_DIRECTORY(. DIR_SRCS)

#添加一个可exe输出如果不加WIN32会有黑框框哦但是加WIN32就
#add_executable(clionQt ${RC_FILES}${SOURCE_FILES}${UI_FILES}${QRC_FILES})
#add_executable(clionQt WIN32 ${RC_FILES}${SOURCE_FILES}${UI_FILES}${QRC_FILES} mainwindow.cpp mainwindow.h)
add_executable(clionQt ${DIR_SRCS})

#添加要链接的赖库
target_link_libraries(clionQt Qt5::Core)
target_link_libraries(clionQt Qt5::Widgets)
target_link_libraries(clionQt Qt5::Gui)
target_link_libraries(clionQt Qt5::Quick)

qt5_use_modules(clionQt Core Widgets Gui Quick)
