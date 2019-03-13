all: adjuvant_functions.o buffer_operations.o list_operations.o file_operations.o menu_handler.o main.o
	$gcc adjuvant_functions.o buffer_operations.o list_operations.o file_operations.o menu_handler.o main.o -o program

adjuvant_functions.o: adjuvant_functions.c adjuvant_functions.h list_operations.h data_structures.h
	$gcc adjuvant_functions.c -c -o adjuvant_functions.o
buffer_operations.o: buffer_operations.c buffer_operations.h data_structures.h
	$gcc buffer_operations.c -c -o buffer_operations.o
list_operations.o: list_operations.c list_operations.h adjuvant_functions.h data_structures.h
	$gcc list_operations.c -c -o list_operations.o
file_operations.o: file_operations.c file_operations.h buffer_operations.h list_operations.h data_structures.h
	$gcc file_operations.c -c -o file_operations.o
menu_handler.o: menu_handler.c menu_handler.h adjuvant_functions.h buffer_operations.h file_operations.h data_structures.h
	$gcc menu_handler.c -c -o menu_handler.o
main.o: main.c menu_handler.h list_operations.h data_structures.h
	$gcc main.c -c -o main.o
clean:
	rm -f *.o program
