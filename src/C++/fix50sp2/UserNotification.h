#ifndef FIX50_USERNOTIFICATION_H
#define FIX50_USERNOTIFICATION_H

#include "Message.h"

namespace FIX50
{

  class UserNotification : public Message
  {
  public:
    UserNotification() : Message(MsgType()) {}
    UserNotification(const FIX::Message& m) : Message(m) {}
    UserNotification(const Message& m) : Message(m) {}
    UserNotification(const UserNotification& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("CB"); }

    UserNotification(
      const FIX::UserStatus& aUserStatus )
    : Message(MsgType())
    {
      set(aUserStatus);
    }

    FIELD_SET(*this, FIX::Username);
    FIELD_SET(*this, FIX::UserStatus);
    FIELD_SET(*this, FIX::Text);
    FIELD_SET(*this, FIX::EncodedTextLen);
    FIELD_SET(*this, FIX::EncodedText);
  };

}

#endif
