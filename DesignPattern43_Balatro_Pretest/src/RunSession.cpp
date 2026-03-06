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

  while (currentRound <= 3) {
    std::cout << "\n--- Memulai Ronde " << currentRound << " ---" << std::endl;

    // 1. Tentukan target skor tiap ronde
    int targetScore = 0;
    if (currentRound == 1)
      targetScore = 40;
    else if (currentRound == 2)
      targetScore = 2000;
    else if (currentRound == 3)
      targetScore = 5000;

    std::cout << "Target Skor ronde ini: " << targetScore << std::endl;

    PlayHand();

    // 2. Minta juri menilai, apakah tembus target?
    bool isWin = CalculateScore(targetScore);

    // 3. Jika juri bilang kalah (false), hentikan permainan!
    if (isWin == false) {
      std::cout << "\n=== GAME OVER ===" << std::endl;
      break; // Perintah 'break' akan langsung menghancurkan putaran 'while'
    }

    // 4. Kalau menang dan belum ronde terakhir, silakan ke toko
    if (currentRound < 3) {
      EnterShop();
    }

    currentRound++;
  }

  EndRun();
}

void RunSession::PlayHand()
{
  int siap;
  std::cout << "Tekan 1 lalu Enter untuk memainkan kartu: ";
  std::cin >> siap; // Komputer akan "mengerem" di sini menunggu pemain!

  std::cout << ">> Memainkan kartu..." << std::endl;
}

bool RunSession::CalculateScore(int targetScore)
{
  int baseScore = scoring.CalculateBaseScore(50, player);
  totalScore = totalScore + baseScore;

  // Tampilkan skor dan bandingkan dengan target
  std::cout << ">> Mendapatkan skor: " << baseScore << " / Target: " << targetScore << std::endl;
  std::cout << ">> Total Skor sekarang: " << totalScore << std::endl;

  // Cek kondisi menang atau kalah
  if (baseScore >= targetScore) {
    int hadiah = 15;
    player.AddMoney(hadiah);
    std::cout << ">> TARGET TERCAPAI! Kamu mendapat hadiah $" << hadiah << "\n" << std::endl;
    return true; // Pemain menang, kembalikan 'true'
  }
  else {
    std::cout << ">> TARGET GAGAL! Skormu tidak mencukupi.\n" << std::endl;
    return false; // Pemain kalah, kembalikan 'false'
  }
}

void RunSession::EnterShop()
{
  shop.EnterShop(player);
}

void RunSession::EndRun()
{
  std::cout << "\n=== Run Selesai ===" << std::endl;
  std::cout << "Skor Akhir: " << totalScore << std::endl;
}