#include "AdvancedKeybinder.h"

#include <StreamDeckSDK/ESDMain.h>

int main(int argc, const char** argv) {
  auto plugin = std::make_unique<AdvancedKeybinder>();
  return esd_main(argc, argv, plugin.get());
}