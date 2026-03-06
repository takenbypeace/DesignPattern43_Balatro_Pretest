#include "Player.h"

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