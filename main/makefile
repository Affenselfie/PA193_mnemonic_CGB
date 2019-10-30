all: main

main: main.o Init.o convNum.o stringConv.o
	gcc  -Wall Init.o convNum.o stringConv.o main.o  -o main -lssl -lcrypto

main.o: main.c Init.h convNum.h stringConv.h
	gcc  -Wall main.c -c 

Init.o: Init.c 
	gcc  -Wall Init.c -c

convNum.o: convNum.c 
	gcc  -Wall convNum.c -c

stringConv.o: stringConv.c 
	gcc  -Wall stringConv.c -c

Clean:
	rm main main.o Init.o convNum.o stringConv;o