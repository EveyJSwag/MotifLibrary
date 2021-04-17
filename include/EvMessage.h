#ifndef EV_MESSAGE_H
#define EV_MESSAGE_H

#include <string>
#include <pthread.h>

enum msg_type_t
{
   STARTUP,
   DATABASE,
   DEFAULT
};

typedef struct 
message_t
{
   msg_type_t      msg_type;
   int             msg_code;
   std::string     msg_str;
} message_t;

class EvMessage
{
public:
   static EvMessage* GetInstance();
   void poll_message();

   message_t get_message()
   {
      return current_message;
   };

   void set_message(const message_t*);

private:
   EvMessage();

   static EvMessage* Singleton;

   message_t current_message;

   



};

#endif