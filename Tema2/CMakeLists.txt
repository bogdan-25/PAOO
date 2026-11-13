cmake_minimum_required(VERSION 3.10)
project(tema2)
include_directories(inc)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(FARA_INIT "" OFF)
option(ORDINE_GRESITA "" OFF)
option(ATRIBUIRE_IN_CORP "" OFF)
option(CATALOG_GLOBAL "" OFF)
option(INCEARCA_ATRIBUIRE "" OFF)
option(INCEARCA_COPIERE "" OFF)
foreach(opt FARA_INIT ORDINE_GRESITA ATRIBUIRE_IN_CORP CATALOG_GLOBAL
            INCEARCA_ATRIBUIRE INCEARCA_COPIERE)
    if(${opt})
        add_definitions(-D${opt})
    endif()
endforeach()

add_executable(${PROJECT_NAME}
    inc/tema2/eticheta.hpp
    inc/tema2/carte.hpp
    inc/tema2/raft.hpp
    inc/tema2/catalog.hpp
    inc/tema2/exemplar.hpp
    inc/tema2/imprumut.hpp
    inc/tema2/necopiabil.hpp
    inc/tema2/manuscris.hpp
    inc/tema2/carte_rara.hpp
    src/deschidere.cpp
    src/catalog.cpp
    src/eticheta.cpp
    src/carte.cpp
    src/raft.cpp
    src/imprumut.cpp
    src/manuscris.cpp
    src/carte_rara.cpp
    src/main.cpp
)
