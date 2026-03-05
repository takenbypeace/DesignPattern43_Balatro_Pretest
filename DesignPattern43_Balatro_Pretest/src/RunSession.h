#pragma once
#include <iostream>
#include "ScoringSystem.h"
#include "ShopSystem.h"

class RunSession {
private:
  int currentRound;
  int totalScore;

  ScoringSystem scoring;
  ShopSystem shop;

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