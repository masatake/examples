/* exitの引数がプロセスの終了ステータスになることを確認する。

   ./a.out; echo $? */

#include <stdlib.h>

int
main(void)
{
  exit(31);
  return 0;
}
