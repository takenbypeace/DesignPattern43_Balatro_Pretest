#pragma once
#include "modifiers/IModifier.h"
#include <vector>
#include "Card.h"

class Player {
private:
  // Tas untuk menyimpan kartu-kartu modifier yang sudah dibeli
  std::vector<IModifier*> activeModifiers;
  int money = 10;
  std::vector<Card> hand;

public:
  // Fungsi untuk memasukkan kartu baru ke dalam tas
  void AddModifier(IModifier* newModifier);
  // Fungsi baru untuk melihat isi tas
  std::vector<IModifier*> GetModifiers();

  int GetMoney();              // Untuk melihat sisa uang
  void AddMoney(int amount);   // Untuk menambah uang (hadiah menang ronde)
  bool SpendMoney(int amount); // Untuk memotong uang saat belanja

  void ReceiveCard(Card c); // Menerima kartu dari Deck
  void ShowHand();          // Menampilkan kartu apa saja yang dipegang
  Card PlayCard(int index); // Memilih satu kartu untuk dimainkan
  std::vector<Card> PlayCards(std::vector<int> indices);
  void ClearHand();         // Membuang sisa kartu saat ronde selesai
};