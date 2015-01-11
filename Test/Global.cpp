#include "StdAfx.h"
#include "Global.h"


Global::Global(void) : 
   CurPath(_T("")), 
   Path2Config(_T("")) 
{
	SetLogPath();
	ServerName = ReadParam("ServerName");
}

Global::~Global(void)
{

}

CString & Global::SetLogPath()
{
   CString buf;
   GetModuleFileName(GetModuleHandle(NULL), buf.GetBuffer(_MAX_PATH), _MAX_PATH );
   buf.ReleaseBuffer();

   CurPath = buf.Left(buf.ReverseFind('\\') + 1);

   Path2Config.Format( "%s%s", CurPath, "server_cfg.ini");
   
   return Path2Config;
}

CString Global::ReadParam(const char* valName, const char* section)
{
    char buf[_MAX_PATH];

    GetPrivateProfileString(section, valName, "", buf, _MAX_PATH, Path2Config.GetString());
    return CString(buf);
}

void Global::SaveParam(const char* valName, const char* value, const char* section)
{
    WritePrivateProfileString(section, valName, value, Path2Config.GetString());
}

void Global::SaveAllParams() 
{
	Glob.SaveParam("ServerName", Glob.ServerName);
}
