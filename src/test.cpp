#include "ProtoApp.h"
#include "EvDBMain.h"
#include "EvMessage.h"
#include <pthread.h>

typedef void* (*WINDOW_THREAD_PROC)(void *);

void so_dumb()
{
    while(1)
    {

    }

}

void access_db();

int main()
{

    pthread_t db_tread_main_id;
    pthread_create(&db_tread_main_id, NULL, (WINDOW_THREAD_PROC)access_db, NULL);
    pthread_detach(db_tread_main_id);

    EvMessage* msg_ins = EvMessage::GetInstance();
    pthread_t message_thread_main_id;
    pthread_create(&message_thread_main_id, NULL, (WINDOW_THREAD_PROC)(&EvMessage::poll_message), msg_ins);
    pthread_detach(message_thread_main_id);

    ProtoApp::GetInstance();
}

void access_db()
{
    // *********************************
    // * Load database accessor
    // *********************************
    message_t msg_t;
    msg_t.msg_type = DATABASE;
    try
    {
       EvDBMain::GetInstance();
       msg_t.msg_str = "success";
       msg_t.msg_code = EvDBMain::DB_UP;
       EvMessage::GetInstance()->set_message(&msg_t);
    }
    catch (EvDBMain::DBException& ex)
    {
       std::cout << ex.GetReason();
       msg_t.msg_str = "failure";
       msg_t.msg_code = EvDBMain::DB_DOWN;
       EvMessage::GetInstance()->set_message(&msg_t);
    }

}