#pragma once
#include "wbEntity.h"
#include "wbComponent.h"
#include "wbTexture.h"

namespace wb
{
    class TileMapRenderer : public Component
    {
    public:
        TileMapRenderer();
        ~TileMapRenderer();

        void Initialize() override;
        void Update() override;
        void LateUpdate() override;
        void Render(HDC hdc) override;

        void SetTexture(graphics::Texture* texture) { mTexture = texture; }
        void SetSize(math::Vector2 size) { mSize = size; }
    private:
        Vector2 mTileSize;

        graphics::Texture* mTexture;
        math::Vector2 mSize;
        Vector2 mIndex;
    };
}
