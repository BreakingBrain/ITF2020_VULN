#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    setreuid( 2020, 2020 );
    setregid( 2020, 2020 );
    system( "less /home/user/read_me" );
    return 0;
 }