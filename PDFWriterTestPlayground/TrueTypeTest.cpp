/*
   Source File : TrueTypeTest.cpp


   Copyright 2011 Gal Kahana HummusPDFWriter

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
#include "TrueTypeTest.h"
#include "OpenTypeFileInput.h"
#include "InputFile.h"
#include "TestsRunner.h"

#include <iostream>

TrueTypeTest::TrueTypeTest(void)
{
}

TrueTypeTest::~TrueTypeTest(void)
{
}

EPDFStatusCode TrueTypeTest::Run()
{
	EPDFStatusCode status;
	InputFile ttfFile;

	do
	{
		status = ttfFile.OpenFile("C:\\PDFLibTests\\TestMaterials\\fonts\\arial.ttf");
		if(status != ePDFSuccess)
		{
			cout<<"cannot read arial font file\n";
			break;
		}

		OpenTypeFileInput trueTypeReader;

		status = trueTypeReader.ReadOpenTypeFile(ttfFile.GetInputStream());
		if(status != ePDFSuccess)
		{
			cout<<"could not read true type file\n";
			break;
		}
	}while(false);

	return status;
}

ADD_CATEGORIZED_TEST(TrueTypeTest,"TrueType")
