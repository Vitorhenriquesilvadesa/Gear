#include "FileSystem.h"

namespace SRMM
{
	bool FileManagementAPI::Init()
	{
		return false;
	}
	void FileManagementAPI::Update(TimeSpam& deltaTime)
	{
	}
	void FileManagementAPI::Shutdown()
	{
	}

	void AssetRegistry::RegisterAsset(Ref<ScriptableObject> asset)
	{
		if (mAssets.contains(asset->GetName())) return;

		mAssets.insert({ std::move(asset->GetName()), asset });
	}

	void AssetRegistry::DeleteAsset(const std::string& assetName)
	{
		mAssets.erase(assetName);
	}

	void AssetRegistry::ClearAssets()
	{
	}

	template<typename T>
	Ref<T> AssetRegistry::GetAssetAs(const std::string& assetName)
	{
		if (!std::is_base_of<ScriptableObject, T>())
		{
			throw std::runtime_error("The asset type must be Scriptable Object to get.");
		}

		Ref<T> asset = mAssets[assetName];
		return asset;
	}
}