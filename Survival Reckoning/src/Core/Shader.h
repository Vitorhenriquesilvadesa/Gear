#ifndef SHADER_H
#define SHADER_H

#include "Scriptable.h"

namespace SRMM
{
	class Shader : public ScriptableObject
	{
	public:
		Shader(const std::string& name) : ScriptableObject(name) { }
		bool Load(const std::string& path) override;
	};
}

#endif