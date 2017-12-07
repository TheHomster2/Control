#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#define KEY 32
//Key is a unique semaphore identifier

int main(int argc, char *argv[]){
	int sd;
	int value;

	if (argc != 2){
		printf("Need one argument\n");
	}
	else{
		if (strcmp(agrv[1], "-c") == 0){
			sd = semget(KEY, 1, IPC_CREAT | IPC_EXCL | 0644);
			if (sd == -1){
				printf("semaphore already exists\n");
			}
			else{
				value = atoi(agrv[2]);
				semctl(sd, 0, SETVAL, value);
			}
		}
	}

	else if (strcmp(agrv[1], "-v") == 0){
		sd = semget(KEY, 1, 0644);
		value = semctl(sem, 0, GETVAL);
	}

	else if (strcmp(agrv[1], "-v") == 0){
		sd = semget(KEY, 1, 0644);
		semctl(sem, 0, IPC_RMID);
	}

	else{
		printf("Invalid argument(s)");
	}

	return 0;
}
} 