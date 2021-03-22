#include "ProtoApp.h"
#include "EvDBMain.h"
int main()
{
    // *********************************
    // * Load database accessor
    // *********************************
    try
    {
       EvDBMain::GetInstance();
    }
    catch (EvDBMain::DBException& ex)
    {
       std::cout << ex.GetReason();
    }
    ProtoApp::GetInstance();
}