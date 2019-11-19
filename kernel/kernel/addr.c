/* malloc, mmapして得たバッファが仮想アドレス上のどこに配置
   されるか調べるプログラム

   実行するとpidとともにバッファのアドレスが表示されるので、
   /proc/$pid/mapsを見て、場所を確認する。*/
   

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/mman.h>

int
main(void)
{
  void * a = malloc(1024 * 100);
  char * b = mmap (NULL, 4096 * 100, PROT_READ, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);

  if (MAP_FAILED == b) 
    {
      perror("mmap");
      return 1;
    }

  printf("(pid: %u) => stack: %lx, malloc: %lx, mmap %lx\n", getpid(), &a, a, b);
  sleep (9999);
  return 0;
}
