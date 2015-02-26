#-------------------------------------
# Minimum Required CMake Version
#-------------------------------------
cmake_minimum_required(VERSION 3.0)

#-------------------------------------
# Information about the Project
#-------------------------------------
project(Core)
SET(VERSION_MAJOR "1")
SET(VERSION_MINOR "0")
SET(VERSION_PATCH "0")
SET(VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})

SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11")
add_definitions(-DSDL_MAIN_HANDLED)

SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/..)

#-------------------------------------
# Get Compiler Paths
#-------------------------------------
INCLUDE(${CMAKE_CURRENT_SOURCE_DIR}/../../../OpenppConfig.txt)

#-------------------------------------
# Sources and Headers
#-------------------------------------
FILE(GLOB ${PROJECT_NAME}_FOLDER "*.cpp" "*.h" "*.inl")
FILE(GLOB ${PROJECT_NAME}_EXCEPTIONS "Exceptions/*.cpp" "Exceptions/*.h")
FILE(GLOB ${PROJECT_NAME}_MATH "*Math/*.cpp" "Math/*.h" "Math/*.inl")

#-------------------------------------
# Create Binary
#-------------------------------------
add_library (${PROJECT_NAME} STATIC ${${PROJECT_NAME}_FOLDER} ${${PROJECT_NAME}_EXCEPTIONS} ${${PROJECT_NAME}_MATH})
target_link_libraries(${PROJECT_NAME} SDL2 SDL2main SDL2_image SDL2_ttf)

INSTALL(TARGETS ${PROJECT_NAME}
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib/static)
