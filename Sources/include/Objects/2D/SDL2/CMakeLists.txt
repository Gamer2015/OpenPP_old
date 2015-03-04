#-------------------------------------
# Minimum Required CMake Version
#-------------------------------------
cmake_minimum_required(VERSION 3.0)

#-------------------------------------
# Information about the Project
#-------------------------------------
project(openpp_sdl2)
SET(VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})

#-------------------------------------
# Get Compiler Paths
#-------------------------------------
INCLUDE(${CMAKE_CURRENT_SOURCE_DIR}/../../../../OpenppConfig.txt)

#-------------------------------------
# Sources and Headers
#-------------------------------------
FILE(GLOB ${PROJECT_NAME}_FOLDER "*.cpp" "*.h" "*.hpp")
FILE(GLOB ${PROJECT_NAME}_PROPERTIES "Properties/*.cpp" "Properties/*.h" "Properties/*.hpp")

#-------------------------------------
# Create Binary
#-------------------------------------
add_library (${PROJECT_NAME} STATIC ${${PROJECT_NAME}_FOLDER} ${${PROJECT_NAME}_PROPERTIES})

INSTALL(TARGETS ${PROJECT_NAME}
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib/static)
