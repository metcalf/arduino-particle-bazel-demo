#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Wire.h"

#include "src/particle-bazel-demo.cpp"

using ::testing::_;
using ::testing::InSequence;

class MockWire : public TwoWire {
public:
  MockWire(): TwoWire(HAL_I2C_INTERFACE1, acquireWireBuffer()) {};

  MOCK_METHOD(size_t, write, (uint8_t), (override));
};

TEST(ExampleTest, DisplaySetup) {
  MockWire wire;
  {
    InSequence seq;

    EXPECT_CALL(wire, write(0x00)).Times(1);
    EXPECT_CALL(wire, write(0xAE)).Times(1);
    EXPECT_CALL(wire, write(_)).Times(33);
  }

  setup(&wire);
}
