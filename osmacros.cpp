#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

namespace
{
   #define TOSTRING(x) #x

   #ifdef _WIN32
   #define ISDEFINED_WIN32 true
   #else
   #define ISDEFINED_WIN32 false
   #endif

   #ifdef __APPLE__
   #define ISDEFINED_APPLE true
   #else
   #define ISDEFINED_APPLE false
   #endif

   #ifdef MAC_OS_X_VERSION_NONEXISTANT
   #define ISDEFINED_NONEXISTANT true
   #else
   #define ISDEFINED_NONEXISTANT false
   #endif

   #ifdef MAC_OS_X_VERSION_10_0
   #define ISDEFINED_10_0 true
   #else
   #define ISDEFINED_10_0 false
   #endif

   #ifdef MAC_OS_X_VERSION_10_1
   #define ISDEFINED_10_1 true
   #else
   #define ISDEFINED_10_1 false
   #endif

   #ifdef MAC_OS_X_VERSION_10_2
   #define ISDEFINED_10_2 true
   #else
   #define ISDEFINED_10_2 false
   #endif

   #ifdef MAC_OS_X_VERSION_10_3
   #define ISDEFINED_10_3 true
   #else
   #define ISDEFINED_10_3 false
   #endif

   #ifdef MAC_OS_X_VERSION_10_4
   #define ISDEFINED_10_4 true
   #else
   #define ISDEFINED_10_4 false
   #endif

   #ifdef MAC_OS_X_VERSION_10_5
   #define ISDEFINED_10_5 true
   #else
   #define ISDEFINED_10_5 false
   #endif

   #ifdef MAC_OS_X_VERSION_10_6
   #define ISDEFINED_10_6 true
   #else
   #define ISDEFINED_10_6 false
   #endif

   #ifdef MAC_OS_X_VERSION_10_7
   #define ISDEFINED_10_7 true
   #else
   #define ISDEFINED_10_7 false
   #endif

   #ifdef MAC_OS_X_VERSION_10_8
   #define ISDEFINED_10_8 true
   #else
   #define ISDEFINED_10_8 false
   #endif

   #ifdef MAC_OS_X_VERSION_10_9
   #define ISDEFINED_10_9 true
   #else
   #define ISDEFINED_10_9 false
   #endif

   #ifdef MAC_OS_X_VERSION_10_10
   #define ISDEFINED_10_10 true
   #else
   #define ISDEFINED_10_10 false
   #endif

   #ifdef MAC_OS_X_VERSION_10_10_2
   #define ISDEFINED_10_10_2 true
   #else
   #define ISDEFINED_10_10_2 false
   #endif

   #ifdef MAC_OS_X_VERSION_10_10_3
   #define ISDEFINED_10_10_3 true
   #else
   #define ISDEFINED_10_10_3 false
   #endif

   #ifdef MAC_OS_X_VERSION_10_11
   #define ISDEFINED_10_11 true
   #else
   #define ISDEFINED_10_11 false
   #endif

   #ifdef MAC_OS_X_VERSION_10_11_2
   #define ISDEFINED_10_11_2 true
   #else
   #define ISDEFINED_10_11_2 false
   #endif

   #ifdef MAC_OS_X_VERSION_10_11_3
   #define ISDEFINED_10_11_3 true
   #else
   #define ISDEFINED_10_11_3 false
   #endif

   #ifdef MAC_OS_X_VERSION_10_11_4
   #define ISDEFINED_10_11_4 true
   #else
   #define ISDEFINED_10_11_4 false
   #endif

   #ifdef MAC_OS_X_VERSION_10_12
   #define ISDEFINED_10_12 true
   #else
   #define ISDEFINED_10_12 false
   #endif

   #ifdef MAC_OS_X_VERSION_10_12_1
   #define ISDEFINED_10_12_1 true
   #else
   #define ISDEFINED_10_12_1 false
   #endif

   #ifdef MAC_OS_X_VERSION_10_12_2
   #define ISDEFINED_10_12_2 true
   #else
   #define ISDEFINED_10_12_2 false
   #endif

   #ifdef MAC_OS_X_VERSION_10_12_4
   #define ISDEFINED_10_12_4 true
   #else
   #define ISDEFINED_10_12_4 false
   #endif

   #ifdef MAC_OS_X_VERSION_10_13
   #define ISDEFINED_10_13 true
   #else
   #define ISDEFINED_10_13 false
   #endif

   #ifdef MAC_OS_X_VERSION_10_13_1
   #define ISDEFINED_10_13_1 true
   #else
   #define ISDEFINED_10_13_1 false
   #endif

   #ifdef MAC_OS_X_VERSION_10_13_2
   #define ISDEFINED_10_13_2 true
   #else
   #define ISDEFINED_10_13_2 false
   #endif

   #ifdef MAC_OS_X_VERSION_10_13_4
   #define ISDEFINED_10_13_4 true
   #else
   #define ISDEFINED_10_13_4 false
   #endif

   #ifdef MAC_OS_X_VERSION_10_14
   #define ISDEFINED_10_14 true
   #else
   #define ISDEFINED_10_14 false
   #endif

   #ifdef MAC_OS_X_VERSION_10_14_1
   #define ISDEFINED_10_14_1 true
   #else
   #define ISDEFINED_10_14_1 false
   #endif

   #ifdef MAC_OS_X_VERSION_10_14_4
   #define ISDEFINED_10_14_4 true
   #else
   #define ISDEFINED_10_14_4 false
   #endif

   #ifdef MAC_OS_X_VERSION_10_15
   #define ISDEFINED_10_15 true
   #else
   #define ISDEFINED_10_15 false
   #endif

   #ifdef MAC_OS_X_VERSION_10_15_1
   #define ISDEFINED_10_15_1 true
   #else
   #define ISDEFINED_10_15_1 false
   #endif

   void checkAndStoreMacro(const std::string& macroName, bool isDefined, std::vector<std::pair<std::string, bool>>& map) {
      map.push_back({ macroName, isDefined });
   }

   std::string rightPad(const std::string& str, size_t totalLength, char padChar = ' ') {
      std::ostringstream oss;
      oss << std::left << std::setw(totalLength) << std::setfill(padChar) << str;
      return oss.str();
   }
}

namespace osmacros
{
   void print() {
      std::vector<std::pair<std::string, bool>> macroDefs;

      // Check and store the status of each macro
      checkAndStoreMacro(TOSTRING(_WIN32), ISDEFINED_WIN32, macroDefs);
      checkAndStoreMacro(TOSTRING(__APPLE__), ISDEFINED_APPLE, macroDefs);
      checkAndStoreMacro(TOSTRING(MAC_OS_X_VERSION_NONEXISTANT), ISDEFINED_NONEXISTANT, macroDefs);
      checkAndStoreMacro(TOSTRING(MAC_OS_X_VERSION_10_0), ISDEFINED_10_0, macroDefs);
      checkAndStoreMacro(TOSTRING(MAC_OS_X_VERSION_10_1), ISDEFINED_10_1, macroDefs);
      checkAndStoreMacro(TOSTRING(MAC_OS_X_VERSION_10_2), ISDEFINED_10_2, macroDefs);
      checkAndStoreMacro(TOSTRING(MAC_OS_X_VERSION_10_3), ISDEFINED_10_3, macroDefs);
      checkAndStoreMacro(TOSTRING(MAC_OS_X_VERSION_10_4), ISDEFINED_10_4, macroDefs);
      checkAndStoreMacro(TOSTRING(MAC_OS_X_VERSION_10_5), ISDEFINED_10_5, macroDefs);
      checkAndStoreMacro(TOSTRING(MAC_OS_X_VERSION_10_6), ISDEFINED_10_6, macroDefs);
      checkAndStoreMacro(TOSTRING(MAC_OS_X_VERSION_10_7), ISDEFINED_10_7, macroDefs);
      checkAndStoreMacro(TOSTRING(MAC_OS_X_VERSION_10_8), ISDEFINED_10_8, macroDefs);
      checkAndStoreMacro(TOSTRING(MAC_OS_X_VERSION_10_9), ISDEFINED_10_9, macroDefs);
      checkAndStoreMacro(TOSTRING(MAC_OS_X_VERSION_10_10), ISDEFINED_10_10, macroDefs);
      checkAndStoreMacro(TOSTRING(MAC_OS_X_VERSION_10_10_2), ISDEFINED_10_10_2, macroDefs);
      checkAndStoreMacro(TOSTRING(MAC_OS_X_VERSION_10_10_3), ISDEFINED_10_10_3, macroDefs);
      checkAndStoreMacro(TOSTRING(MAC_OS_X_VERSION_10_11), ISDEFINED_10_11, macroDefs);
      checkAndStoreMacro(TOSTRING(MAC_OS_X_VERSION_10_11_2), ISDEFINED_10_11_2, macroDefs);
      checkAndStoreMacro(TOSTRING(MAC_OS_X_VERSION_10_11_3), ISDEFINED_10_11_3, macroDefs);
      checkAndStoreMacro(TOSTRING(MAC_OS_X_VERSION_10_11_4), ISDEFINED_10_11_4, macroDefs);
      checkAndStoreMacro(TOSTRING(MAC_OS_X_VERSION_10_12), ISDEFINED_10_12, macroDefs);
      checkAndStoreMacro(TOSTRING(MAC_OS_X_VERSION_10_12_1), ISDEFINED_10_12_1, macroDefs);
      checkAndStoreMacro(TOSTRING(MAC_OS_X_VERSION_10_12_2), ISDEFINED_10_12_2, macroDefs);
      checkAndStoreMacro(TOSTRING(MAC_OS_X_VERSION_10_12_4), ISDEFINED_10_12_4, macroDefs);
      checkAndStoreMacro(TOSTRING(MAC_OS_X_VERSION_10_13), ISDEFINED_10_13, macroDefs);
      checkAndStoreMacro(TOSTRING(MAC_OS_X_VERSION_10_13_1), ISDEFINED_10_13_1, macroDefs);
      checkAndStoreMacro(TOSTRING(MAC_OS_X_VERSION_10_13_2), ISDEFINED_10_13_2, macroDefs);
      checkAndStoreMacro(TOSTRING(MAC_OS_X_VERSION_10_13_4), ISDEFINED_10_13_4, macroDefs);
      checkAndStoreMacro(TOSTRING(MAC_OS_X_VERSION_10_14), ISDEFINED_10_14, macroDefs);
      checkAndStoreMacro(TOSTRING(MAC_OS_X_VERSION_10_14_1), ISDEFINED_10_14_1, macroDefs);
      checkAndStoreMacro(TOSTRING(MAC_OS_X_VERSION_10_14_4), ISDEFINED_10_14_4, macroDefs);
      checkAndStoreMacro(TOSTRING(MAC_OS_X_VERSION_10_15), ISDEFINED_10_15, macroDefs);
      checkAndStoreMacro(TOSTRING(MAC_OS_X_VERSION_10_15_1), ISDEFINED_10_15_1, macroDefs);

      std::cout << "===== Macros defined? =====" << std::endl;
      auto maxLength = std::max_element(macroDefs.begin(), macroDefs.end(),
         [](auto a, auto b) { return a.first.length() < b.first.length(); })->first.length();
      for (const auto& entry : macroDefs) {
         std::cout << "- " << rightPad(entry.first, maxLength) << " : " << (entry.second ? "TRUE" : "FALSE") << std::endl;
      }
   }

}