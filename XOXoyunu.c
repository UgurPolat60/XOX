#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char tahta[3][3];
const char OYUNCU = 'X';
const char BILGISAYAR = 'O';

void tahtaSifirla();
void tahtaYazdir();
int bosAlanKontrol();
void oyuncuHamlesi();
void bilgisayarHamlesi();
char kazananKontrol();
void kazananYazdir(char);

int main()
{
   char kazanan = ' ';
   char yanit = ' ';

   do
   {
      kazanan = ' ';
      yanit = ' ';
      tahtaSifirla();

      while(kazanan == ' ' && bosAlanKontrol() != 0)
      {
         tahtaYazdir();

         oyuncuHamlesi();
         kazanan = kazananKontrol();
         if(kazanan != ' ' || bosAlanKontrol() == 0)
         {
            break;
         }

         bilgisayarHamlesi();
         kazanan = kazananKontrol();
         if(kazanan != ' ' || bosAlanKontrol() == 0)
         {
            break;
         }
      }

      tahtaYazdir();
      kazananYazdir(kazanan);

      printf("\nTekrar oynamak ister misiniz? (E/H): ");
      scanf(" %c", &yanit); 
      yanit = toupper(yanit);
   } while (yanit == 'E');

   printf("Oynadığınız için teşekkürler!");

   return 0;
}

void tahtaSifirla()
{
   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         tahta[i][j] = ' ';
      }
   }
}
void tahtaYazdir()
{
   printf(" %c | %c | %c ", tahta[0][0], tahta[0][1], tahta[0][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", tahta[1][0], tahta[1][1], tahta[1][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", tahta[2][0], tahta[2][1], tahta[2][2]);
   printf("\n");
}
int bosAlanKontrol()
{
   int bosAlan = 9;

   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         if(tahta[i][j] != ' ')
         {
            bosAlan--;
         }
      }
   }
   return bosAlan;
}
void oyuncuHamlesi()
{
   int x;
   int y;

   do
   {
      printf("Satır numarasını girin (1-3): ");
      scanf("%d", &x);
      x--;
      printf("Sütun numarasını girin (1-3): ");
      scanf("%d", &y);
      y--;

      if(tahta[x][y] != ' ')
      {
         printf("Geçersiz hamle!\n");
      }
      else
      {
         tahta[x][y] = OYUNCU;
         break;
      }
   } while (tahta[x][y] != ' ');
}
void bilgisayarHamlesi()
{
   srand(time(0));
   int x;
   int y;

   if(bosAlanKontrol() > 0)
   {
      do
      {
         x = rand() % 3;
         y = rand() % 3;
      } while (tahta[x][y] != ' ');

      tahta[x][y] = BILGISAYAR;
   }
   else
   {
      kazananYazdir(' ');
   }
}
char kazananKontrol()
{

   for(int i = 0; i < 3; i++)
   {
      if(tahta[i][0] == tahta[i][1] && tahta[i][0] == tahta[i][2])
      {
         return tahta[i][0];
      }
   }

   for(int i = 0; i < 3; i++)
   {
      if(tahta[0][i] == tahta[1][i] && tahta[0][i] == tahta[2][i])
      {
         return tahta[0][i];
      }
   }
   
   if(tahta[0][0] == tahta[1][1] && tahta[0][0] == tahta[2][2])
   {
      return tahta[0][0];
   }
   if(tahta[0][2] == tahta[1][1] && tahta[0][2] == tahta[2][0])
   {
      return tahta[0][2];
   }

   return ' ';
}
void kazananYazdir(char kazanan)
{
   if(kazanan == OYUNCU)
   {
      printf("KAZANDINIZ!");
   }
   else if(kazanan == BILGISAYAR)
   {
      printf("KAYBETTİNİZ!");
   }
   else{
      printf("BERABERE!");
   }
}
