cmake_minimum_required(VERSION 3.20)
project(MOS)

set(CMAKE_CXX_STANDARD 23)

add_library(MOS STATIC Creature.cpp Creature.h Skill.cpp Skill.h SchoolTable.cpp SchoolTable.h Input.h Squad.cpp Squad.h MoraleSquad.cpp MoraleSquad.h Summoner.cpp Summoner.h Tile.cpp Tile.h STile.cpp STile.h Landscape.cpp Landscape.h)
