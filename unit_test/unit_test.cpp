#include "pch.h"
#include "CppUnitTest.h"
#include "wx/wx.h"
#include "../Calculator/Processor.h"
#include "../Calculator/cMain.h"
#include "../Calculator/buttonFactory.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	buttonFactory* test = new buttonFactory();
	wxWindow* btn_test;
	cMain* cmain;
	wxFrame* frame = new wxFrame();

	TEST_CLASS(UnitTests)
	{
	public:

		TEST_METHOD(AddTestFourAndSeven)
		{
			int answer = Processor::TestOnOperationPlus(4, 7);
			Assert::AreEqual(answer, 11);
		}

		TEST_METHOD(AddTestHundredAndThousand)
		{
			int answer = Processor::TestOnOperationPlus(5000, 100);
			Assert::AreEqual(answer, 5100);
		}

		TEST_METHOD(AddTestMillionAndOne)
		{
			int answer = Processor::TestOnOperationPlus(1000000, 1);
			Assert::AreEqual(answer, 1000001);
		}

		TEST_METHOD(MinusTest5And10)
		{
			int answer = Processor::TestOnOperationMinus(10, 5);
			Assert::AreEqual(answer, 5);
		}

		TEST_METHOD(MinusTest100And70)
		{
			int answer = Processor::TestOnOperationMinus(100, 70);
			Assert::AreEqual(answer, 30);
		}

		TEST_METHOD(MinusTest1000And768)
		{
			int answer = Processor::TestOnOperationMinus(1000, 768);
			Assert::AreEqual(answer, 232);
		}

		TEST_METHOD(TimesTest500And5)
		{
			int answer = Processor::TestonOperationTimes(500, 5);
			Assert::AreEqual(answer, 2500);
		}

		TEST_METHOD(TimesTest5And7)
		{
			int answer = Processor::TestonOperationTimes(5, 7);
			Assert::AreEqual(answer, 35);
		}


		TEST_METHOD(TimesTest10000And40)
		{
			int answer = Processor::TestonOperationTimes(10000, 40);
			Assert::AreEqual(answer, 400000);
		}

		TEST_METHOD(DivTest100And5)
		{
			int answer = Processor::TestonOperationDiv(100, 5);
			Assert::AreEqual(answer, 20);
		}

		TEST_METHOD(DivTest2)
		{
			int answer = Processor::TestonOperationDiv(543,3);
			Assert::AreEqual(answer, 181);
		}

		TEST_METHOD(DivTest3)
		{
			int answer = Processor::TestonOperationDiv(98654,2);
			Assert::AreEqual(answer,49327);
		}

		TEST_METHOD(BINARYTEST) {
			string test = "100100000100001";
			string answer = Processor::TestGetBinary(18465);
			Assert::AreEqual(answer, test);
		}

		TEST_METHOD(BINARYTEST2) {
			string test = "100110100110101";
			string answer = Processor::TestGetBinary(19765);
			Assert::AreEqual(answer, test);
		}

		TEST_METHOD(BINARYTEST3) {
			string test = "100011001001111";
			string answerBin = Processor::TestGetBinary(17999);
			Assert::AreEqual(answerBin, test);
		}

		TEST_METHOD(HEXADECIMALTEST1) {
			string test = "0x41";
			string answer = Processor::TestGetHexadecimal(65);
			Assert::AreEqual(answer, test);
		}

		TEST_METHOD(HEXADECIMALTEST2) {
			string test = "0x64";
			string answer = Processor::TestGetHexadecimal(100);
			Assert::AreEqual(answer, test);
		}

		TEST_METHOD(HEXADECIMALTEST3) {
			string test = "0xF";
			string answer = Processor::TestGetHexadecimal(15);
			Assert::AreEqual(answer, test);
		}

		TEST_METHOD(BUTTONTESTNUM) {
			wxButton* hello = test->get_Five(frame,cmain);
			int test1 = hello->GetId();
			int answer = 5;
			Assert::AreEqual(answer, test1);
		}

		TEST_METHOD(BUTTONTESTOPERATION) {
			wxButton* hello = test->get_Equals(frame, cmain);
			int test2 = hello->GetId();
			int answer = 29;
			Assert::AreEqual(answer, test2);
		}

		TEST_METHOD(BUTTONTESTOPERATION2) {
			wxButton* hello = test->get_AC(frame, cmain);
			int test3 = hello->GetId();
			int answer = 24;
			Assert::AreEqual(answer, test3);
		}
	};
}
