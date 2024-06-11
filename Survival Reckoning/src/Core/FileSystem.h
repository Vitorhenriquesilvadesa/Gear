#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

#include "ApplicationService.h"
#include "Scriptable.h"

namespace SRMM
{
	class AssetRegistry
	{
	public:
		void RegisterAsset(Ref<ScriptableObject> asset);
		void DeleteAsset(const std::string& assetName);
		void ClearAssets();

		template<typename T>
		Ref<T> GetAssetAs(const std::string& assetName);

	private:
		std::map<std::string, Ref<ScriptableObject>> mAssets;
	};

	class FileManagementAPI : public ApplicationService
	{
	public:
		bool Init() override;
		void Update(TimeSpam& deltaTime) override;
		void Shutdown() override;

		template<typename T>
		Ref<T> LoadAsset(const std::string& assetPath)
		{
			if (!std::is_base_of<ScriptableObject, T>())
			{
				throw std::runtime_error("The asset type must be Scriptable Object to load.");
			}

			Ref<ScriptableObject> asset = std::make_shared<T>();
			asset->Load(assetPath);
			return asset;
		}

	
	};
}

#endif