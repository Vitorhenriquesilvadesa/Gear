#ifndef SCRIPTABLE_H
#define SCRIPTABLE_H

#include "Common.h"

namespace SRMM
{
	class ScriptableObject
	{
	public:
		ScriptableObject(const std::string& name) : mName(name) {}
		virtual bool Load(const std::string& path) = 0;
		virtual bool Save(const std::string& assetPath)  { }
		std::string GetName() { return mName; }

	private:
		std::string mName;
	};
}

#endif