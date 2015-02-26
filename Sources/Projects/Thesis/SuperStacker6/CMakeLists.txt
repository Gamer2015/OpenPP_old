# Minimum CMake Version required
cmake_minimum_required(VERSION 3.0)

#-------------------------------------
# Information about the Project
#-------------------------------------
project(SuperStacker6)
SET(VERSION_MAJOR "1")
SET(VERSION_MINOR "0")
SET(VERSION_PATCH "0")
SET(VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})

SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11")
add_definitions(-DSDL_MAIN_HANDLED)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

#-------------------------------------
# Get Compiler Paths
#-------------------------------------
INCLUDE(${CMAKE_CURRENT_SOURCE_DIR}/../../../OpenppConfig.txt)

#-------------------------------------
# Sources and Headers
#-------------------------------------
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_NAME}_FILES)
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/Game ${PROJECT_NAME}_FILES)

#-------------------------------------
# Create Binary
#-------------------------------------
add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_headers} ${${PROJECT_NAME}_FILES})

#-------------------------------------
# Link Binaries to Libs
#-------------------------------------
target_link_libraries(${PROJECT_NAME} SDL2 SDL2main SDL2_image SDL2_ttf Box2D)

#-------------------------------------
# Configure install
#-------------------------------------
install(TARGETS ${PROJECT_NAME}
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib/static)
