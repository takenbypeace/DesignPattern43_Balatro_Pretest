#include "RandomBonusModifier.h"
#include <cstdlib> // Wajib ditambahkan untuk menggunakan rand()

int RandomBonus::ApplyModifier(int currentScore)
{
  // Menghasilkan angka bonus acak antara 1 sampai 20
  int bonus = rand() % 20 + 1;

  // Menambahkan bonus tersebut ke skor pemain saat ini
  return currentScore + bonus;
}