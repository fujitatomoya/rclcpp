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

#ifndef RCLCPP_LOANED_MESSAGE_HPP_
#define RCLCPP_LOANED_MESSAGE_HPP_

#include "rclcpp/loaned_message_factory.hpp"

namespace rclcpp
{

template<class MessageT>
class LoanedMessageFactory;

template<class MessageT>
class LoanedMessage
{
  friend class LoanedMessageFactory<MessageT>;

protected:
  LoanedMessage()
  : msg_(new MessageT())
  {}

  virtual ~LoanedMessage()
  {
    delete msg_;
  }

  LoanedMessage(const LoanedMessage<MessageT> & other) = delete;

  MessageT * msg_ = nullptr;

public:
  bool is_valid() const {
    return msg_ != nullptr;
  }

  MessageT & get() const {
    return *msg_;
  }
};

}  // namespace rclcpp

#endif  // RCLCPP_LOANED_MESSAGE_HPP_
