#include <stddef.h> // for size_t
#include <stdint.h> // for uint32_t
#include <stdio.h> // for printf
#include <netinet/in.h>
#include <fcntl.h> // for fopen, fread...

int main(int argc, char *argv[])
{
    int i=argc;

    if(argc != 3){
        printf("Usage: ./%s <filename1> <filename2> (ARGC: 3)\n", argv[0]);
        printf("ARGC : %d\n", i);
        return 0;
    }

    FILE *fd1, *fd2;
    uint32_t n1, n2;

    fd1=fopen(argv[1], "r");
    fd2=fopen(argv[2], "r");

    if(fd1==NULL||fd2==NULL){
        printf("File does not exist error..\n");
    }

    fread(&n1, sizeof n1, 1, fd1);
    fread(&n2, sizeof n2, 1, fd2);

    fclose(fd1);
    fclose(fd2);

    n1=htonl(n1);
    n2=htonl(n2);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", n1, n1, n2, n2, n1+n2, n1+n2);

    return 0;
}
