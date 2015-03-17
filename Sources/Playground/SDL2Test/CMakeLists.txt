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
# Get Files in Project Hirachie
#-------------------------------------
FILE(GLOB ${CMAKE_CURRENT_SOURCE_DIR}_FOLDER "*.h" "*.hpp" "*.inl")

string(REPLACE "/" "" Target ${CMAKE_CURRENT_SOURCE_DIR})
string(REPLACE ":" "" Target ${Target})
string(REPLACE "." "" Target ${Target})
string(REPLACE "_" "" Target ${Target})
add_custom_target(${Target} SOURCES ${${CMAKE_CURRENT_SOURCE_DIR}_FOLDER})
