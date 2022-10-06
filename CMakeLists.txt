cmake_minimum_required(VERSION 3.16)

include(cmake/vcpkg.cmake)

project(advancedkeybinder VERSION 0.1 LANGUAGES CXX)

if (APPLE)
  set(
    STREAMDECK_PLUGIN_DIR
    "$ENV{HOME}/Library/ApplicationSupport/com.elgato.StreamDeck/Plugins"
  )
endif()
if (WIN32)
  set(
    STREAMDECK_PLUGIN_DIR
    "%appdata%\\Elgato\\StreamDeck\\Plugins\\"
  )
endif()

set(
  CMAKE_INSTALL_PREFIX
  "${STREAMDECK_PLUGIN_DIR}/${CMAKE_PROJECT_NAME}"
  CACHE STRING "See cmake documentation"
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (MSVC)
  add_definitions("/Zc:__cplusplus" -DUNICODE=1)
endif()
include_directories("${CMAKE_SOURCE_DIR}")

include(StreamDeckSDK.cmake)

# TODO: Add windows- and mac variants of the keybinder
set(
  SOURCES
  src/AdvancedKeybinder.cpp
  src/main.cpp
)
if (APPLE)
  #list(APPEND SOURCES macOS/CpuUsageHelper.cpp)
elseif (WIN32)
  #list(APPEND SOURCES Windows/CpuUsageHelper.cpp)
endif()
add_executable(
  advancedkeybinder
  ${SOURCES}
)
target_link_libraries(advancedkeybinder StreamDeckSDK)

enable_testing()