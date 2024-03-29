cmake_minimum_required(VERSION 3.16.3)
project(KanaCrush)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_STANDARD 14)
#
## Download automatic conan.cmake file
#if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
#    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
#    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
#            "${CMAKE_BINARY_DIR}/conan.cmake")
#endif()
#
#include(${CMAKE_BINARY_DIR}/conan.cmake)
#
#conan_cmake_configure(REQUIRES
#        boost/1.73.0
#        openssl/3.0.1
#        crow/0.1
#        #sqlite3/3.34.1
#        #libcurl/7.80.0
#        ncurses/6.3
#        qt/6.2.4
#
#        GENERATORS cmake_find_package)

#conan_cmake_autodetect(settings)

#set(CONAN_SYSREQUIRES_MODE enabled)
#export(CONAN_SYSREQUIRES_MODE enabled)
#export(sysrequires_mode enabled)

###conan install : Installs the requirements specified in a recipe (conanfile.py or conanfile.txt).
###conan_cmake_install is a wrapper for conan install
#conan_cmake_install(PATH_OR_REFERENCE .
#        BUILD missing
#        REMOTE conancenter
#        SETTINGS ${settings}
##        sysrequires_mode
##        CONAN_SYSREQUIRES_MODE=enabled #ERROR: 'settings.CONAN_SYSREQUIRES_MODE' doesn't exist
#        )

include_directories(.)
include_directories(src)
#include_directories(src/1model)
#include_directories(src/1model/button)
#include_directories(src/1model/candy)
#include_directories(src/1model/cell)
#include_directories(src/2view)
#include_directories(src/2view/button)
#include_directories(src/2view/candy)
#include_directories(src/2view/cell)
#include_directories(src/3control)
#include_directories(src/3control/button)
#include_directories(src/3control/candy)
#include_directories(src/3control/cell)

add_executable(KanaCrush
#        src/1model/button/button.cpp
#        src/1model/button/button.h
#        src/1model/candy/candy.cpp
#        src/1model/candy/candy.h
        src/1model/game/board/cell/Mcell.cpp
        src/1model/game/board/cell/Mcell.h
        src/1model/game/board/Mboard.cpp
        src/1model/game/board/Mboard.h
#        src/2view/button/button.cpp
#        src/2view/button/button.h
#        src/2view/candy/candy.cpp
#        src/2view/candy/candy.h
#        src/2view/cell/Vcell.cpp
#        src/2view/cell/Vcell.h
#        src/2view/Vboard.cpp
#        src/2view/Vboard.h
#        src/3control/button/button.h
#        src/3control/candy/candy.cpp
#        src/3control/candy/candy.h
#        src/3control/cell/Ccell.cpp
#        src/3control/cell/Ccell.h
#        src/3control/Cboard.cpp
#        src/3control/Cboard.h
#        src/cell_linked_list_array.cpp
#        src/cell_linked_list_array.h
#        src/candy.cpp
#        src/CandyCrush.cpp
#        src/main.cpp
#        src/main.h
        src/constants.h
        src/FL_includes.h
        src/srcCommon.h

        src/main.cpp
        src/main.h
        src/2view/GUI/GameWindow.cpp
        src/2view/GUI/GameWindow.h

        src/1model/game/game.cpp
        src/1model/game/game.h

        src/2view/GUI/animation.cpp
        src/2view/GUI/animation.h
        src/2view/GUI/Bounce.cpp
        src/2view/GUI/Bounce.h

        src/2view/GUI/canvas.cpp
        src/2view/GUI/canvas.h
        src/2view/GUI/sketchable.cpp
        src/2view/GUI/sketchable.h
        src/2view/GUI/Rectangle.cpp
        src/2view/GUI/Rectangle.h


        src/test.cpp
        src/test.h

        src/1model/game/board/linked_list/Linked_list.cpp
        src/1model/game/board/linked_list/Linked_list.h
        src/1model/game/board/linked_list/node/Node.cpp
        src/1model/game/board/linked_list/node/Node.h
        src/parameters.cpp
        src/parameters.h
        src/2view/MVCinclude.h
        src/3control/MVCinclude.h
        src/1model/Menu.cpp
        src/1model/Menu.h
        src/2view/GUI/MenuWindow.cpp
        src/2view/GUI/MenuWindow.h
#        src/2view/GUI/Window.cpp
#        src/2view/GUI/Window.h
        src/2view/GUI/WelcomeWindow.cpp
        src/2view/GUI/WelcomeWindow.h
        src/1model/Welcome.cpp
        src/1model/Welcome.h
        src/2view/GUI/ClickableCell.cpp
        src/2view/GUI/ClickableCell.h)

target_link_libraries(KanaCrush fltk)
