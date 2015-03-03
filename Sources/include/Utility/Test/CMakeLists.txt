#-------------------------------------
# Currently used CMake Version
#-------------------------------------
cmake_minimum_required(VERSION 3.0)

#-------------------------------------
# Subdirectories (please add in alphabetical Order)
#-------------------------------------
MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
	LIST(APPEND dirlist ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()

SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})

FOREACH(subdir ${SUBDIRS})
    ADD_SUBDIRECTORY(${subdir})
ENDFOREACH()

#-------------------------------------
# Information about the Project
#-------------------------------------
string(REPLACE "/" "" ProjectName ${CMAKE_CURRENT_SOURCE_DIR})
string(REPLACE ":" "" ProjectName ${ProjectName})
string(REPLACE "." "" ProjectName ${ProjectName})
string(REPLACE "_" "" ProjectName ${ProjectName})
string(REPLACE "CUsersStefanDocumentsGitHubOpenppSources" "" ProjectName ${ProjectName})

project(${ProjectName})
SET(VERSION_MAJOR "1")
SET(VERSION_MINOR "0")
SET(VERSION_PATCH "0")
SET(VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})

SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11")

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

#-------------------------------------
# Get Compiler Paths
#-------------------------------------
INCLUDE(${CMAKE_CURRENT_SOURCE_DIR}/../../../OpenppConfig.txt)

#-------------------------------------
# Sources and Headers
#-------------------------------------
SET(${PROJECT_NAME}_SOURCES

    main.cpp
)
SET(${PROJECT_NAME}_HEADERS

    String.h
)

#-------------------------------------
# Create Binary
#-------------------------------------
add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCES} ${${PROJECT_NAME}_HEADERS})

#-------------------------------------
# Configure install
#-------------------------------------
install(TARGETS ${PROJECT_NAME}
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib/static)
