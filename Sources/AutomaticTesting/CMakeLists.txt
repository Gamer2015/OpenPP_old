#-------------------------------------
# Currently used CMake Version
#-------------------------------------
cmake_minimum_required(VERSION 3.0)

#-------------------------------------
# Add Subdirectories
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
# Get Files in Project Hirachie
#-------------------------------------

string(REPLACE "/" "" ProjectName ${CMAKE_CURRENT_SOURCE_DIR})
string(REPLACE ":" "" ProjectName ${ProjectName})
string(REPLACE "." "" ProjectName ${ProjectName})
string(REPLACE "_" "" ProjectName ${ProjectName})
string(REPLACE "CUsersStefanDocumentsGitHubOpenppSources" "" ProjectName ${ProjectName})
project(${ProjectName})

FILE(GLOB ${PROJECT_NAME}_FOLDER "*.c" "*.cpp" "*.h" "*.hpp" "*.inl" "*.dll" "*.a" "*.pc" "*.cmake")
add_custom_target(${PROJECT_NAME} SOURCES ${${PROJECT_NAME}_FOLDER})
