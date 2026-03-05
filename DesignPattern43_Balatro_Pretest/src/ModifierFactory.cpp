#include "ModifierFactory.h"
#include "modifiers/SquareScoreModifier.h"
#include "modifiers/RandomBonusModifier.h"

IModifier* ModifierFactory::CreateModifier(std::string modifierName)
{
  if (modifierName == "SquareScore") {
    return new SquareScore();
  }
  else if (modifierName == "RandomBonus") {
    return new RandomBonus();
  }

  // Jika namanya tidak dikenali, jangan buat apa-apa
  return nullptr;
}