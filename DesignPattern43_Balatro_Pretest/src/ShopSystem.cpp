#include "ShopSystem.h"
#include "ModifierFactory.h"
#include <iostream>

void ShopSystem::EnterShop(Player& pembeli)
{
  ModifierFactory pabrik;
  bool masihDiToko = true; // Kunci untuk mengulang menu toko

  std::cout << "\n=== MEMASUKI TOKO MODIFIER ===" << std::endl;

  // Selama pemain masih di toko, tampilkan terus etalasenya
  while (masihDiToko) {
    int pilihan;
    std::cout << "\n--- ETALASE TOKO ---" << std::endl;
    std::cout << "Uangmu saat ini: $" << pembeli.GetMoney() << std::endl;
    std::cout << "1. Beli Random Bonus Modifier ($5)" << std::endl;
    std::cout << "2. Beli Square Score Modifier ($10)" << std::endl;
    std::cout << "3. Keluar dari Toko (Lanjut Ronde Berikutnya)" << std::endl;
    std::cout << "Pilihanmu: ";

    std::cin >> pilihan; // Menangkap angka yang diketik pemain

    if (pilihan == 1) {
      if (pembeli.SpendMoney(5)) {
        std::cout << ">> Transaksi Berhasil! Kamu mendapatkan Random Bonus." << std::endl;
        // Memesan kartu RandomBonus dan menyimpannya di wadahKartu
        IModifier* wadahKartu = pabrik.CreateModifier("RandomBonus");
        pembeli.AddModifier(wadahKartu);
      }
      else {
        std::cout << ">> Maaf, uangmu tidak cukup untuk membeli ini!" << std::endl;
      }
    }
    else if (pilihan == 2) {
      if (pembeli.SpendMoney(10)) {
        std::cout << ">> Transaksi Berhasil! Kamu mendapatkan Square Score." << std::endl;
        // Memesan kartu Square dan menyimpannya di wadahKartu
        IModifier* wadahKartu = pabrik.CreateModifier("SquareScore");
        pembeli.AddModifier(wadahKartu);
      }
      else {
        std::cout << ">> Maaf, uangmu tidak cukup untuk membeli ini!" << std::endl;
      }
    }
    else if (pilihan == 3) {
      std::cout << ">> Kamu meninggalkan toko..." << std::endl;
      masihDiToko = false; // Mengubah kunci menjadi false agar loop berhenti
    }
    else {
      std::cout << ">> Pilihan tidak valid, silakan masukkan angka 1, 2, atau 3." << std::endl;
    }
  }
}