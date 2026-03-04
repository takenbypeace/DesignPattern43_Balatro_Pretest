#pragma once
#include <iostream>

class RunSession {
private:
  int currentRound;
  int totalScore;

  // Nanti kita akan memanggil kelas ScoringSystem dan ShopSystem di sini

public:
  RunSession(); // Constructor untuk menyiapkan nilai awal saat game mulai

  // Fungsi-fungsi ini secara langsung mewakili siklus permainan
  void StartRun();
  void PlayHand();
  void CalculateScore();
  void EnterShop();
  void EndRun();

  // Fungsi utama untuk mengatur perulangan ronde (Repeat)
  void RunLoop();
};