#-------------------------------------
# Currently used CMake Version
#-------------------------------------
cmake_minimum_required(VERSION 3.0)

#-------------------------------------
# Information about the Project
#-------------------------------------
project(TilemapEditor)
SET(VERSION_MAJOR "1")
SET(VERSION_MINOR "0")
SET(VERSION_PATCH "0")
SET(VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})

#-------------------------------------
# Get Compiler Paths
#-------------------------------------
INCLUDE(${CMAKE_CURRENT_SOURCE_DIR}/../../../OpenppConfig.txt)

#-------------------------------------
# It's an SDL2 Programm
#-------------------------------------
add_definitions(-DSDL_MAIN_HANDLED)

#-------------------------------------
# Sources and Headers
#-------------------------------------
file(GLOB ${PROJECT_NAME}_SOURCES "*.cpp" "Editor/*.cpp" "Editor/Screens/*.cpp")
file(GLOB ${PROJECT_NAME}_HEADERS "*.hpp" "Editor/*.hpp" "Editor/Screens/*.hpp")

#-------------------------------------
# Create Binary
#-------------------------------------
add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCES} ${${PROJECT_NAME}_HEADERS})

#-------------------------------------
# Link Binaries to Libs
#-------------------------------------
target_link_libraries(${PROJECT_NAME} openpp_sdl2 SDL2 SDL2main SDL2_image SDL2_ttf)

#-------------------------------------
# Configure install
#-------------------------------------
install(TARGETS ${PROJECT_NAME}
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib/static)
