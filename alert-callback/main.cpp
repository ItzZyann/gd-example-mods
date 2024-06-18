#include "incl.h"

class MyProtocol : public FLAlertLayerProtocol {
public:
 // Now we can use this protocol everywhere
 // Wether for any classes or functions
 // Since this is just an example, I will
 // be just adding the alert popup in this class.
 
 // This function is already on FLAlertLayerProtocol
 // Tho I didnt just mention this on class
 // This function is virtual.
 
 virtual void FLAlert_Clicked(FLAlertLayer* alert, bool isBtn2) {
  // To add a function for button one
  // Just make it that if(!isBtn2) or
  // use the else statement.
  
  if(isBtn2) {
   // Function for button 2 here.
   // Example:
   FLAlertLayer::create(
    nullptr,
    "Button 2",
    "This is button 2!",
    "OK", nullptr, 300)->show();
  } else {
   // Function for button 1 here.
   // Example:
   FLAlertLayer::create(
    nullptr,
    "Button 1",
    "This is button 1!",
    "OK", nullptr, 300)->show();
  }
 }
 
 void showAlert(CCObject*) {
  auto protocol = new MyProtocol();
  FLAlertLayer::create(
   protocol,
   "Hello",
   "Click any button.",
   "Alright",
   "Okay",
   330)->show();
 }
 
 static MyProtocol* get() {
  return new MyProtocol();
 }
};

void MenuLayer_onPlay(CCObject* pSender) {
 MyProtocol::get()->showAlert(pSender);
}

__attribute__((constructor))
void libgame_loader() {
 _hook("_ZN9MenuLayer6onPlayEPN7cocos2d8CCObjectE",
  MenuLayer_onPlay);
  
}