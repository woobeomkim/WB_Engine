#pragma once
#include "wbEntity.h"

namespace wb
{
	class Resource : public Entity
	{
	public:
		Resource(const enums::eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0;
		
		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }
	private:
		const enums::eResourceType mType;
		std::wstring mPath;
	};
}
