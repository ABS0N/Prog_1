#include<cstdio>

void f(char p[], int x)
{
    printf("p: %s, x: %d\n", p, x);
}

int main()
{
    printf("Hello, World!\n");

    char p1[] = "Hello";
    char p2[] = "World!";

    printf("%s, %s\n", p1, p2);

    f("foo", 7);

    return 0;
}

