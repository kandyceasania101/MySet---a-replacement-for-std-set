/*unittest1.cpp*/

//
// Unit tests for mymap data structure.
//
// YOUR NAME
// U. of Illinois, Chicago
// CS 341, Fall 2017
// Project #03
//

#include "stdafx.h"
#include "CppUnitTest.h"

#include "myset.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace MyMapUnitTests
{		
	TEST_CLASS(your_netid_tests)
	{
	public:

    TEST_METHOD(your_netid_test01)
    {
      myset<int>  s;
	  myset<int>  t;

      Assert::IsTrue(s.size() == 0);
	  Assert::IsTrue(t.size() == 0);
      Assert::IsTrue(s.empty());
	  Assert::IsTrue(t.empty());

	  Assert::IsTrue(s.insert(5));
	  //Assert::IsTrue(s.capacity() < 9);
	  t = s;
	  Assert::IsTrue(!s.empty());
	  Assert::IsTrue(!t.empty());
    }

    TEST_METHOD(your_netid_test02)
    {
      myset<int>  s;

      Assert::IsTrue(s.size() == 0);
      Assert::IsTrue(s.empty());

      Assert::IsTrue(s.insert(12));

      Assert::IsTrue(s.size() == 1);
      Assert::IsTrue(!s.empty());
    }

    TEST_METHOD(your_netid_test03)
    {
      myset<string>  s;

      Assert::IsTrue(s.size() == 0);
      Assert::IsTrue(s.empty());

      Assert::IsTrue(s.insert("apple"));

      Assert::IsTrue(s.size() == 1);
      Assert::IsTrue(!s.empty());

      Assert::IsTrue(s["apple"]);
    }
		
    TEST_METHOD(your_netid_test04)
    {
      myset<string>  s;

      Assert::IsTrue(s.size() == 0);
      Assert::IsTrue(s.empty());

      Assert::IsTrue(s.insert("apple"));
      Assert::IsTrue(!s.insert("apple"));  // should not insert again

      Assert::IsTrue(s.size() == 1);
      Assert::IsTrue(!s.empty());

      Assert::IsTrue(s["apple"]);
      Assert::IsTrue(!s["pear"]);  // should not find
    }

	TEST_METHOD(your_netid_test05)
		{
      myset<int>  s;

      Assert::IsTrue(s.size() == 0);
      Assert::IsTrue(s.empty());

      Assert::IsTrue(s.insert(12));
      Assert::IsTrue(s.insert(71));
      s += 20;  // another way to insert:
      Assert::IsTrue(!s.insert(20));  // already inserted:

      Assert::IsTrue(s.size() == 3);
      Assert::IsTrue(!s.empty());

      Assert::IsTrue(s[71]);
      Assert::IsTrue(s[12]);
      Assert::IsTrue(s[20]);
      Assert::IsTrue(!s[11]);
      Assert::IsTrue(!s[999]);;
    }

    TEST_METHOD(your_netid_test06)
    {
      myset<int>  s;

      Assert::IsTrue(s.insert(10));
      Assert::IsTrue(s.insert(20));
      Assert::IsTrue(s.insert(30));

      Assert::IsTrue(s.size() == 3);
      Assert::IsTrue(!s.empty());
	 
      auto iter = s.find(20);
      Assert::IsTrue(iter != s.end());
      Assert::IsTrue(*iter == 20);

      auto iter2 = s.find(40);
      Assert::IsTrue(iter2 == s.end());
    }

    TEST_METHOD(your_netid_test07)
    {
      myset<int>  s;

      Assert::IsTrue(s.insert(12));
      Assert::IsTrue(s.insert(71));
      Assert::IsTrue(s.insert(20));
      Assert::IsTrue(s.insert(2));
      Assert::IsTrue(s.insert(99));

      Assert::IsTrue(s.size() == 5);
      Assert::IsTrue(!s.empty());

      auto iter = s.find(2);

      Assert::IsTrue(iter != s.end());
      Assert::IsTrue(*iter == 2);
      ++iter;
      Assert::IsTrue(iter != s.end());
      Assert::IsTrue(*iter == 12);
      ++iter;
      Assert::IsTrue(iter != s.end());
      Assert::IsTrue(*iter == 20);
      ++iter;
      Assert::IsTrue(iter != s.end());
      Assert::IsTrue(*iter == 71);
      ++iter;
      Assert::IsTrue(iter != s.end());
      Assert::IsTrue(*iter == 99);
      ++iter;
      Assert::IsTrue(iter == s.end());

      auto iter2 = s.find(1);
      Assert::IsTrue(iter2 == s.end());
    }

    TEST_METHOD(your_netid_test08)
    {
      myset<int>  s;

      for (int i = 100; i >= 50; --i)
      {
        Assert::IsTrue(s.insert(i));
      }

      //Assert::IsTrue(s.size() == 901);
     // Assert::IsTrue(!s.empty());

      //int j = 100;
      //auto iter = s.begin();
      //while (iter != s.end())
      //{
      //  Assert::IsTrue(*iter == j);
       // ++iter;
        //++j;
      //}

      //int k = 100;
      //for (auto x : s)
      //{
        //Assert::IsTrue(x == k);
       // ++k;
      ///}
    }

	TEST_METHOD(kburks2_test01)
	{
		myset<int>  s;
		Assert::IsTrue(s.empty());

		for (int i = 1000; i >= 100; --i)
		{
			Assert::IsTrue(s.insert(i));
		}

		Assert::IsTrue(s.size() == 901);
		Assert::IsTrue(!s.empty());

		Assert::IsTrue(!s.insert(1000));

		auto itr = (s.begin());
		Assert::IsTrue(*itr == 100);
		int i = 0;
		while (i < 200) {
			++itr;
			++i;
		}
		Assert::IsTrue(*itr == 300);
		Assert::IsTrue(!s[99]);
		Assert::IsTrue(!s[1]);
		Assert::IsTrue(s[100]);
	}

	TEST_METHOD(kburks2_test02)
	{
		myset<string>  s;

		Assert::IsTrue(s.size() == 0);
		Assert::IsTrue(s.empty());

		Assert::IsTrue(s.insert("fo"));
		Assert::IsTrue(s.insert("foo"));
		Assert::IsTrue(s.insert("fooo"));  // should not insert again

		Assert::IsTrue(s.size() == 3);
		Assert::IsTrue(!s.empty());

		Assert::IsTrue(s["fo"]);
		Assert::IsTrue(s["foo"]);
		Assert::IsTrue(s["fooo"]);  // should not find
	}

	TEST_METHOD(kburks2_test03)
	{
		myset<int>  s;

		Assert::IsTrue(s.size() == 0);
		Assert::IsTrue(s.empty());

		int i = 0,j = 0;

		Assert::IsTrue(s.insert(i));

		while (j < 100) {
		Assert::IsTrue(!s.insert(i));
		j++;
		}

		Assert::IsTrue(!s.insert(0));
		Assert::IsTrue(s.insert(1));
		Assert::IsTrue(s.insert(2));
		Assert::IsTrue(s.insert(3));
		Assert::IsTrue(s.insert(4));

		auto itr = s.find(1);
		Assert::IsTrue(*itr == 1);
		++itr;
		Assert::IsTrue(*itr == 2);

		itr = s.end();
		Assert::IsTrue(*itr != 4);

		Assert::IsTrue(!s.empty());

	}

	TEST_METHOD(kburks_test04) {

		myset<float> s;

		Assert::IsTrue(s.empty());

		Assert::IsTrue(s.insert(12.5));
		Assert::IsTrue(s.insert(71.1));
		Assert::IsTrue(s.insert(20.2));
		Assert::IsTrue(s.insert(2.3));
		Assert::IsTrue(s.insert(99.4));

		Assert::IsTrue(s.size() == 5);
		Assert::IsTrue(!s.empty());

		auto iter = s.find(2.3);

		Assert::IsTrue(iter != s.end());
		++iter;
		Assert::IsTrue(iter != s.end());
		Assert::IsTrue(*iter == 12.5);
		++iter;
		Assert::IsTrue(iter != s.end());
		++iter;
		Assert::IsTrue(iter != s.end());
		++iter;
		Assert::IsTrue(iter != s.end());
		++iter;
		Assert::IsTrue(iter == s.end());

		auto iter2 = s.find(1.0);
		Assert::IsTrue(iter2 == s.end());
		s.clear();
		Assert::IsTrue(s.empty());

	}

	TEST_METHOD(kburks_test05) {

		myset<int> s;

		Assert::IsTrue(s.empty());

		for (int i = 0; i <= 500; ++i)
		{
			Assert::IsTrue(s.insert(i));
		}

		Assert::IsTrue(s.size() == 501);
		Assert::IsTrue(!s.empty());

		int j = 0;
		auto iter = s.begin();
		while (iter != s.end())
		{
			Assert::IsTrue(*iter == j);
			++iter;
			++j;
		}

		int k = 20;
		for (auto x : s)
		{
			Assert::IsTrue(!(x == k));
			++k;
		}

	}

	};
}