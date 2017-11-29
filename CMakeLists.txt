cmake_minimum_required(VERSION 2.8.11)

project(libAIalgorithms)

file(GLOB PROJECT_FILES "*.h"
						"*.cpp")

set(CMAKE_INCLUDE_CURRENT_DIR ON)		# Find includes in corresponding build directories
set(CMAKE_AUTOMOC ON)					# Instruct CMake to run moc automatically when needed.

# Packages included in project
find_package(Qt5Core REQUIRED)

# Output a static library
add_library(${PROJECT_NAME} ${PROJECT_FILES})
					  
target_link_libraries(${PROJECT_NAME} Qt5::Core
									  ${LIBS})

# Expose public includes (including Qt transitively) to other subprojects through cache variable.
set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}
								 ${Qt5Core_INCLUDE_DIRS}
    CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)

# Expose public libs
set(${PROJECT_NAME}_LIBS ${LIBS}
    CACHE INTERNAL "${PROJECT_NAME}: Required Dynamic Libraries" FORCE)