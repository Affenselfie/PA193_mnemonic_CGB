all: main

main: main.o Init.o convNum.o stringConv.o fastpbkdf2.o hashFct.o choice.o
	gcc  -Wall Init.o convNum.o stringConv.o fastpbkdf2.o hashFct.o choice.o main.o  -o main -lssl -lcrypto

main.o: main.c Init.h convNum.h stringConv.h fastpbkdf2.h hashFct.h choice.h
	gcc  -Wall main.c -c 

Init.o: Init.c 
	gcc  -Wall Init.c -c

convNum.o: convNum.c 
	gcc  -Wall convNum.c -c

stringConv.o: stringConv.c hashFct.h
	gcc  -Wall stringConv.c -c

hashFct.o: hashFct.c 
	gcc  -Wall hashFct.c -c

choice.o: choice.c hashFct.h convNum.h Init.h stringConv.h fastpbkdf2.h
	gcc  -Wall choice.c -c

Clean:
	rm main main.o Init.o convNum.o stringConv.o