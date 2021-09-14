/*
 * This file handles the methods of invoking the program driver. Based of the invokation method, the program will then pass the output file name to the functions within 
 * the static library liblog.a. Invocation methods include:
 * 	./driver (no argument) -- prints log to messages.log
 * 	./driver -h -- prints usage message
 * 	./driver -t sec -- prints log to messages.log on average every sec seconds
 * 	./driver [file name] -- prints log to user specified file name
 */

#include <stdio.h>
#include "liblog.a"

int main(int argc, char *argv[]) {
	
	int opt, sec; // Holds argument passed through command line
	char *fileName; // Holds file name
	data_t data;

	if(argc < 2) {
		fileName = "messages.log";
	       	if(addmsg(data, fileName, 0) == -1) {
			exit(0);
		}

		return 0;

	} else if(argc >= 2) {
		if(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "-t") == 0) {
			// Do nothing
		} else {
			fileName = argv[1];
			if(addmsg(data, fileName, 0) == -1) {
				exit(0);
			}

			return 0;
		}
	}

	while((opt = getopt(argc, argv, "th")) != -1) {
		switch(opt) {
			case 'h':
				printf("This program takes 3 different arguments\n");
				printf("./driver -h: prints this usage/help message\n");
				printf("./driver -t [sec]: prints the messages, on average, every sec seconds\n");
				printf("./driver [logfile]: logfile is interpreted as the specified file name to print messages to\n");
				return 0;

			case 't':
				if(argc == 3) {
					sec = atoi(argv[2]);
					fileName = "messages.log";
					if(addmsg(data, fileName, sec) == -1) {
						exit(0);
					}
					break;
				} else {
					printf("Please specify seconds as an integer following -t\n");
					printf("Usage: ./driver -t [sec]\n");
					return 0;
				}

			default:
			        printf("In default");	
				// Invalid option
				return 0;
			}
	}
	
	return 0;
}
