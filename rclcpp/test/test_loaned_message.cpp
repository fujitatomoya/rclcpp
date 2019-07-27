// Copyright 2019 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <gtest/gtest.h>

#include "rclcpp/loaned_message.hpp"
#include "rclcpp/loaned_message_factory.hpp"

#include "test_msgs/msg/basic_types.hpp"

using LoanedMessageT = rclcpp::LoanedMessage<test_msgs::msg::BasicTypes>;
using LoanedMessageFactoryT = rclcpp::LoanedMessageFactory<test_msgs::msg::BasicTypes>;

TEST(TestLoanedMessage, initialize) {
  LoanedMessageFactoryT factory;
  auto loaned_msg_ptr = factory.loan_message();

  SUCCEED();
}

TEST(TestLoanedMessage, assign_values) {
  LoanedMessageFactoryT factory;
  auto loaned_msg_ptr = factory.loan_message();
  ASSERT_TRUE(loaned_msg_ptr->is_valid());
  loaned_msg_ptr->get().float32_value = 42;

  SUCCEED();
}
