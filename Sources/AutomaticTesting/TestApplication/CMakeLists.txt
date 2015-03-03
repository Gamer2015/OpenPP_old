#-------------------------------------
# Currently used CMake Version
#-------------------------------------
cmake_minimum_required(VERSION 3.0)

#-------------------------------------
# Information about the Project
#-------------------------------------
PROJECT(AutomaticTestApplication)
SET(VERSION_MAJOR "1")
SET(VERSION_MINOR "0")
SET(VERSION_PATCH "0")
SET(VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})

#-------------------------------------
# Get Compiler Paths
#-------------------------------------
INCLUDE(${CMAKE_CURRENT_SOURCE_DIR}/../../OpenppConfig.txt)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/..)

#-------------------------------------
# Additional Compiler Settings
#-------------------------------------
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

#-------------------------------------
# Set up QT
#-------------------------------------
list(APPEND CMAKE_MODULE_PATH "${QT_PATH}/lib/cmake")
FIND_PACKAGE(Qt5Widgets)

add_definitions(${Qt5Widgets_DEFINITIONS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

#-------------------------------------
# Qt Gui Files
#-------------------------------------

SET(${PROJECT_NAME}_SOURCES

    main.cpp
    Gui/mainwindow.cpp
    Testing/TesterThread.cpp
)
SET(${PROJECT_NAME}_HEADERS

    Commands.h
    Gui/mainwindow.h
    Testing/TesterThread.h
)
SET(${PROJECT_NAME}_QT_UIS

    Gui/mainwindow.ui
)
QT5_WRAP_UI(${PROJECT_NAME}_FORMS_HEADERS ${${PROJECT_NAME}_QT_UIS})

#-------------------------------------
# Create Binary
#-------------------------------------

ADD_EXECUTABLE(${PROJECT_NAME}

    ${${PROJECT_NAME}_SOURCES}
    ${${PROJECT_NAME}_HEADERS}

    ${${PROJECT_NAME}_FORMS_HEADERS}
)

#-------------------------------------
# Link Libraries
#-------------------------------------
target_link_libraries(${PROJECT_NAME} Qt5::Widgets boost_system boost_filesystem)

#-------------------------------------
# Configure install
#-------------------------------------
install(TARGETS ${PROJECT_NAME}
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib/static)
