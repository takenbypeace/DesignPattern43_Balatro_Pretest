#pragma once
#include "IModifier.h"

class SquareScore : public IModifier {
public:
  // Kita menggunakan kata kunci 'override' untuk menimpa/mengisi fungsi dari IModifier
  int ApplyModifier(int currentScore) override;
};