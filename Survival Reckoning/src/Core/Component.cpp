#include "Component.h"

namespace SRMM
{
    template<typename T>
    Ref<T> GameObject::GetComponent() {
        for (auto& component : mComponents) {
            if (auto casted = std::dynamic_pointer_cast<T>(component)) {
                return casted;
            }
        }
        throw std::runtime_error("Component not found");
    }

    Transform::Transform(GameObject& parent)
        : Component(parent), mPosition(0.0f), mRotation(0.0f), mLocalScale(1.0f) {}

    Transform::Transform(GameObject& parent, const glm::vec3& position, const glm::vec3& rotation, const glm::vec3& scale)
        : Component(parent), mPosition(position), mRotation(rotation), mLocalScale(scale) {}

    const glm::vec3& Transform::GetPosition() const { return mPosition; }
    const glm::vec3& Transform::GetRotation() const { return mRotation; }
    const glm::vec3& Transform::GetScale() const { return mLocalScale; }

    void Transform::SetPosition(const glm::vec3& position) {
        glm::vec3 deltaPosition = position - mPosition;
        for (auto& child : mChildren) {
            child.get().SetPosition(child.get().GetPosition() + deltaPosition);
        }
        mPosition = position;
    }

    void Transform::SetRotation(const glm::vec3& rotation) {
        glm::vec3 deltaRotation = rotation - mRotation;
        for (auto& child : mChildren) {
            child.get().SetRotation(child.get().GetRotation() + deltaRotation);
        }
        mRotation = rotation;
    }

    void Transform::SetScale(const glm::vec3& scale) {
        glm::vec3 deltaScale = scale / mLocalScale - glm::vec3(1.0f);
        for (auto& child : mChildren) {
            child.get().SetScale(child.get().GetScale() * (deltaScale + glm::vec3(1.0f)));
        }
        mLocalScale = scale;
    }

    void Transform::SetScale(float scale) {
        SetScale(glm::vec3(scale));
    }

    void Transform::AddChild(Transform& child) {
        mChildren.push_back(child);
    }
}