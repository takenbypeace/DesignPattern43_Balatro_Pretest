#include "ShopSystem.h"
#include <iostream>

void ShopSystem::EnterShop()
{
  int pilihan;
  std::cout << "=== TOKO MODIFIER ===" << std::endl;
  std::cout << "1. Beli Modifier" << std::endl;
  std::cout << "2. Lanjut ke Ronde Berikutnya" << std::endl;
  std::cout << "Pilihanmu: ";

  std::cin >> pilihan; // Menangkap angka yang diketik pemain

  if (pilihan == 1) {
    std::cout << "Kamu memilih untuk membeli modifier!" << std::endl;
    // Nanti kita akan menyuruh pabrik membuat modifier di sini
  }
  else if (pilihan == 2) {
    std::cout << "Kamu memilih lanjut bermain." << std::endl;
  }
  else {
    std::cout << "Pilihan tidak valid!" << std::endl;
  }
}