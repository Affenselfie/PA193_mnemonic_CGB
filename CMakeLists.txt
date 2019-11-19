cmake_minimum_required(VERSION 3.15)
project(PA193_mnemonic_CGB)

set(CMAKE_CXX_STANDARD 14)

include_directories(main)

add_link_options(-lssl -lcrypto)
add_executable(PA193_mnemonic_CGB
        main/choice.c
        main/choice.h
        main/convNum.c
        main/convNum.h
        main/fastpbkdf2.c
        main/fastpbkdf2.h
        main/hashFct.c
        main/hashFct.h
        main/Init.c
        main/Init.h
        main/main.c
        main/stringConv.c
        main/stringConv.h
        README.md)
