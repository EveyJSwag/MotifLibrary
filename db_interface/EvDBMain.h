#ifndef EVDBMAIN_H
#define EVDBMAIN_H

#include <oci.h>
#include <string.h>
#include <string>
#include <exception>
class EvDBMain
{
public:

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
   int Insert(const std::string& a_instr) throw(DBException);

   int Select(const unsigned char* a_outstr, const unsigned char* a_instr) throw(DBException);
   int Select(const std::string& a_outstr, const std::string& a_instr) throw(DBException);

private:
   static EvDBMain* instance;
   EvDBMain();
   EvDBMain(const unsigned char* a_hostname, const unsigned char* a_username, const unsigned char* a_password) throw(DBException);
   int Initialize();
   bool isInitialized;
};
#endif /* EVDBMAIN_H */ 