#ifndef EVDBMAIN_H
#define EVDBMAIN_H

#include <oci.h>
#include <string.h>
#include <string>
#include <exception>
class EvDBMain
{
public:

   typedef enum db_status 
   {
      CONNECTING,
      HOST_UP,
      HOST_DOWN,
      DB_UP,
      DB_DOWN
   } db_status;

   class DBException : public std::exception
   {
   public:
      DBException(const unsigned int a_line, std::string& a_file, std::string& a_reason);
      std::string GetReason() {return reason;}

   private:
      int line;
      std::string file;
      std::string reason;
   };

   static EvDBMain* GetInstance();

   int Insert(const unsigned char* a_instr) throw(DBException);
   int Select(const unsigned char* a_instr, const unsigned char* a_outstr) throw(DBException);

   static db_status GetStatus(){return cur_status;}
   static bool GetIsInit(){return isInitialized;}

private:
   static EvDBMain* instance;
   static db_status cur_status;

   OCIEnv     *envhp  = NULL;
   OCIError   *errhp  = NULL;
   OCISession *authp  = (OCISession*) 0;
   OCIServer  *srvhp  = NULL;
   OCISvcCtx  *svchp  = NULL;
   OCIStmt    *stmthp = NULL;
   OCIDefine  *defnp  = (OCIDefine*) 0;

   EvDBMain();
   EvDBMain(const unsigned char* a_hostname, const unsigned char* a_username, const unsigned char* a_password) throw(DBException);

   void CreateEnv() throw(DBException);
   void ServerAttach() throw(DBException);
   void BeginSession() throw(DBException);

   typedef struct DBCreds
   {
      const char* hostname;
      const char* username;
      const char* password;
   } DBCreds;

   DBCreds creds;

   int Initialize();
   static bool isInitialized;
};
#endif /* EVDBMAIN_H */ 