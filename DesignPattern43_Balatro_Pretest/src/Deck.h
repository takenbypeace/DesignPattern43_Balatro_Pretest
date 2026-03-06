#pragma once
#include "Card.h"
#include <vector>

class Deck {
private:
  std::vector<Card> cards; // Ini adalah kotak yang berisi tumpukan kartu kita

public:
  Deck();                  // Saat Deck dibuat, langsung cetak 52 kartu
  void InitializeDeck();   // Mesin pencetak 52 kartu standar
  void Shuffle();          // Mesin pengocok kartu acak
  Card DrawCard();         // Mengambil 1 kartu dari tumpukan paling atas
  int GetRemainingCards(); // Mengecek sisa kartu di tumpukan
};