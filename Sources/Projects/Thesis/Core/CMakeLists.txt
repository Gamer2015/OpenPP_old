#-------------------------------------
# Minimum Required CMake Version
#-------------------------------------
cmake_minimum_required(VERSION 3.0)

#-------------------------------------
# Information about the Project
#-------------------------------------
project(thesis_core)
SET(VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})

#-------------------------------------
# Get Compiler Paths
#-------------------------------------
INCLUDE(${CMAKE_CURRENT_SOURCE_DIR}/../../../OpenppConfig.txt)

#-------------------------------------
# Sources and Headers
#-------------------------------------
FILE(GLOB ${PROJECT_NAME}_FOLDER "*.cpp" "*.h" "*.hpp")

#-------------------------------------
# Create Binary
#-------------------------------------
add_library (${PROJECT_NAME} STATIC ${${PROJECT_NAME}_FOLDER})

#-------------------------------------
# Link Binaries to Libs
#-------------------------------------
target_link_libraries(${PROJECT_NAME} SDL2 SDL2main SDL2_image SDL2_ttf openpp_sdl2)


INSTALL(TARGETS ${PROJECT_NAME}
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib/static)
