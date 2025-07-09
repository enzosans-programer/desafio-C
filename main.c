#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")  // Vincula a biblioteca

int main(int argc, char *argv[]) {
    printf("\n");
    PlaySoundA("robots_and_aliens-joel_cummins.wav", NULL, SND_FILENAME | SND_ASYNC);
    return 0;
}
