#ifndef COMPONENT_H
#define COMPONENT_H

#include "TimeSpam.h"
#include "Common.h"
#include <glm/glm.hpp>

namespace SRMM
{
	class Component;

	class GameObject
	{
	public:
		GameObject() = default;

		std::string GetName() { return "Hello Object"; }

		template<typename T>
		Ref<T> GetComponent();

		template<typename T, typename... Args>
		Ref<T> AddComponent(Args&&... args)
		{
			Ref<Component> component = std::make_shared<T>(*this, std::forward<Args>(args)...);
			mComponents.push_back(component);
			return std::static_pointer_cast<T>(component);
		}

	private:
		std::vector<Ref<Component>> mComponents;
	};

	class Component
	{
	public:
		virtual ~Component() = default;
		Component(GameObject& parent) : Parent(parent) {}
		virtual void OnStart() {}
		virtual void OnUpdate(TimeSpam& deltaTime) {}
		
	protected:
		GameObject& Parent;
	};

	class Transform : public Component
	{
	public:
		Transform(GameObject& parent);
		Transform(GameObject& parent, const glm::vec3& position, const glm::vec3& rotation, const glm::vec3& scale);

		const glm::vec3& GetPosition() const;
		const glm::vec3& GetRotation() const;
		const glm::vec3& GetScale() const;

		void SetPosition(const glm::vec3& position);
		void SetRotation(const glm::vec3& rotation);
		void SetScale(const glm::vec3& scale);
		void SetScale(float scale);

		void AddChild(Transform& child);

	private:
		glm::vec3 mPosition;
		glm::vec3 mRotation;
		glm::vec3 mLocalScale;
		std::vector<std::reference_wrapper<Transform>> mChildren;
		Transform* mParent = nullptr;
	};
}

#endif