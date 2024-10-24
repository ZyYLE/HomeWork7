#pragma once

#include <iostream>
#include <exception>

using namespace std;



class BadIndex : public exception
{
	private:
		const char* _reason;
	public:
		virtual const char* what() const noexcept override;
		void SetReason(const char* r);


};

