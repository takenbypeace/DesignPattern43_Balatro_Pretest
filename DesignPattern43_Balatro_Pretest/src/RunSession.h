#pragma once
#include <iostream>
#include "ScoringSystem.h"
#include "ShopSystem.h"
#include "Player.h"
#include "Deck.h"
#include "HandEvaluator.h"

class RunSession {
private:
  int currentRound;
  int totalScore;

  Player player;
  ScoringSystem scoring;
  ShopSystem shop;
  Deck deck;

public:
  RunSession();
  void StartRun();

  std::vector<Card> PlayHand();

  bool CalculateScore(int targetScore, std::vector<Card> playedCards);

  void EnterShop();
  void EndRun();
  void RunLoop();
};