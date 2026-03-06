#pragma once
#include "Player.h"

class ScoringSystem {
public:
  // Fungsi untuk menerima skor dasar, lalu menghitung total akhirnya setelah ditambah efek kartu
  int CalculateBaseScore(int baseScore, Player& player);
};