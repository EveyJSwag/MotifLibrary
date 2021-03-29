#include "EvDBMain.h"
#include "SecretHeader.h"
#include <iostream>
#include <sstream>

EvDBMain* EvDBMain::instance;
EvDBMain::db_status EvDBMain::cur_status = EvDBMain::db_status::CONNECTING;
bool EvDBMain::isInitialized = false;

EvDBMain* EvDBMain::GetInstance()
{
   if (! instance)
   {
      instance = new EvDBMain(
         (const unsigned char*)DB_HOST, 
         (const unsigned char*)DB_USERNAME, 
         (const unsigned char*)DB_PASSWORD);
   }
   else if(EvDBMain::cur_status == HOST_DOWN or EvDBMain::cur_status == DB_DOWN)
   {
      free(instance);
      instance = new EvDBMain(
         (const unsigned char*)DB_HOST, 
         (const unsigned char*)DB_USERNAME, 
         (const unsigned char*)DB_PASSWORD);
   }
   return instance;
}

EvDBMain::DBException::DBException(const unsigned int a_line, std::string& a_file, std::string& a_reason)
{
   line = a_line;
   file = a_file;
   std::ostringstream full_reason;
   full_reason << file << ":" << line << "\n" << a_reason << std::endl;
   reason = full_reason.str();
}

EvDBMain::EvDBMain(const unsigned char* a_hostname, const unsigned char* a_username, const unsigned char* a_password) throw(DBException)
{
   creds.hostname = (char *)a_hostname;
   creds.username = (char *)a_username;
   creds.password = (char *)a_password;

   try 
   {
      CreateEnv();
      ServerAttach();
      BeginSession();
      isInitialized = true;
   }
   catch (DBException& ex)
   {
      std::cout << ex.GetReason();
   }
}

void EvDBMain::CreateEnv() throw (DBException)
{
   sword errcode = 0;

   errcode = OCIEnvCreate(&envhp, 
                         (ub4)OCI_DEFAULT, 
                         (dvoid *)0, 
                         (dvoid * (*)(dvoid *, size_t)) 0, 
                         (dvoid * (*)(dvoid*, dvoid*, size_t)) 0,  
                         (void (*)(dvoid *, dvoid *))0, (size_t) 0, (dvoid **)0);
   
   if (errcode < 0)
   {
      cur_status = EvDBMain::db_status::HOST_DOWN;
      std::string file_str = __FILE__;
      std::string reason_str = "Failed to create ENV";
      throw DBException(__LINE__, file_str, reason_str);
   }
}

void EvDBMain::ServerAttach() throw (DBException)
{
   OCIHandleAlloc((void *)envhp, (void **)&errhp, OCI_HTYPE_ERROR, 0, (dvoid **)0);
   OCIHandleAlloc((void *)envhp, (void **)&srvhp, OCI_HTYPE_SERVER, 0, (dvoid **)0);
   OCIHandleAlloc((void *)envhp, (void **)&svchp, OCI_HTYPE_SVCCTX, 0, (dvoid **)0);

   sword errcode = OCIServerAttach(srvhp, errhp, (OraText*)creds.hostname, strlen((char *)creds.hostname), 0);

   if (errcode < 0)
   {
      cur_status = EvDBMain::db_status::HOST_DOWN;
      std::string file_str = __FILE__;
      std::string reason_str = "Failed to attach to Server";
      throw DBException(__LINE__, file_str, reason_str);
   }
}

void EvDBMain::BeginSession() throw (DBException)
{
   OCIAttrSet((void *)svchp, OCI_HTYPE_SVCCTX, (void *)srvhp, 0, OCI_ATTR_SERVER, (OCIError *)errhp);
   OCIHandleAlloc(envhp, (void **)&authp, OCI_HTYPE_SESSION, 0, (void **)0);
   OCIAttrSet((void *)authp, OCI_HTYPE_SESSION, (void *)creds.username, strlen((char *)creds.username),OCI_ATTR_USERNAME, (OCIError *)errhp);
   OCIAttrSet((void *)authp, OCI_HTYPE_SESSION, (void *)creds.password, strlen((char *)creds.password),OCI_ATTR_PASSWORD, (OCIError *)errhp);

   sword errcode = OCISessionBegin(svchp, errhp, authp, OCI_CRED_RDBMS, OCI_DEFAULT);
   if (errcode < 0)
   {
      cur_status = EvDBMain::db_status::HOST_DOWN;
      std::string file_str = __FILE__;
      std::string reason_str = "Failed to begin the session";
      throw DBException(__LINE__, file_str, reason_str);
   }

   OCIAttrSet((void *)svchp, OCI_HTYPE_SVCCTX, authp, 0, OCI_ATTR_SESSION, errhp);
   cur_status = EvDBMain::db_status::DB_UP;
}

int EvDBMain::Insert(const unsigned char* a_instr) throw(DBException)
{

}

int EvDBMain::Select(const unsigned char* a_instr, const unsigned char* a_outstr) throw(DBException)
{
   sword errcode = 0;
   
   OCIHandleAlloc(envhp, (void **)&stmthp, OCI_HTYPE_STMT, 0, (void**)0);

   OCIStmtPrepare(stmthp, errhp, (OraText*)a_instr, strlen((char *)a_instr), OCI_NTV_SYNTAX, OCI_DEFAULT);

   errcode = OCIDefineByPos(stmthp, &defnp, errhp, 1, (void *)a_outstr, 100, SQLT_CHR, (void*) 0, (ub2 *)0, (ub2 *)0, OCI_DEFAULT);
   if (errcode < 0)
   {
      std::string file_str = __FILE__;
      std::string reason_str = "OCIDefineByPos failed";
      throw DBException(__LINE__, file_str, reason_str);
   }

   errcode = OCIStmtExecute(svchp, stmthp, errhp, 1, 0, NULL, NULL, OCI_DEFAULT);
   if (errcode < 0)
   {
      std::string file_str = __FILE__;
      std::string reason_str = "OCIStmtExecute failed";
      throw DBException(__LINE__, file_str, reason_str);
   }
}