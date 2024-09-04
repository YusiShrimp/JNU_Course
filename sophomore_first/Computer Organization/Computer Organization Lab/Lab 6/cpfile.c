/* All of rio function implementations are obtained from csapp.c */
/* Please note the usage of wrapper function */

/* $begin cpfile */
#include "csapp.h"

int main(int argc, char** argv)

{
    int n;
    rio_t rio;
    char buf[MAXLINE];
    int fd;

    /* Check that the input file is specified */
    if (argc == 2) {
        /* If an input file is specified, an attempt is made to open it */
        if (access(argv[1], F_OK) != -1) {
            fd = Open(argv[1], O_RDONLY, 0);
            Rio_readinitb(&rio, fd);
        }
        else {
            /* If the file does not exist, a message is displayed */
            fprintf(stderr, "File %s does not exist. Reading from standard input.\n", argv[1]);
            Rio_readinitb(&rio, STDIN_FILENO);
        }

    }
    else {
        /* No input file is specified and the standard input is read directly */  //Satisfy the requirement£¡£¡
        Rio_readinitb(&rio, STDIN_FILENO);
    }
    /* Each character is read in turn and printed to standard output */
    int count = 0; //Counter, which records the number of bytes read
    while ((n = Rio_readnb(&rio, buf, 1)) != 0) {
        Rio_writen(STDOUT_FILENO, buf, n);
        count++;
        if (count == 10) {
            /* Line feed every 10 characters read */
            Rio_writen(STDOUT_FILENO, "\n", 1);
            count = 0;
        }
    }

    /* If there is less than 10 characters left, output directly */
    if (count > 0) {
        Rio_writen(STDOUT_FILENO, "\n", 1);
    }
    exit(0);
}
/* $end cpfile */
