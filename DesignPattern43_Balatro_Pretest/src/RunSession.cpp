#include "RunSession.h"
#include <iostream>
#include <sstream>
#include <string>

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

  // Siapkan 52 kartu dan kocok sebelum main
  deck.InitializeDeck();
  deck.Shuffle();
}

void RunSession::RunLoop()
{
  StartRun();

  while (currentRound <= 3) {
    std::cout << "\n--- Memulai Ronde " << currentRound << " ---" << std::endl;

    // 1. Tentukan target skor tiap ronde
    int targetScore = 0;
    if (currentRound == 1)
      targetScore = 10; 
    else if (currentRound == 2)
      targetScore = 100; 
    else if (currentRound == 3)
      targetScore = 1000;

    std::cout << "Target Skor ronde ini: " << targetScore << std::endl;
    std::cout << "Uangmu saat ini: $" << player.GetMoney() << std::endl;

    // --- FASE PEMBAGIAN KARTU ---
    // Tarik 5 kartu dari atas tumpukan dan berikan ke tangan pemain
    for (int i = 0; i < 5; i++) {
      player.ReceiveCard(deck.DrawCard());
    }

    // Memilih kartu dan menyimpan nilai kartu yang dimainkan
    std::vector<Card> kartuYangDimainkan = PlayHand();

    // 2. Minta juri menilai, apakah tembus target? (Sekarang pakai nilai kartu asli)
    bool isWin = CalculateScore(targetScore, kartuYangDimainkan);

    // Bersihkan kartu dari tangan pemain untuk ronde berikutnya
    player.ClearHand();

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

// ... (RunLoop biarkan sama, kita cuma ubah 2 fungsi di bawahnya)

std::vector<Card> RunSession::PlayHand()
{
  player.ShowHand();

  std::cout << "\nPilih nomor kartu (pisahkan dengan spasi, maks 5). Contoh: 1 3 4\n";
  std::cout << "Pilihanmu: ";

  std::string input;
  // Bersihkan sisa tombol "Enter" dari input sebelumnya agar tidak error
  if (std::cin.peek() == '\n')
    std::cin.ignore();
  std::getline(std::cin, input);

  // Alat bantu untuk memecah teks "1 3 4" menjadi angka terpisah
  std::stringstream ss(input);
  std::vector<int> pilihan;
  int nomor;
  while (ss >> nomor) {
    pilihan.push_back(nomor - 1); // Kurangi 1 karena komputer menghitung dari 0
  }

  std::vector<Card> dimainkan = player.PlayCards(pilihan);

  std::cout << "\n>> Kamu memainkan " << dimainkan.size() << " kartu!" << std::endl;
  return dimainkan; // Kirim kumpulan kartu ini ke juri
}

bool RunSession::CalculateScore(int targetScore, std::vector<Card> playedCards)
{
  // 1. Serahkan ke Juri untuk dinilai kombonya!
  HandInfo vonis = HandEvaluator::EvaluateHand(playedCards);

  std::cout << "\n=== HASIL JURI ===" << std::endl;
  std::cout << "Kombo: " << vonis.name << "!" << std::endl;

  // 2. Hitung total Chips dari nilai asli kartu-kartu yang dimainkan
  int totalCardChips = 0;
  for (Card c : playedCards) {
    totalCardChips += c.GetValue();
  }

  // 3. RUMUS BALATRO ASLI: (Chips Kombo + Chips Kartu) * Mult Kombo
  int totalChips = vonis.chips + totalCardChips;
  int skorKombo = totalChips * vonis.mult;

  std::cout << "Hitungan: (" << vonis.chips << " Chips Kombo + " << totalCardChips
            << " Chips Kartu) x " << vonis.mult << " Mult\n";

  // 4. Masukkan skor ini ke sistem modifikator toko milikmu!
  int finalScore = scoring.CalculateBaseScore(skorKombo, player);
  totalScore = totalScore + finalScore;

  // Tampilkan skor dan bandingkan dengan target
  std::cout << ">> Mendapatkan skor: " << finalScore << " / Target: " << targetScore << std::endl;
  std::cout << ">> Total Skor sekarang: " << totalScore << std::endl;

  if (finalScore >= targetScore) {
    int hadiah = 15;
    player.AddMoney(hadiah);
    std::cout << ">> TARGET TERCAPAI! Kamu mendapat hadiah $" << hadiah << "\n" << std::endl;
    return true;
  }
  else {
    std::cout << ">> TARGET GAGAL! Skormu tidak mencukupi.\n" << std::endl;
    return false;
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