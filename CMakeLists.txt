cmake_minimum_required(VERSION 3.19)
project(screaming_goose)

set(SFML_STATIC_LIBRARIES TRUE)
set(CMAKE_BUILD_TYPE Release)
find_package(SFML 2 COMPONENTS graphics system window audio network REQUIRED)

set(SOURCE_FILES
    src/main.cpp
    src/app.cpp
    src/pipe.cpp
    src/assets.cpp
    src/player.cpp
    src/button.cpp
    src/scenes/splash_scene.cpp
    src/scenes/menu_scene.cpp
    src/scenes/game_scene.cpp
    src/scenes/death_scene.cpp
)

add_executable(game ${SOURCE_FILES})

target_link_libraries(game sfml-graphics sfml-system sfml-window sfml-audio sfml-network)

file(COPY res/ DESTINATION res/)
