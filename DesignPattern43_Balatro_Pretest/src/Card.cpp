#include "Card.h"

// Saat kartu dibuat, simpan lambang dan angkanya
Card::Card(Suit s, Rank r)
{
  suit = s;
  rank = r;
}

// Kembalikan nilai skor kartu untuk dihitung
int Card::GetValue()
{
  if (rank == Rank::Jack || rank == Rank::Queen || rank == Rank::King) {
    return 10; // Kartu wajah nilainya 10
  }
  else if (rank == Rank::Ace) {
    return 11; // Kartu As nilainya 11
  }
  else {
    return static_cast<int>(rank); // Kartu 2-10 nilainya sesuai angkanya
  }
}

// Ubah lambang dan angka menjadi teks yang bisa dibaca manusia
std::string Card::ToString()
{
  std::string rankStr = "";
  std::string suitStr = "";

  // Tentukan teks angka/wajah
  switch (rank) {
    case Rank::Two:   rankStr = "2"; break;
    case Rank::Three: rankStr = "3"; break;
    case Rank::Four:  rankStr = "4"; break;
    case Rank::Five:  rankStr = "5"; break;
    case Rank::Six:   rankStr = "6"; break;
    case Rank::Seven: rankStr = "7"; break;
    case Rank::Eight: rankStr = "8"; break;
    case Rank::Nine:  rankStr = "9"; break;
    case Rank::Ten:   rankStr = "10"; break;
    case Rank::Jack:  rankStr = "Jack"; break;
    case Rank::Queen: rankStr = "Queen"; break;
    case Rank::King:  rankStr = "King"; break;
    case Rank::Ace:   rankStr = "Ace"; break;
  }

  // Tentukan teks lambang
  switch (suit) {
    case Suit::Hearts:   suitStr = "Hearts"; break;
    case Suit::Diamonds: suitStr = "Diamonds"; break;
    case Suit::Clubs:    suitStr = "Clubs"; break;
    case Suit::Spades:   suitStr = "Spades"; break;
  }

  return rankStr + " of " + suitStr; // Contoh hasil: "King of Hearts"
}

Rank Card::GetRank()
{
  return rank;
}