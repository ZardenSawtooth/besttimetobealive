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
            Assert::IsFalse(eamaxis::read_dates(filename, years, eamaxis::MAX_YEARS));
        }

        TEST_METHOD(TestFileReadSuccess) {
            std::string filename = test_path + "testcase_fileread.txt";
            int years[eamaxis::MAX_YEARS] = { 0 };
            Assert::IsTrue(eamaxis::read_dates(filename, years, eamaxis::MAX_YEARS));
        }

        TEST_METHOD(InputTestCase_IncorrectFile) {
            std::string filename = test_path + "testcase_fake.txt";

            std::vector<int> best_period = eamaxis::best_time_to_be_alive(filename);
            Assert::AreEqual(0, best_period[0]);
            Assert::AreEqual(0, best_period[1]);
        }

        TEST_METHOD(InputTestCase_OverlappingLifespan) {
            std::string filename = test_path + "testcase_1.txt";

            std::vector<int> best_period = eamaxis::best_time_to_be_alive(filename);
            Assert::AreEqual(1702, best_period[0]);
            Assert::AreEqual(1719, best_period[1]);
        }

        TEST_METHOD(InputTestCase_OverlappingNestedLifespan) {
            std::string filename = test_path + "testcase_2.txt";
            std::vector<int> best_period = eamaxis::best_time_to_be_alive(filename);
            Assert::AreEqual(1709, best_period[0]);
            Assert::AreEqual(1710, best_period[1]);
        }

        TEST_METHOD(InputTestCase_ConsecutiveYearWithNoOverlapLifespan) {
            std::string filename = test_path + "testcase_3.txt";
            std::vector<int> best_period = eamaxis::best_time_to_be_alive(filename);
            Assert::AreEqual(1700, best_period[0]);
            Assert::AreEqual(1721, best_period[1]);
        }

        TEST_METHOD(InputTestCase_NoOverlapLifespan) {
            std::string filename = test_path + "testcase_4.txt";
            std::vector<int> best_period = eamaxis::best_time_to_be_alive(filename);
            Assert::AreEqual(1725, best_period[0]);
            Assert::AreEqual(1727, best_period[1]);
        }

        TEST_METHOD(InputTestCase_MaxRange) {
            std::string filename = test_path + "testcase_5.txt";
            std::vector<int> best_period = eamaxis::best_time_to_be_alive(filename);
            Assert::AreEqual(0000, best_period[0]);
            Assert::AreEqual(1993, best_period[1]);
        }

        TEST_METHOD(InputTestCase_BirthDeathSameYear) {
            std::string filename = test_path + "testcase_6.txt";
            std::vector<int> best_period = eamaxis::best_time_to_be_alive(filename);
            Assert::AreEqual(1600, best_period[0]);
            Assert::AreEqual(1600, best_period[1]);
        }

        TEST_METHOD(InputTestCase_RandomData) {
            std::string filename = test_path + "testcase_7.txt";
            std::vector<int> best_period = eamaxis::best_time_to_be_alive(filename);
            Assert::AreEqual(1503, best_period[0]);
            Assert::AreEqual(1505, best_period[1]);
        }

        TEST_METHOD(InputTestCase_AllAlive) {
            std::string filename = test_path + "testcase_8.txt";
            std::vector<int> best_period = eamaxis::best_time_to_be_alive(filename);
            Assert::AreEqual(1600, best_period[0]);
            Assert::AreEqual(1993, best_period[1]);
        }
    };
}
