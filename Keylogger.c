#include <stdio.h>
#include <windows.h>

int main()
{
    char name[64] = "";
    strcpy(name,getenv("USERNAME"));
    printf("%s\n", name);
    return 0;
}