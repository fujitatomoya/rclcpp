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

#ifndef RCLCPP_LOANED_MESSAGE_FACTORY_HPP_
#define RCLCPP_LOANED_MESSAGE_FACTORY_HPP_

#include "rclcpp/loaned_message.hpp"

namespace rclcpp
{

template<class MessageT>
class LoanedMessage;

template<class MessageT>
class LoanedMessageFactory
{
public:
  LoanedMessageFactory() = default;

  auto loan_message() const
  {
    auto deleter = std::bind(
      &LoanedMessageFactory<MessageT>::return_message, this, std::placeholders::_1);
    return std::unique_ptr<LoanedMessage<MessageT>, decltype(deleter)>(
      new LoanedMessage<MessageT>(), deleter);
  }

private:
  void return_message(LoanedMessage<MessageT> * ptr) const
  {
    delete ptr;
  }
};

}  // namespace rclcpp

#endif  // RCLCPP_LOANED_MESSAGE_FACTORY_HPP_
