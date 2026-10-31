#include <termios.h>
#include <unistd.h>
#include <cstdio>

int main() {
    termios old, raw;
    tcgetattr(0, &old);
    raw = old;
    raw.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0, TCSANOW, &raw);

    unsigned char c;
    while (read(0, &c, 1) == 1 && c != 'q')
        std::printf("%3d  0x%02x\n", c, c);

    tcsetattr(0, TCSANOW, &old);
}
