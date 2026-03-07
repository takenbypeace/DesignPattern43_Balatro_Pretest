#pragma once
#include "IModifier.h"

class RandomBonus : public IModifier {
public:
  long long ApplyModifier(long long currentScore) override;
};