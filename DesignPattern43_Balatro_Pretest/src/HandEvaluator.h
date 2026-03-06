#pragma once
#include "Card.h"
#include <string>
#include <vector>

// Paket informasi hasil penilaian juri
struct HandInfo {
  std::string name; // Nama Kombo (Pair, High Card, dll)
  int chips;        // Skor awal kombo
  int mult;         // Pengali awal kombo
};

class HandEvaluator {
public:
  // Fungsi ini menerima kumpulan kartu yang dimainkan, lalu memvonis kombo apa itu
  static HandInfo EvaluateHand(std::vector<Card> playedCards);
};