#pragma once
#include "resource.h" 
#include "LogDlg.h"

typedef std::vector<CPoint> CHART_ARRAY;

class Global
{
public:
	CString ServerName;
	CString ServerPort;
	CString Path2Config;
	CString CurPath;

	CLogDlg * pLogDlg;

	Global(void);
	~Global(void);

public:
	CString & SetLogPath();
	CString ReadParam(const char* valName, const char* section = "SETTINGS");
    void SaveParam(const char* valName, const char* value, const char* section = "SETTINGS");
	void SaveAllParams();
};

extern Global Glob;

