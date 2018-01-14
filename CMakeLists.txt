cmake_minimum_required(VERSION 3.7)
include(FindPkgConfig)
pkg_search_module(ALLEGRO REQUIRED allegro)
add_executable(SpaceDemo
               global.cxx
               Object.cxx
               Pixel.cxx
               Point.cxx
               RefreshTimer.cxx
               spacedemo.cxx
               Sprite.cxx
               Starfield.cxx
               Vector.cxx)
target_link_libraries(SpaceDemo PUBLIC ${ALLEGRO_LIBRARIES})
