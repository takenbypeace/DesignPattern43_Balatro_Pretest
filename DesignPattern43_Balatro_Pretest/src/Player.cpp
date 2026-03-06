#include "Player.h"
#include <iostream>
#include <algorithm>

void Player::AddModifier(IModifier* newModifier)
{
  // Memasukkan kartu baru ke urutan paling belakang di dalam tas
  activeModifiers.push_back(newModifier);
}

std::vector<IModifier*> Player::GetModifiers()
{
  // Mengembalikan seluruh isi tas
  return activeModifiers;
}

int Player::GetMoney()
{
  return money;
}

void Player::AddMoney(int amount)
{
  money = money + amount;
}

bool Player::SpendMoney(int amount)
{
  // Cek dulu, apakah uangnya cukup untuk membayar?
  if (money >= amount) {
    money = money - amount; // Potong uangnya
    return true;            // Transaksi berhasil
  }
  else {
    return false; // Transaksi gagal, uang tidak cukup!
  }
}

// Menerima kartu dan memasukkannya ke tangan
void Player::ReceiveCard(Card c)
{
  hand.push_back(c);
}

// Menampilkan jejeran kartu di layar
void Player::ShowHand()
{
  std::cout << "\n--- Kartu di Tanganmu ---" << std::endl;
  for (int i = 0; i < hand.size(); i++) {
    // Menampilkan format: "1. Ace of Spades (Nilai: 11)"
    std::cout << i + 1 << ". " << hand[i].ToString() << " (Nilai: " << hand[i].GetValue() << ")"
              << std::endl;
  }
}

// Mengeluarkan kartu dari tangan untuk dimainkan
Card Player::PlayCard(int index)
{
  Card playedCard = hand[index];    // Ambil kartunya
  hand.erase(hand.begin() + index); // Hapus kartu itu dari tangan
  return playedCard;                // Serahkan ke meja permainan
}

// Membuang semua kartu di akhir ronde
void Player::ClearHand()
{
  hand.clear();
}

// Fungsi baru untuk memainkan lebih dari 1 kartu
std::vector<Card> Player::PlayCards(std::vector<int> indices)
{
  std::vector<Card> playedCards;

  // Trik C++: Urutkan index pilihan dari yang TERBESAR ke TERKECIL
  // Supaya saat kartu dihapus, urutan kartu di depannya tidak bergeser!
  std::sort(indices.begin(), indices.end(), std::greater<int>());

  for (int index : indices) {
    // Cek agar tidak error kalau pemain salah ketik angka yang kebesaran
    if (index >= 0 && index < hand.size()) {
      playedCards.push_back(hand[index]);
      hand.erase(hand.begin() + index); // Hapus kartu dari tangan
    }
  }
  return playedCards;
}