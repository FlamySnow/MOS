cmake_minimum_required(VERSION 3.20)
project(MOS)

set(CMAKE_CXX_STANDARD 23)

add_library(MOS STATIC Creature.cpp Creature.h Skill.cpp Skill.h)
