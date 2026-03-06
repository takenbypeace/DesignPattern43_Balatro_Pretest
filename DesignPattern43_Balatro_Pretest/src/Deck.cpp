#include "Deck.h"
#include <algorithm> // Untuk std::shuffle
#include <chrono>    // Untuk mengambil waktu komputer saat ini
#include <random>    // Untuk mesin acak

Deck::Deck()
{
  InitializeDeck();
}

void Deck::InitializeDeck()
{
  cards.clear(); // Kosongkan kotak sebelum mencetak kartu baru

  // Daftar semua lambang dan angka
  Suit suits[] = { Suit::Hearts, Suit::Diamonds, Suit::Clubs, Suit::Spades };
  Rank ranks[] = { Rank::Two,   Rank::Three, Rank::Four, Rank::Five, Rank::Six,
                   Rank::Seven, Rank::Eight, Rank::Nine, Rank::Ten,  Rank::Jack,
                   Rank::Queen, Rank::King,  Rank::Ace };

  // Proses cetak: Gabungkan setiap lambang dengan setiap angka (4 x 13 = 52 kartu)
  for (Suit s : suits) {
    for (Rank r : ranks) {
      cards.push_back(Card(s, r));
    }
  }
}

void Deck::Shuffle()
{
  // Buat bibit acak (seed) berdasarkan waktu komputer yang terus berjalan
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine mesinAcak(seed);

  // Kocok tumpukan kartu
  std::shuffle(cards.begin(), cards.end(), mesinAcak);
}

Card Deck::DrawCard()
{
  // Ambil kartu paling atas (di akhir vector)
  Card topCard = cards.back();
  // Hapus kartu itu dari tumpukan agar tidak terambil dua kali
  cards.pop_back();
  return topCard;
}

int Deck::GetRemainingCards()
{
  return cards.size();
}