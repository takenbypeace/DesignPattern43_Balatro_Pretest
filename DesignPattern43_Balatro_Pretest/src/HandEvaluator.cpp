#include "HandEvaluator.h"
#include <map>

HandInfo HandEvaluator::EvaluateHand(std::vector<Card> playedCards)
{
  HandInfo result;

  // Alat untuk menghitung berapa kali sebuah Rank muncul
  std::map<Rank, int> rankCounts;
  for (Card c : playedCards) {
    rankCounts[c.GetRank()]++;
  }

  // Cari tahu jumlah kembaran terbanyak
  int maxSameRank = 0;
  for (const auto& pair : rankCounts) {
    if (pair.second > maxSameRank) {
      maxSameRank = pair.second; // pair.second adalah 'count' atau jumlah kartunya
    }
  }

  // === VONIS KOMBO ===
  if (maxSameRank == 3) {
    result.name = "Three of a Kind";
    result.chips = 30; // Standar Balatro
    result.mult = 3;
  }
  else if (maxSameRank == 2) {
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