#ifndef MODEL_H
#define MODEL_H

#include "Common.h"
#include <glm/glm.hpp>

#include "Component.h"

namespace SRMM
{
	struct Vertex
	{
		glm::vec3 Position;
		glm::vec3 Normal;
		glm::vec2 UV;

		Vertex(const glm::vec3& position, const glm::vec3& normal, const glm::vec2& uv)
			: Position(position), Normal(normal), UV(uv) {}
	};

	struct Mesh
	{
		std::vector<Vertex> Vertices;
		std::vector<uint32_t> Indices;

		Mesh(const std::vector<Vertex>& vertices, const std::vector<uint32_t>& indices)
			: Vertices(vertices), Indices(indices) {}
	};

	class MeshFilter : public Component
	{
	public:
		MeshFilter(GameObject& parent, Mesh mesh) : Component(parent), mMesh(std::move(mesh)) {}

		std::vector<Vertex>& GetVertices() { return mMesh.Vertices; }
		std::vector<uint32_t>& GetIndices() { return mMesh.Indices; }
		Mesh& GetMesh() { return mMesh; }
	private:
		Mesh mMesh;
	};
}

#endif