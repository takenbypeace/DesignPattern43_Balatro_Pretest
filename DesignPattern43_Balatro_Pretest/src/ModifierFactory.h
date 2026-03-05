#pragma once
#include "modifiers/IModifier.h"
#include <string>

class ModifierFactory {
public:
  // Fungsi untuk memproduksi modifier
  IModifier* CreateModifier(std::string modifierName);
};