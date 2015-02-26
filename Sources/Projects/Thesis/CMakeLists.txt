# Minimum CMake Version required
cmake_minimum_required(VERSION 3.0)

#-------------------------------------
# Information about the Project
#-------------------------------------
project(Thesis)
SET(VERSION_MAJOR "1")
SET(VERSION_MINOR "0")
SET(VERSION_PATCH "0")
SET(VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})

#-------------------------------------
# Subdirectories
#-------------------------------------
add_subdirectory(Core)
add_subdirectory(SuperStacker6)
