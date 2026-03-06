#include "ScoringSystem.h"

int ScoringSystem::CalculateBaseScore(int baseScore, Player& player)
{
  int currentScore = baseScore; // Mulai dengan skor dasar

  // Kita ambil seluruh isi tas pemain
  std::vector<IModifier*> tasPemain = player.GetModifiers();

  // Loop 'for' modern: Untuk setiap kartu (mod) di dalam tasPemain...
  for (IModifier* mod : tasPemain) {
    // ...timpa currentScore dengan hasil dari efek kartu tersebut!
    currentScore = mod->ApplyModifier(currentScore);
  }

  return currentScore; // Kembalikan hasil akhir yang sudah dimodifikasi
}