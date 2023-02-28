#include <termios.h>
#include <unistd.h>
#include <stdio.h>

int get_char(void)
{
    struct termios old, new;
    int c;
    
    tcgetattr(STDIN_FILENO, &old);
    new = old;
    new.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new);

    c = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &old);

    return c;
}

int main(void)
{
  while(1)
    printf("%c\n", get_char());

  return 0;
}
