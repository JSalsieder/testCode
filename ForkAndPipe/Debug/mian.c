/*
 * mian.c
 *
 *  Created on: Oct 5, 2017
 *      Author: cs3841
 */


#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


#define process_number 2000


int main(int argc, char* argv[]){

	pid_t pid[process_number];
	int a = 0;

	printf("before forking begins a = %d \n", a);
	for(int i = 0; i < process_number; i++){
		pid[i] = fork();
		if(pid[i] == 0){
			goto child;
		}else{
			a++;
		}
	}

	for(int i = 0; i < process_number; i++){
		waitpid(pid[i], 0, 0);
	}
	printf("i am the Parent my number a = %d and i have ended \n" , a );
	exit(EXIT_SUCCESS);

child:

printf("i am a child my number a = %d and i have ended \n" , a );
exit(EXIT_SUCCESS);





}
