#include "EvMessage.h"
#include "EvDBMain.h"
#include "DBStatus.h"

EvMessage* EvMessage::Singleton;

EvMessage::EvMessage()
{
   current_message.msg_code = 0;
   current_message.msg_str  = "msg start";
   current_message.msg_type = STARTUP;
}

EvMessage* EvMessage::GetInstance()
{
   if (EvMessage::Singleton == NULL)
   {
       EvMessage::Singleton = new EvMessage();
   }
   return EvMessage::Singleton;
}

void EvMessage::set_message(const message_t* a_msg)
{
   current_message.msg_code = a_msg->msg_code;
   current_message.msg_str  = a_msg->msg_str;
   current_message.msg_type = a_msg->msg_type;
}

void EvMessage::poll_message()
{
   for (;;)
   {
      switch(current_message.msg_type)
      {
         case STARTUP:
            break;
         case DATABASE:
            switch (current_message.msg_code)
            {
               case EvDBMain::db_status::CONNECTING:
                  break;
               case EvDBMain::db_status::HOST_UP:
                  break;
               case EvDBMain::db_status::HOST_DOWN:
                  break;
               case EvDBMain::db_status::DB_UP:
                  break;
               case EvDBMain::db_status::DB_DOWN:
                  break;
            }
            break;
         case DEFAULT:
            break; 
      }
   }
}