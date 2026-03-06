#pragma once
#include <string>

// Kumpulan lambang kartu (Suit)
enum class Suit {
  Hearts,   // Hati
  Diamonds, // Wajik
  Clubs,    // Keriting
  Spades    // Sekop
};

// Kumpulan angka/wajah kartu (Rank) dengan identitas unik
enum class Rank {
  Two = 2,
  Three = 3,
  Four = 4,
  Five = 5,
  Six = 6,
  Seven = 7,
  Eight = 8,
  Nine = 9,
  Ten = 10,
  Jack = 11,
  Queen = 12,
  King = 13,
  Ace = 14
};

class Card {
private:
  Suit suit;
  Rank rank;

public:
  // Constructor: Saat kartu dicetak, harus ada lambang dan angkanya
  Card(Suit s, Rank r);

  // Fungsi untuk mengambil nilai kartu
  int GetValue();
  Rank GetRank();

  // Fungsi untuk mengubah kartu menjadi teks, misal: "Ace of Spades"
  std::string ToString();
};