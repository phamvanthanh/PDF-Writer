/*
   Source File : SafeBufferMacrosDefs.h


   Copyright 2011 Gal Kahana PDFWriter

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

   
*/
#pragma once

#ifdef WIN32
	#include "UnicodeString.h"
	#include <string>
	#include <sstream>
	static std::wstring UTF8ToUTF16Wide(const std::string& inUTF8String);

	std::wstring UTF8ToUTF16Wide(const std::string& inUTF8String)
	{
		UnicodeString unicodeString;
		unicodeString.FromUTF8(inUTF8String);

		EPDFStatusCodeAndUShortList result = unicodeString.ToUTF16UShort();
		
		std::wstringstream stream;

		UShortList::const_iterator it = result.second.begin();

		for(; it != result.second.end();++it)
			stream.put((wchar_t)*it);

		return stream.str();
	}

	#define	SAFE_SPRINTF_1(BUFFER,BUFFER_SIZE,FORMAT,ARG1) sprintf_s(BUFFER,BUFFER_SIZE,FORMAT,ARG1)
	#define	SAFE_SPRINTF_2(BUFFER,BUFFER_SIZE,FORMAT,ARG1,ARG2) sprintf_s(BUFFER,BUFFER_SIZE,FORMAT,ARG1,ARG2)
	#define	SAFE_SPRINTF_3(BUFFER,BUFFER_SIZE,FORMAT,ARG1,ARG2,ARG3) sprintf_s(BUFFER,BUFFER_SIZE,FORMAT,ARG1,ARG2,ARG3)
	#define	SAFE_SPRINTF_4(BUFFER,BUFFER_SIZE,FORMAT,ARG1,ARG2,ARG3,ARG4) sprintf_s(BUFFER,BUFFER_SIZE,FORMAT,ARG1,ARG2,ARG3,ARG4)
	#define	SAFE_SPRINTF_5(BUFFER,BUFFER_SIZE,FORMAT,ARG1,ARG2,ARG3,ARG4,ARG5) sprintf_s(BUFFER,BUFFER_SIZE,FORMAT,ARG1,ARG2,ARG3,ARG4,ARG5)
	#define SAFE_SPRINTF_6(BUFFER,BUFFER_SIZE,FORMAT,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) sprintf_s(BUFFER,BUFFER_SIZE,FORMAT,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6)
	#define	SAFE_SWPRINTF_1(BUFFER,BUFFER_SIZE,FORMAT,ARG1) swprintf_s(BUFFER,BUFFER_SIZE,FORMAT,ARG1)
	#define	SAFE_SWPRINTF_2(BUFFER,BUFFER_SIZE,FORMAT,ARG1,ARG2) swprintf_s(BUFFER,BUFFER_SIZE,FORMAT,ARG1,ARG2)
	#define	SAFE_SWPRINTF_3(BUFFER,BUFFER_SIZE,FORMAT,ARG1,ARG2,ARG3) swprintf_s(BUFFER,BUFFER_SIZE,FORMAT,ARG1,ARG2,ARG3)
	#define	SAFE_SWPRINTF_4(BUFFER,BUFFER_SIZE,FORMAT,ARG1,ARG2,ARG3,ARG4) swprintf_s(BUFFER,BUFFER_SIZE,FORMAT,ARG1,ARG2,ARG3,ARG4)
	#define	SAFE_SWPRINTF_5(BUFFER,BUFFER_SIZE,FORMAT,ARG1,ARG2,ARG3,ARG4,ARG5) swprintf_s(BUFFER,BUFFER_SIZE,FORMAT,ARG1,ARG2,ARG3,ARG4,ARG5)
	#define SAFE_SWPRINTF_6(BUFFER,BUFFER_SIZE,FORMAT,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) swprintf_s(BUFFER,BUFFER_SIZE,FORMAT,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6)
	#define SAFE_LOCAL_TIME(structuredLocalTime,currentTime) localtime_s(&structuredLocalTime,&currentTime)
	#define SAFE_VSWPRINTF(BUFFER,BUFFER_SIZE,FORMAT,ARGLIST) vswprintf_s(BUFFER,BUFFER_SIZE,FORMAT,ARGLIST)
	#define SAFE_VSPRINTF(BUFFER,BUFFER_SIZE,FORMAT,ARGLIST) vsprintf_s(BUFFER,BUFFER_SIZE,FORMAT,ARGLIST)
	#define SAFE_FOPEN(FILESTREAM_P,FILE_PATH,MODE) {if(_wfopen_s(&FILESTREAM_P,UTF8ToUTF16Wide(FILE_PATH).c_str(),UTF8ToUTF16Wide(MODE).c_str()) != 0) FILESTREAM_P = NULL;}
	#if _MSC_VER >= 1600
		#define SAFE_SGETN(BUFFER,BUFFER_SIZE,READ_COUNT) sgetn(BUFFER,READ_COUNT)
	#else
		#define SAFE_SGETN(BUFFER,BUFFER_SIZE,READ_COUNT) _Sgetn_s(BUFFER,BUFFER_SIZE,READ_COUNT)
	#endif
#else
	#define	SAFE_SPRINTF_1(BUFFER,BUFFER_SIZE,FORMAT,ARG1) sprintf(BUFFER,BUFFER_SIZE,FORMAT,ARG1)
	#define	SAFE_SPRINTF_2(BUFFER,BUFFER_SIZE,FORMAT,ARG1,ARG2) sprintf(BUFFER,FORMAT,ARG1,ARG2)
	#define	SAFE_SPRINTF_3(BUFFER,BUFFER_SIZE,FORMAT,ARG1,ARG2,ARG3) sprintf(BUFFER,FORMAT,ARG1,ARG2,ARG3)
	#define	SAFE_SPRINTF_4(BUFFER,BUFFER_SIZE,FORMAT,ARG1,ARG2,ARG3,ARG4) sprintf(BUFFER,FORMAT,ARG1,ARG2,ARG3,ARG4)
	#define	SAFE_SPRINTF_5(BUFFER,BUFFER_SIZE,FORMAT,ARG1,ARG2,ARG3,ARG4,ARG5) sprintf(BUFFER,FORMAT,ARG1,ARG2,ARG3,ARG4,ARG5)
	#define SAFE_SPRINTF_6(BUFFER,BUFFER_SIZE,FORMAT,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) sprintf(BUFFER,FORMAT,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6)
	#define	SAFE_SWPRINTF_1(BUFFER,BUFFER_SIZE,FORMAT,ARG1) swprintf(BUFFER,BUFFER_SIZE,FORMAT,ARG1)
	#define	SAFE_SWPRINTF_2(BUFFER,BUFFER_SIZE,FORMAT,ARG1,ARG2) swprintf(BUFFER,FORMAT,ARG1,ARG2)
	#define	SAFE_SWPRINTF_3(BUFFER,BUFFER_SIZE,FORMAT,ARG1,ARG2,ARG3) swprintf(BUFFER,FORMAT,ARG1,ARG2,ARG3)
	#define	SAFE_SWPRINTF_4(BUFFER,BUFFER_SIZE,FORMAT,ARG1,ARG2,ARG3,ARG4) swprintf(BUFFER,FORMAT,ARG1,ARG2,ARG3,ARG4)
	#define	SAFE_SWPRINTF_5(BUFFER,BUFFER_SIZE,FORMAT,ARG1,ARG2,ARG3,ARG4,ARG5) swprintf(BUFFER,FORMAT,ARG1,ARG2,ARG3,ARG4,ARG5)
	#define SAFE_SWPRINTF_6(BUFFER,BUFFER_SIZE,FORMAT,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) swprintf(BUFFER,FORMAT,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6)
	#define SAFE_LOCAL_TIME(structuredLocalTime,currentTime) structuredLocalTime = *localtime(&currentTime)
	#define SAFE_VSWPRINTF(BUFFER,BUFFER_SIZE,FORMAT,ARGLIST) vswprintf(BUFFER,BUFFER_SIZE,FORMAT,ARGLIST)
	#define SAFE_VSPRINTF(BUFFER,BUFFER_SIZE,FORMAT,ARGLIST) vsprintf(BUFFER,BUFFER_SIZE,FORMAT,ARGLIST)
	#define SAFE_FOPEN(FILESTREAM_P,FILE_PATH,MODE) {FILESTREAM_P = fopen(FILE_PATH),MODE);}
	#define SAFE_SGETN(BUFFER,BUFFER_SIZE,READ_COUNT) sgetn(BUFFER,READ_COUNT)
#endif

