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
      const char* what() const throw()
      {
         return "Database Exception";
      }

   private:
      int line;
      char* file;
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
   EvDBMain(const std::string& a_hostname, const std::string& a_username, const std::string& a_password) throw(DBException);
   int Initialize();
   bool isInitialized;
};
#endif /* EVDBMAIN_H */ 