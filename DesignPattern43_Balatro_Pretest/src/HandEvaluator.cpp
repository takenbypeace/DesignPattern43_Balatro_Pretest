#include "HandEvaluator.h"
#include <map>

HandInfo HandEvaluator::EvaluateHand(std::vector<Card> playedCards)
{
  HandInfo result;

  // 1. Alat untuk menghitung berapa kali sebuah Rank muncul
  std::map<Rank, int> rankCounts;
  for (Card c : playedCards) {
    rankCounts[c.GetRank()]++;
  }

  // 2. Variabel detektif untuk menghitung jumlah kelompok kembaran
  int pairs = 0;   // Untuk menghitung jumlah kembar 2
  int triples = 0; // Untuk menghitung jumlah kembar 3
  int quads = 0;   // Untuk menghitung jumlah kembar 4

  // 3. Juri mulai menginspeksi hasil hitungan
  for (const auto& pair : rankCounts) {
    if (pair.second == 4) {
      quads++;
    }
    else if (pair.second == 3) {
      triples++;
    }
    else if (pair.second == 2) {
      pairs++;
    }
  }

  // === 4. VONIS KOMBO (Diurutkan dari yang Paling Kuat) ===
  if (quads == 1) {
    result.name = "Four of a Kind";
    result.chips = 60;
    result.mult = 7;
  }
  else if (triples == 1 && pairs >= 1) {
    // Punya kembar 3 DAN kembar 2 di saat bersamaan = Full House
    result.name = "Full House";
    result.chips = 40;
    result.mult = 4;
  }
  else if (triples == 1) {
    result.name = "Three of a Kind";
    result.chips = 30;
    result.mult = 3;
  }
  else if (pairs == 2) {
    result.name = "Two Pair";
    result.chips = 20;
    result.mult = 2;
  }
  else if (pairs == 1) {
    result.name = "Pair";
    result.chips = 10;
    result.mult = 2;
  }
  else {
    result.name = "High Card";
    result.chips = 5;
    result.mult = 1;
  }

  return result;
}