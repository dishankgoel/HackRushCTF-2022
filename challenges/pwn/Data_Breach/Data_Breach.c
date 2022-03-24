#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

/* Ignore these functions */
void buffering() {
    setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
}

void timeout(int sig) {
    if (sig == SIGALRM) {
        printf("[!] DOS Alert\n");
        _exit(0);
    }
}

void kill_signal() {
    signal(SIGALRM, timeout);
    alarm(60);
}

// Real challenge starts here

char flag[50];

void setup() {
    FILE* f = fopen("flag.txt", "r");
    fscanf(f, "%s", flag);
    fclose(f);
}

void func() {
    printf("[*] We suspect that there may be a big data breach that has happened on our servers\n");
    printf("Can you find what caused it?: ");
    char cause[100];
    fgets(cause, 100, stdin);
    printf(cause);
}

int main() {
    buffering();
    kill_signal();
    setup();
    func();
}
