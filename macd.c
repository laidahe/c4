#include <stdio.h>
//diff = EMA(CLOSE,9) - EMA(CLOSE,26)
//dea  = EMA(DIFF,12)
//macd : 2*(DIFF-DEA)
//zero: HHV(CLOSE,120)


int main()
{

  int *CLOSE, *fast, *slow, *diff, *diffma, *diff2, *macd;
  int i,c,t;
  CLOSE = GCLS();
  fast = EMA(CLOSE, 9);
  slow = EMA(CLOSE, 26);
  diff = SUBV(fast, slow);
  diffma = EMA(diff, 12);
  diff2 = SUBV(diff, diffma);
  macd = MULV(diff2, 2);
  
  i = 0;
  c = 0;
  while(i < 100){
    i++;
    t = *(macd + i);
    if(t > 0){
      //printf("macd|i=%d|val=%d\n", i, t);
      c++;
    }
    if(c > 10){
      return 0;
    }
  }
  return 0;
}
