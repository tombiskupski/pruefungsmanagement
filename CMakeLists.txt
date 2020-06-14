cmake_minimum_required(VERSION 3.16)
project(progprojekt)

set(CMAKE_CXX_STANDARD 17)

add_executable(progprojekt main.cpp Anmeldung.h Anmeldung.cpp Student.cpp Student.h Pruefer.cpp Pruefer.h Pruefung.cpp Pruefung.h Raum.cpp Raum.h Zeit.cpp Zeit.h PruefungsTag.cpp PruefungsTag.h)