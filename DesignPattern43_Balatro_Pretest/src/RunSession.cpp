#include "RunSession.h"
#include <iostream>

// Constructor: Menyiapkan nilai awal
RunSession::RunSession()
{
  currentRound = 1;
  totalScore = 0;
}

void RunSession::StartRun()
{
  std::cout << "\n=== Memulai Run Baru ===" << std::endl;
  std::cout << "Skor Awal: " << totalScore << std::endl;
}

void RunSession::RunLoop()
{
  StartRun();

  // Mengulang selama ronde masih kurang dari atau sama dengan 3
  while (currentRound <= 3) {
    std::cout << "\n--- Memulai Ronde " << currentRound << " ---" << std::endl;

    PlayHand();
    CalculateScore();
    EnterShop();

    currentRound++; // Ini bagian yang sangat penting!
  }

  EndRun();
}

void RunSession::PlayHand()
{
  std::cout << "Pemain memainkan kartu..." << std::endl;
}

void RunSession::CalculateScore()
{
  std::cout << "Menghitung skor..." << std::endl;
}

void RunSession::EnterShop()
{
  std::cout << "Masuk ke toko (Shop)..." << std::endl;
}

void RunSession::EndRun()
{
  std::cout << "\n=== Run Selesai ===" << std::endl;
  std::cout << "Skor Akhir: " << totalScore << std::endl;
}