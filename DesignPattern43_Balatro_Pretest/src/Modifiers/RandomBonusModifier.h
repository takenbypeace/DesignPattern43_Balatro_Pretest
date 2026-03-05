#pragma once
#include "IModifier.h"

class RandomBonus : public IModifier {
public:
  int ApplyModifier(int currentScore) override;
};