#pragma once

#include <exception>
#include <string>
#include <memory>

namespace chainsql
{
	class ChainsqlException : public std::exception
	{
	protected:
		std::string _name_value;
		std::string _error_msg;
	public:
		inline ChainsqlException(){ }
		inline ChainsqlException(const std::string &name_value, const std::string &error_msg)
			: _name_value(name_value), _error_msg(error_msg) {}
		inline ChainsqlException(const ChainsqlException& other) {
			_name_value = other._name_value;
			_error_msg = other._error_msg;
		}
		inline ChainsqlException(const char *msg)
		{
			_error_msg = msg;
		}
		inline ChainsqlException(std::string &msg)
		{
			_error_msg = msg;
		}
		inline ChainsqlException& operator=(const ChainsqlException& other) {
			if (this != &other)
			{
				_error_msg = other._error_msg;
			}
			return *this;
		}
		inline virtual ~ChainsqlException() {}

#ifdef WIN32
		inline virtual const char* what() const
#else
		inline virtual const char* what() const noexcept
#endif 
		{
			return _error_msg.c_str();
		}
		inline std::string name() const
		{
			return _name_value;
		}
		inline virtual std::shared_ptr<chainsql::ChainsqlException> dynamic_copy_exception()const
		{
			return std::make_shared<ChainsqlException>(*this);
		}
		inline virtual void dynamic_rethrow_exception()const
		{
			chainsql::ChainsqlException::dynamic_rethrow_exception();
		}
	};
}
