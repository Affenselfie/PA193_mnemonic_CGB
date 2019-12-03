all: main

main: main.o Init.o convNum.o stringConv.o fastpbkdf2.o hashFct.o choice.o
	afl-clang-fast  -Wall Init.o convNum.o stringConv.o fastpbkdf2.o hashFct.o choice.o main.o  -o main -lssl -lcrypto

main.o: main.c Init.h convNum.h stringConv.h fastpbkdf2.h hashFct.h choice.h
	afl-clang-fast  -Wall main.c -c 

Init.o: Init.c 
	afl-clang-fast  -Wall Init.c -c

convNum.o: convNum.c 
	afl-clang-fast  -Wall convNum.c -c

stringConv.o: stringConv.c hashFct.h
	afl-clang-fast  -Wall stringConv.c -c

hashFct.o: hashFct.c 
	afl-clang-fast  -Wall hashFct.c -c

choice.o: choice.c hashFct.h convNum.h Init.h stringConv.h fastpbkdf2.h
	afl-clang-fast  -Wall choice.c -c

Clean:
	rm main main.o Init.o convNum.o stringConv.o
