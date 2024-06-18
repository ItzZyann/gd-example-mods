#include "incl.h"

void PlayLayer_destroyPlayer(void* p0, void* p1) {

 /* This is just a static hook,
 we dont need to return so that it
 avoids the player from dying.
 */
 
 return;
}

__attribute__((constructor))
void libgame_loader() {
 // PlayLayer::destroyPlayer(PlayerObject* p0, GameObject* p1)
 _hook("_ZN9PlayLayer13destroyPlayerEP12PlayerObjectP10GameObject",
  PlayLayer_destroyPlayer);
  
}