#pragma once
class Global
{
public:
	CString ServerName;
	CString Path2Config;
	CString CurPath;

	Global(void);
	~Global(void);

public:
	CString & SetLogPath();
	CString ReadParam(const char* valName, const char* section = "SETTINGS");
    void SaveParam(const char* valName, const char* value, const char* section = "SETTINGS");
	void SaveAllParams();
};

extern Global Glob;

