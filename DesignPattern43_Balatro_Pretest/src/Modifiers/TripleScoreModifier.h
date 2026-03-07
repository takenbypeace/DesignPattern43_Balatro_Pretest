#pragma once
#include "IModifier.h"

class TripleScoreModifier : public IModifier {
public:
  int ApplyModifier(int currentScore) override;
};