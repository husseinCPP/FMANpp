#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

namespace fs = std::filesystem;

int main(int argc, char *argv[]) {
  // حوّل الوسائط إلى vector من string لسهولة التعامل
  std::vector<std::string> args(argv +, argv + argc);

  bool recursive = false;
  bool force = false;
  std::vector<fs::path> targets;

  for (const auto &arg : args) {
    if (arg.size() > 1 && arg[0] == '-') {
      // خيارات مثل -r أو -rf أو -f
      for (size_t i = 1; i < arg.size(); ++i) {
        switch (arg[i]) {
        case 'r':
          recursive = true;
          break;
        case 'f':
          force = true;
          break;
        default:
          std::cerr << "خيار غير معروف: -" << arg[i] << '\n';
          return 1;
        }
      }
    } else {
      targets.emplace_back(arg); // وسيط عادي (مسار)
    }
  }

  if (targets.empty()) {
    std::cerr << "الاستخدام: " << argv[0] << " [-rf] <path>...\n";
    return 1;
  }

  for (const auto &p : targets) {
    std::error_code ec;

    if (!fs::exists(p, ec)) {
      if (!force)
        std::cerr << "لا يوجد: " << p << '\n';
      continue;
    }

    if (fs::is_directory(p, ec) && !recursive) {
      std::cerr << p << " مجلد (استخدم -r)\n";
      continue;
    }

    if (recursive)
      fs::remove_all(p, ec);
    else
      fs::remove(p, ec);

    if (ec && !force)
      std::cerr << "فشل حذف " << p << ": " << ec.message() << '\n';
  }
}