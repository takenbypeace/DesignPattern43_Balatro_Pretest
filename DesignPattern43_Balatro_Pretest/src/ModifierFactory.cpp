#include "ModifierFactory.h"
#include "modifiers/TripleScoreModifier.h"
#include "modifiers/RandomBonusModifier.h"

IModifier* ModifierFactory::CreateModifier(std::string modifierName)
{
  if (modifierName == "TripleScore") {
    return new TripleScoreModifier();
  }
  else if (modifierName == "RandomBonus") {
    return new RandomBonus();
  }

  // Jika namanya tidak dikenali, jangan buat apa-apa
  return nullptr;
}