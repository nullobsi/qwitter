cmake_minimum_required(VERSION 3.17)
project(qwitter)
set(QTKEYCHAIN_STATIC)
add_subdirectory(qtkeychain)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets Network NetworkAuth)
set(REQUIRED_LIBS_QUALIFIED Qt${QT_VERSION}::Core Qt${QT_VERSION}::Gui Qt${QT_VERSION}::Widgets Qt${QT_VERSION}::Network Qt${QT_VERSION}::NetworkAuth)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
add_executable(${PROJECT_NAME} main.cpp gui/MainWindow.cpp gui/MainWindow.h gui/MainWindow.ui gui/TimelineTweet.cpp gui/TimelineTweet.h gui/TimelineTweet.ui gui/AuthenticateDialog.cpp gui/AuthenticateDialog.h gui/AuthenticateDialog.ui api/TwitterClient.cpp api/TwitterClient.h)

target_include_directories(${PROJECT_NAME} PRIVATE qtkeychain)
target_compile_definitions(${PROJECT_NAME} PRIVATE QTKEYCHAIN_NO_EXPORT)
if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED} qt5keychain)
