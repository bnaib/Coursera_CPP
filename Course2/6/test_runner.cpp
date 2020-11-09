#include "test_runner.h"

void Assert(bool b, const std::string& hint) {
  AssertEqual(b, true, hint);
}

TestRunner::~TestRunner()
{
  if (fail_count > 0) {
    std::cerr << "FAILED (failures = " << fail_count << ")" << std::endl;
    exit(1);
  }
  std::cerr << "OK" << std::endl;
}
