#pragma once
#include "IModifier.h"

class TripleScoreModifier : public IModifier {
public:
  long long ApplyModifier(long long currentScore) override;
};