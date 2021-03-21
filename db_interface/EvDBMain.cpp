#include "EvDBMain.h"
#include "SecretHeader.h"
#include <sstream>
EvDBMain* EvDBMain::instance;

EvDBMain* EvDBMain::GetInstance()
{
   if (! instance)
      instance = new EvDBMain((const unsigned char*)DB_HOST, (const unsigned char*)DB_USERNAME, (const unsigned char*)DB_PASSWORD);
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
   static const char* username = "system"; 
   static const char* password = "asdf";
   printf("%s\n", username);
   static OCIEnv *envhp = NULL;
   static OCIError *errhp = NULL;
   static sword status;
   OCIDescribe *dschndl1 = (OCIDescribe *) 0,
               *dschndl2 = (OCIDescribe *) 0,
               *dschndl3 = (OCIDescribe *) 0;

   OCISession *authp = (OCISession*) 0;
   OCIServer  *srvhp = NULL;
   OCISvcCtx  *svchp = NULL;
   OCIStmt    *inserthp = NULL,
              *stmthp   = NULL,
              *stmthp1  = NULL;
            
   OCIDefine  *defnp = (OCIDefine*) 0;

   OCIBind  *bnd1p = (OCIBind *) 0;             /* the first bind handle */
   OCIBind  *bnd2p = (OCIBind *) 0;             /* the second bind handle */
   OCIBind  *bnd3p = (OCIBind *) 0;             /* the third bind handle */
   OCIBind  *bnd4p = (OCIBind *) 0;             /* the fourth bind handle */
   OCIBind  *bnd5p = (OCIBind *) 0;             /* the fifth bind handle */
   OCIBind  *bnd6p = (OCIBind *) 0;             /* the sixth bind handle */

   sword errcode = 0;

   errcode = OCIEnvCreate(&envhp, 
                         (ub4)OCI_DEFAULT, 
                         (dvoid *)0, 
                         (dvoid * (*)(dvoid *, size_t)) 0, 
                         (dvoid * (*)(dvoid*, dvoid*, size_t)) 0,  
                         (void (*)(dvoid *, dvoid *))0, (size_t) 0, (dvoid **)0);

   OCIHandleAlloc((void *)envhp, (void **)&errhp, OCI_HTYPE_ERROR, 0, (dvoid **)0);
   OCIHandleAlloc((void *)envhp, (void **)&srvhp, OCI_HTYPE_SERVER, 0, (dvoid **)0);
   OCIHandleAlloc((void *)envhp, (void **)&svchp, OCI_HTYPE_SVCCTX, 0, (dvoid **)0);
   const char* connect_str = "ev-db";
   printf("%s\n", connect_str);
   errcode = OCIServerAttach(srvhp, errhp, (OraText*)connect_str, strlen(connect_str), 0);
   if (errcode < 0)
   {
      std::string file_str = __FILE__;
      std::string reason_str = "Failed to attach to Server";
      throw DBException(__LINE__, file_str, reason_str);
   }
}

int EvDBMain::Insert(const unsigned char* a_instr) throw(DBException)
{

}

int EvDBMain::Insert(const std::string& a_instr) throw(DBException)
{

}

int EvDBMain::Select(const unsigned char* a_outstr, const unsigned char* a_instr) throw(DBException)
{

}
int EvDBMain::Select(const std::string& a_outstr, const std::string& a_instr) throw(DBException)
{

}