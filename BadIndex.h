#pragma once

#include <iostream>
#include <exception>

using namespace std;



class BadIndex : public exception
{
	private:
		const char* _reason;
		int _badindex;
	public:
		BadIndex(int i, const char* r);
		virtual const char* what() const noexcept override;
		void SetReason(const char* r);
		void SetBadIndex(int bi);



};

