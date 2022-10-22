#include "pch.h"
#include "CppUnitTest.h"
#include "..\EAMaxis_TimeToBeAlive\EAMaxis_TimeToBeAlive.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EAMaxisUnitTests
{
    const std::string test_path = std::string(__FILE__) + "\\..\\..\\data\\test\\";

    TEST_CLASS(EAMaxisUnitTests)
    {
    public:
        TEST_METHOD(TestFileReadFail) {
            std::string filename = "test/testcase_fake.txt";
            int years[eamaxis::MAX_YEARS] = { 0 };
            Assert::IsFalse(eamaxis::read_file(filename, years));
        }

        TEST_METHOD(TestFileReadSuccess) {
            std::string filename = test_path + "testcase_fileread.txt";
            int years[eamaxis::MAX_YEARS] = { 0 };
            Assert::IsTrue(eamaxis::read_file(filename, years));
        }

        TEST_METHOD(InputTestCase_1) {
            std::string filename = test_path + "testcase_1.txt";

            int years[eamaxis::MAX_YEARS] = { 0 };
            if (eamaxis::read_file(filename, years)) {
                std::vector<int> best_period = eamaxis::best_time_to_be_alive(years);
                Assert::AreEqual(1702, best_period[0]);
                Assert::AreEqual(1719, best_period[1]);
            }
            else Assert::Fail();
        }

        TEST_METHOD(InputTestCase_2) {
            std::string filename = test_path + "testcase_2.txt";
            int years[eamaxis::MAX_YEARS] = { 0 };
            if (eamaxis::read_file(filename, years)) {
                std::vector<int> best_period = eamaxis::best_time_to_be_alive(years);
                Assert::AreEqual(1709, best_period[0]);
                Assert::AreEqual(1710, best_period[1]);
            }
            else Assert::Fail();
        }

        TEST_METHOD(InputTestCase_3) {
            std::string filename = test_path + "testcase_3.txt";
            int years[eamaxis::MAX_YEARS] = { 0 };
            if (eamaxis::read_file(filename, years)) {
                std::vector<int> best_period = eamaxis::best_time_to_be_alive(years);
                Assert::AreEqual(1700, best_period[0]);
                Assert::AreEqual(1721, best_period[1]);
            }
            else Assert::Fail();
        }

        TEST_METHOD(InputTestCase_4) {
            std::string filename = test_path + "testcase_4.txt";
            int years[eamaxis::MAX_YEARS] = { 0 };
            if (eamaxis::read_file(filename, years)) {
                std::vector<int> best_period = eamaxis::best_time_to_be_alive(years);
                Assert::AreEqual(1725, best_period[0]);
                Assert::AreEqual(1727, best_period[1]);
            }
            else Assert::Fail();
        }

        TEST_METHOD(InputTestCase_5) {
            std::string filename = test_path + "testcase_5.txt";
            int years[eamaxis::MAX_YEARS] = { 0 };
            if (eamaxis::read_file(filename, years)) {
                std::vector<int> best_period = eamaxis::best_time_to_be_alive(years);
                Assert::AreEqual(0000, best_period[0]);
                Assert::AreEqual(1993, best_period[1]);
            }
            else Assert::Fail();
        }

        TEST_METHOD(InputTestCase_6) {
            std::string filename = test_path + "testcase_6.txt";
            int years[eamaxis::MAX_YEARS] = { 0 };
            if (eamaxis::read_file(filename, years)) {
                std::vector<int> best_period = eamaxis::best_time_to_be_alive(years);
                Assert::AreEqual(1600, best_period[0]);
                Assert::AreEqual(1600, best_period[1]);
            }
            else Assert::Fail();
        }

        TEST_METHOD(InputTestCase_7) {
            std::string filename = test_path + "testcase_7.txt";
            int years[eamaxis::MAX_YEARS] = { 0 };
            if (eamaxis::read_file(filename, years)) {
                std::vector<int> best_period = eamaxis::best_time_to_be_alive(years);
                Assert::AreEqual(1503, best_period[0]);
                Assert::AreEqual(1505, best_period[1]);
            }
            else Assert::Fail();
        }
    };
}
