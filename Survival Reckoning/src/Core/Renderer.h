#ifndef RENDERER_H
#define RENDERER_H

#include "Model.h"
#include "Component.h"

namespace SRMM
{
	class Renderer
	{
	public:
		Renderer() = default;
		virtual ~Renderer() = default;
		virtual void Draw(const MeshFilter& mesh) = 0;
	};

	class MeshRenderer : public Renderer, public Component
	{
	public:
		MeshRenderer(GameObject& parent) : Renderer(), Component(parent) { }
		void Draw(const MeshFilter& mesh) override;
		~MeshRenderer() override = default;
	};
}

#endif