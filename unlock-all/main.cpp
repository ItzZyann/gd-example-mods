#include "incl.h"

bool GameStatsManager_isItemUnlocked() {
 return true;
}

__attribute__((constructor))
void libgame_loader() {
 // GameStatsManager::isItemUnlocked(UnlockType, int)
 _hook("_ZN16GameStatsManager14isItemUnlockedE10UnlockTypei",
  GameStatsManager_isItemUnlocked);
  
}